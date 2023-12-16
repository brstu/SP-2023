import threading
import time
import queue
import secrets  

class Waiter(threading.Thread):
    def __init__(self, name, orders_queue, orders_list, flag):
        super().__init__()
        self.name = name
        self.orders_queue = orders_queue
        self.orders_list = orders_list
        self.flag = flag

    def run(self):
        while not self.flag.is_set():
            if self.orders_list:
                order = self.orders_list.pop(0)
                print(f'{self.name} принял заказ на {order}')
                self.orders_queue.put(order)
                time.sleep(secrets.randbelow(3) + 1)  
            else:
                self.flag.set()
                print(f'{self.name} закончил принимать заказы')

class Chef(threading.Thread):
    def __init__(self, name, orders_queue, flag):
        super().__init__()
        self.name = name
        self.orders_queue = orders_queue
        self.flag = flag

    def run(self):
        while not self.flag.is_set() or not self.orders_queue.empty():
            if not self.orders_queue.empty():
                order = self.orders_queue.get()
                print(f'{self.name} начал готовить {order}')
                time.sleep(secrets.randbelow(4) + 2)  
                print(f'{self.name} закончил готовить {order}')
            else:
                if not self.flag.is_set():
                    print(f'{self.name} ждет заказов')


if __name__ == "__main__":
    orders_queue = queue.Queue()
    orders_list = ['Pizza', 'Burger', 'Salad'] 
    flag = threading.Event()

    waiter1 = Waiter('Официант 1', orders_queue, orders_list, flag)
    waiter2 = Waiter('Официант 2', orders_queue, orders_list, flag)
    waiter3 = Waiter('Официант 3', orders_queue, orders_list, flag)
    chef = Chef('Повар', orders_queue, flag)

    waiter1.start()
    waiter2.start()
    waiter3.start()
    chef.start()

    waiter1.join()
    waiter2.join()
    waiter3.join()
    chef.join()

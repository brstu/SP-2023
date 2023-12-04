import threading
import time
import queue
import random

orders_list = [{'salad': 3,
                'pizza': 4,
                'burger': 3,
                'chicken': 5}]

orders_queue = queue.Queue()
flag = threading.Event()
lock = threading.Lock()

def waiters():
    waiter_list = ['Официант1', 'Официант2', 'Официант3']
    idx = 0
    while not flag.is_set():
        with lock:
            if orders_list:
                order = orders_list.pop(0)
                for dish, cook_time in order.items():
                    waiter = waiter_list[idx % len(waiter_list)]
                    print(f'{waiter} принял заказ на {dish}')
                    orders_queue.put((dish, cook_time))
                    time.sleep(random.randint(1, 3))
                    idx += 1
            else:
                flag.set()
                print('Официанты закончили принимать заказы')

def cooker():
    while not flag.is_set() or not orders_queue.empty():
        if not orders_queue.empty():
            dish, cook_time = orders_queue.get()
            print(f'Повар начал готовить {dish}')
            time.sleep(cook_time)
            print(f'Повар закончил готовить {dish}')
        else:
            if not flag.is_set():
                print('Повар ждет заказов')
                break

waiter_thread = threading.Thread(target=waiters)
cooker_thread = threading.Thread(target=cooker)

waiter_thread.start()
cooker_thread.start()

waiter_thread.join()
cooker_thread.join()

print("Ресторан закрыт")

import threading

# Создаем мьютекс
mutex = threading.Lock()

# Функция, которая будет выполняться в потоках
def worker():
    # Захватываем мьютекс
    mutex.acquire()
    try:
        first = input('Введите первую строку: ')
        second = input('Введите вторую строку: ')
        print(first + second)
    finally:
        # Освобождаем мьютекс
        mutex.release()
# Создаем и запускаем потоки
thread1 = threading.Thread(target=worker)
thread2 = threading.Thread(target=worker)
thread1.start()
thread2.start()
thread1.join()
thread2.join()
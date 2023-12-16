# Лабораторная работа №5

## Многопоточность.

### Цель работы

Научиться работать с многопоточностью в приложениях.

Необходимо написать 2 программы, используя в них несколько потоков. 
Одну из программ реализовать через атомные переменные, вторую – через mutex. 
Отчёт должен содержать цель работы, код программы, скриншот работы программы и вывод по лабораторной работе.


### Варианты заданий
Создать два потока, записывающих две введённых с клавиатуры строки в одну общую. 


Пример использования mutex:

```Python
mutex = threading.Lock()
```
Создаем мьютекс.


```Python
def worker():
    mutex.acquire()
    try:
        first = input('Введите первую строку: ')
        second = input('Введите вторую строку: ')
        print(first + second)
    finally:
        mutex.release()
```
Функция, которая будет выполняться в потоках.


```Python
thread1 = threading.Thread(target=worker)
thread2 = threading.Thread(target=worker)
thread1.start()
thread2.start()
thread1.join()
thread2.join()
```
Создаем и запускаем потоки.



Пример атомной переменной:

```Python
input_string_1 = ""
input_string_2 = ""

def write_string_1():
    global input_string_1
    input_string_1 = input("Введите первую строку: \n")

def write_string_2():
    global input_string_2
    input_string_2 = input("Введите вторую строку: ")
```
Функции для ввода строк.


```Python
thread1 = threading.Thread(target=write_string_1)
thread1.start()

thread2 = threading.Thread(target=write_string_2)
thread2.start()

#Ожидаем завершения обоих потоков
thread1.join()
thread2.join()
```
Создаем и запускаем потоки.


```Python
combined_string = input_string_1 + input_string_2
print("Объединенная строка: ", combined_string)
```
Объединяем и выводим объединенную строку.
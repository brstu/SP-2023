import threading

input_string_1 = ""
input_string_2 = ""

def write_string_1():
    global input_string_1
    input_string_1 = input("Введите первую строку: \n")

def write_string_2():
    global input_string_2
    input_string_2 = input("Введите вторую строку: ")

# Создаем и запускаем первый поток
thread1 = threading.Thread(target=write_string_1)
thread1.start()

# Создаем и запускаем второй поток
thread2 = threading.Thread(target=write_string_2)
thread2.start()

# Ожидаем завершения обоих потоков
thread1.join()
thread2.join()

# Объединяем строки
combined_string = input_string_1 + input_string_2

# Выводим объединенную строку
print("Объединенная строка: ", combined_string)
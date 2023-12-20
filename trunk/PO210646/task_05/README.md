# Лабораторная работа №5 #

## Тема ##

Многопоточность

## Цель работы ##

Научиться работать с многопоточностью в приложениях.


## Вариант 3 ##

## Реализация/ход работы ##

### Условие ###

Создать три потока, выполняющих различные арифметические операции над переменной типа ***float***.



Через mutex:

```c++
Операция увеличения

std::thread t1([&]() {
    for (int i = 0; i < times; ++i) {
        mtx.lock();
        num += inc;
        mtx.unlock();
    }
    });
	
Операция уменьшения
std::thread t2([&]() {
    for (int i = 0; i < times; ++i) {
        mtx.lock();
        num -= dec;
        mtx.unlock();
    }
    });
	
Операция умножения
std::thread t3([&]() {
    for (int i = 0; i < times; ++i) {
        mtx.lock();
        num *= mult;
        mtx.unlock();
    }
    });

```

Через atomic:

```c++

Инкрементирование (увеличение данных)

std::thread t4([&]() {
    for (int i = 0; i < times; ++i) {
        counter.fetch_add(inc1, std::memory_order_relaxed);
    }
    });



Дерементирование (уменьшение данных)

std::thread t5([&]() {
    for (int i = 0; i < times; ++i) {
        counter.fetch_sub(dec1, std::memory_order_relaxed);
    }
    });


Умножение данных

std::thread t6([&]() {
    for (int i = 0; i < times; ++i) {
        mult1 = counter.load() * mult1;
        counter.store(counter);
    }
    });

```


#### Результат работы программы ####

Mutex
![image_1.png](images/images_1.png)

Atomic
![image_2.png](images/images_2.png)

#### Вывод ####

Научились работать с многопоточностью в приложениях.


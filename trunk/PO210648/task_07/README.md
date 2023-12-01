# Лабораторная работа №7 Синхронизация потоков #

## Цель работы: Научиться синхронизировать работу с потоками в приложениях. ##

### Задание ###

***Создать симулятор рынка с минимум 3 торговцами. Торговцы обслуживают по одному человеку в очереди, а после того, как очередь закончилась – начинаю обслуживать людей в очередях других торговцев.***


1. Создание 3 потоков. 

``` c++
    traders.emplace_back(&Trader::startService, &trader1, 1);
    traders.emplace_back(&Trader::startService, &trader2, 2);
    traders.emplace_back(&Trader::startService, &trader3, 3);
```

2. Распределение клиентов между торговцами.
```c++
    for (int i = 1; i <= 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Имитировать время прибытия клиента
        int traderId = (i % 3) + 1; // Распределяйте клиентов между трейдерами по циклической схеме
        switch (traderId) {
            case 1:
                trader1.addToQueue(i);
                break;
            case 2:
                trader2.addToQueue(i);
                break;
            case 3:
                trader3.addToQueue(i);
                break;
        }
    }
```

3. Результат:

![result.png](images/result.png)

### Вывод ###

*** Научился синхронизировать работу с потоками в приложениях. ***

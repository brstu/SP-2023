# Лабораторная работа №4 Наследование #

## Цель работы: Научиться создавать простейшие классы-наследники ##

### Задание ###

***Для выполнения лабораторной работы необходимо создать класс Window. В классе должны быть следующие поля: id (int), height (int), width (int), memoryNeeded(int), areAdministatorRightsGranted (boolean) и isShown(boolean).   Требуется реализовать конструктор, задающий id и принимающий параметры height, width и areAdministatorRightsGranted, метод doWork, в котором будет изменяться значение memoryNeeded и метод showOrHide, меняющий значение переменной isShown.Затем необходимо создать класс-наследник класса Window по варианту, реализующий имитацию заданной функциональности.Работу выполнять на языке C++.***

***Создать класс DesktopWindow. В данном классе добавляются поля shortcuts (массив/список ярлыков) и backgroundImagePath. Ярлык реализовать отдельным классом. У ярлыка должен быть id, size, xPosition, yPosition и path. Реализовать методы для перемещения ярлыка и запуска. doWork вызывается только при создании объекта класса и при перемещении ярлыка. MemoryNeeded принимать как неизменяемое значение, зависящее от количества ярлыков. В основной программе реализовать функцию, создающую новый экран и функцию, меняющий активный экран.***

1. Создание класса Window. 

- ![1.png](images/1.png)

2. Создание класса Shortcuts.

- ![2.png](images/2.png)

3. Наследование:

- ![3.png](images/3.png)

### Вывод ###

*** Научился создавать простейшие классы-наследники. ***
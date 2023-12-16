# Лабораторная работа №4 #

## Наследование ##

## Вариант 2 ##

## Реализация/ход работы ##

Создали класс ***GameWindow***:

```c++
//..
class GameWindow : public Window {
public:
    GameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);
    virtual void doAction() = 0;

protected:
    Settings* settings;
};
```

Реализовали 2 класса-наследника (***RockPaperScissorsGameWindow*** и ***GuessNumberGameWindow***) 
от класса ***GameWindow***:

```c++
\\..
class RockPaperScissorsGameWindow : public GameWindow {
public:
	RockPaperScissorsGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);
	void doAction() override;
	int calculateMemoryNeeded();
};
```

```c++
\\..
class GuessNumberGameWindow : public GameWindow {
public:
    GuessNumberGameWindow(int id, int height, int width, bool areAdministratorRightsGranted, Settings* settings);
    void doAction() override;
    int calculateMemoryNeeded();

private:
    int targetNumber;
};
```

#### Результат работы программы ####

Вывод меню для выбора игры "Камень-ножницы-бумага":

![img.png](images/img.png)

Вывод меню для выбора игры "Угадай число":

![img_1.png](images/img_1.png)

![img_2.png](images/img_2.png)

#### Вывод ####

Научились создавать простейшие классы-наследники.

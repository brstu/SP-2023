# Лабораторная работа №4

## Наследование

### Цель работы

Научиться создавать простейшие классы-наследники.

Для выполнения лабораторной работы необходимо создать класс Window. 
В классе должны быть следующие поля: id (int), height (int), width (int), 
memoryNeeded (int), areAdministatorRightsGranted (boolean) и isShown(boolean). 
Требуется реализовать конструктор, задающий id и принимающий параметры height, 
width и areAdministatorRightsGranted, метод doWork, в котором будет изменяться 
значение memoryNeeded и метод showOrHide, меняющий значение переменной isShown.
Затем необходимо создать класс-наследник класса Window по варианту, реализующий имитацию заданной функциональности.


### Варианты заданий
Создать класс GameWindow. В данном классе добавляется поле settings. Settings реализовать отдельным классом с минимум 5 полями настроек. В классе должен быть абстрактный метод doAction. Реализовать 3 различных класса-наследника от класса GameWindow (например, RockPaperScissorsGameWindow) и столько же классов-наследников Settings (свой для каждого класса, который передаётся ему в конструкторе). Переопределить в каждом классе-наследнике doAction с вызовом doWork (высчитывать необходимый memoryNeeded исходя из настроек и самого doAction). В основной программе реализовать функцию запуска всех 3 наследников GameWindow.  



```Python
class Window:
    def __init__(self, id, height, width, areAdministatorRightsGranted):
        self.id = id
        self.height = height
        self.width = width
        self.memoryNeeded = 0
        self.areAdministatorRightsGranted = areAdministatorRightsGranted
        self.isShown = False

    def doWork(self):
        self.memoryNeeded += 1

    def showOrHide(self):
        self.isShown = not self.isShown
```
Создания класса: 


```Python
    class GameWindow(Window, ABC):
    def __init__(self, id, height, width, areAdministatorRightsGranted, settings):
        super().__init__(id, height, width, areAdministatorRightsGranted)
        self.settings = settings

    @abstractmethod
    def doAction(self):
        pass
```
Класс, содержащий абстрактный метод doAction:


```Python
     class RockPaperScissorsGameWindow(GameWindow):
    def __init__(self, id, height, width, areAdministatorRightsGranted, settings):
        super().__init__(id, height, width, areAdministatorRightsGranted, settings)

    def doAction(self):
        self.doWork()
        print("RockPaperScissorsGameWindow doAction")

class TicTacToeGameWindow(GameWindow):
    def __init__(self, id, height, width, areAdministatorRightsGranted, settings):
        super().__init__(id, height, width, areAdministatorRightsGranted, settings)

    def doAction(self):
        self.doWork()
        print("TicTacToeGameWindow doAction")

class SnakeGameWindow(GameWindow):
    def __init__(self, id, height, width, areAdministatorRightsGranted, settings):
        super().__init__(id, height, width, areAdministatorRightsGranted, settings)

    def doAction(self):
        self.doWork()
        print("SnakeGameWindow doAction")
```
Классы, которые наследуют функции из класса GameWindow.


```Python
    settings1 = Settings("Setting1", "Setting2", "Setting3", "Setting4", "Setting5")
    settings2 = Settings("SettingA", "SettingB", "SettingC", "SettingD", "SettingE")
    settings3 = Settings("SettingX", "SettingY", "SettingZ", "SettingW", "SettingV")

    gameWindow1 = RockPaperScissorsGameWindow(1, 800, 600, True, settings1)
    gameWindow2 = TicTacToeGameWindow(2, 800, 600, True, settings2)
    gameWindow3 = SnakeGameWindow(3, 800, 600, True, settings3)
```
Экземпляры класса Settings для каждого окна и экземпляры классов-наследников GameWindow.

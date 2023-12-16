from abc import ABC, abstractmethod

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

class Settings:
    def __init__(self, setting1, setting2, setting3, setting4, setting5):
        self.setting1 = setting1
        self.setting2 = setting2
        self.setting3 = setting3
        self.setting4 = setting4
        self.setting5 = setting5

class GameWindow(Window, ABC):
    def __init__(self, id, height, width, areAdministatorRightsGranted, settings):
        super().__init__(id, height, width, areAdministatorRightsGranted)
        self.settings = settings

    @abstractmethod
    def doAction(self):
        pass

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

def launchAllWindows():
    # Создаем экземпляры класса Settings для каждого окна
    settings1 = Settings("Setting1", "Setting2", "Setting3", "Setting4", "Setting5")
    settings2 = Settings("SettingA", "SettingB", "SettingC", "SettingD", "SettingE")
    settings3 = Settings("SettingX", "SettingY", "SettingZ", "SettingW", "SettingV")

    # Создаем экземпляры классов-наследников GameWindow
    gameWindow1 = RockPaperScissorsGameWindow(1, 800, 600, True, settings1)
    gameWindow2 = TicTacToeGameWindow(2, 800, 600, True, settings2)
    gameWindow3 = SnakeGameWindow(3, 800, 600, True, settings3)

    # Создаем список окон
    windows = [gameWindow1, gameWindow2, gameWindow3]

    # Запускаем метод doAction для каждого окна
    for window in windows:
        window.doAction()

# Пример использования
launchAllWindows()
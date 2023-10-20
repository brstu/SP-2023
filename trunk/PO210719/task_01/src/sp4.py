class Shortcut:
    def __init__(self, shortcut_id, size, x_position, y_position, path):
        self.id = shortcut_id
        self.size = size
        self.x_position = x_position
        self.y_position = y_position
        self.path = path

    def move(self, new_x, new_y):
        self.x_position = new_x
        self.y_position = new_y
        self.do_work()

    def launch(self):
        print("Launching shortcut:", self.path)

    def do_work(self):
        print("Working on shortcut:", self.id)

class DesktopWindow:
    def __init__(self):
        self.shortcuts = []
        self.background_image_path = ""
        self.memory_needed = 0

    def add_shortcut(self, shortcut):
        self.shortcuts.append(shortcut)
        self.memory_needed += shortcut.size

    def change_background_image(self, image_path):
        self.background_image_path = image_path

    def move_shortcut(self, shortcut_id, new_x, new_y):
        for shortcut in self.shortcuts:
            if shortcut.id == shortcut_id:
                shortcut.move(new_x, new_y)
                break

    def launch_shortcut(self, shortcut_id):
        for shortcut in self.shortcuts:
            if shortcut.id == shortcut_id:
                shortcut.launch()
                break

# Creating a new desktop window
desktop = DesktopWindow()

# Creating and adding shortcuts
shortcut1 = Shortcut(1, 10, 100, 50, "C:/Users/Admin/Desktop")
shortcut2 = Shortcut(2, 8, 200, 100, "D:/PyCharm/Python310/Projects/SP")
desktop.add_shortcut(shortcut1)
desktop.add_shortcut(shortcut2)

# Changing the background image
desktop.change_background_image("D:/PyCharm/Python310/Projects/GiMS/images/Ducky.bmp")

# Moving a shortcut
desktop.move_shortcut(1, 150, 80)

# Launching a shortcut
desktop.launch_shortcut(2)
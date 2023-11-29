import os


def console_menu():
    print("===== Menu ====")
    print("1. Move File")
    print("2. Print Dirs")
    print("3. Create")
    print("4. Remove File/Folder")
    print("0. Exit")
    print("==========================")
    choice = input("Enter your choice: ")
    return choice

def move_file():
    current_name = input('Enter the path to file: ')
    new_name = input('Enter the new path to file: ')
    os.replace(current_name, new_name)

def print_dirs():
    path = input('Enter the path: ')
    for dirpath, dirnames, filenames in os.walk(path):
        for dirname in dirnames:
            print('Каталог: ', os.path.join(dirpath, dirname))
        for filename in filenames:
            print('Файл: ', os.path.join(dirpath, filename))

def create():
    def create_folder():
        create = input('Enter the folder name: ')
        if not os.path.isdir(create):
            os.mkdir(create)
        else:
            print('Folder already exists!')

    def create_folder_tree():
        create = input('Enter the folder tree: ')
        os.makedirs(create)

    def create_file():
        create = input('Enter the file name: ')
        write = input('Enter the content for the file: ')
        with open(create + '.txt', 'w') as file:
            file.write(write)

    def create_menu():
        print("===== Create ====")
        print("1. Create Folder")
        print("2. Create Folder Tree")
        print("3. Create File")
        print("0. Exit")
        print("==========================")
        choice = input("Enter your choice: ")
        return choice

    def main():
        while True:
            choice = create_menu()
            if choice == "0":
                break
            elif choice == "1":
                create_folder()
            elif choice == "2":
                create_folder_tree()
            elif choice == '3':
                create_file()
            else:
                print("Invalid choice. Please try again.")

    if __name__ == '__main__':
        main()

def remove_folder_file():
    def remove_folder():
        folder_path = input('Path to folder: ')
        os.rmdir(folder_path)

    def remove_file():
        file_path = input('Path to file: ')
        os.remove(file_path)

    def remove_menu():
        print("===== Delete ====")
        print("1. Remove Folder")
        print("2. Remove File")
        print("0. Exit")
        print("==========================")
        choice = input("Enter your choice: ")
        return choice

    def main():
        while True:
            choice = remove_menu()
            if choice == "0":
                break
            elif choice == "1":
                remove_folder()
            elif choice == "2":
                remove_file()
            else:
                print("Invalid choice. Please try again.")

    if __name__ == '__main__':
        main()

def main():
    while True:
        choice = console_menu()
        if choice == "0":
            break
        elif choice == "1":
            move_file()
        elif choice == "2":
            print_dirs()
        elif choice == '3':
            create()
        elif choice == '4':
            remove_folder_file()
        else:
            print("Invalid choice. Please try again.")

if __name__ == '__main__':
    main()

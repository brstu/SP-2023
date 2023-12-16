import tkinter as tk
from tkinter import messagebox

def show_message():
    text = entry.get()
    messagebox.showinfo('Введенный текст', text)

window = tk.Tk()
window.title('Приложение')
window.geometry('400x400+100+100')
window.resizable(False, False)
screen_width = window.winfo_screenwidth()
screen_height = window.winfo_screenheight()
x = int((screen_width/2) - (400/2))
y = int((screen_height/2) - (400/2))
window.geometry(f"400x400+{x}+{y}")

entry = tk.Entry(window)
entry.pack(pady=20)

button = tk.Button(window, text='Показать текст', command=show_message)
button.pack()

window.mainloop()
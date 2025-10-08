import os
import tkinter as tk
from tkinter import messagebox

def gui_available():
    # Перевіряємо базову змінну оточення
    if "DISPLAY" in os.environ or "WAYLAND_DISPLAY" in os.environ:
        return True
    return False

def show_warning_if_gui():
    if gui_available():
        try:
            root = tk.Tk()
            root.withdraw()  # сховати головне вікно
            messagebox.showwarning("WARNING", "Timer end!")
            root.destroy()
        except Exception as e:
            pass

# Виклик:
show_warning_if_gui()


from tkinter import *
from tkinter import messagebox


def click():
    messagebox.showinfo(title='Hello World',
                        message="Halo! Perkenalkan nama saya:  Hafizh Alexander. NIM = 23051204149")


window = Tk()  # instance an instance of a window
window.geometry("240x160")
window.title("HelloWorld")


icon = PhotoImage(file='ATLUS INFO ID LOGO - Copy-1.png')
window.iconphoto(True, icon)
window.config(background="#eeeeee")

button = Button(window,
                text="Hello World",
                command=click,
                font=("Times New Roman", 14),
                fg="black")
button.pack()

window.mainloop()


# label = Label(window,
#               text="Hello World",
#               font=('Arial',40,'bold'),
#               fg='green', bg='black',
#               relief=RAISED,
#               bd=10,
#               padx=20, pady=20)
# label.pack()
# #label.place(x=240,y=180)

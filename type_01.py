import os
import random
import string
import time
import shutil


def clear_screen():
    if os.name == "nt":
        _ = os.system('cls')
    else:
        _ = os.system('clear')


clear_screen()

print("Vital Message"
      "\n")

while True:
    D = int(input('How Difficult?'))
    if D >= 4 and D <= 10:
        break

M = ''

for i in range(D):
    M += random.choice(string.ascii_uppercase)

clear_screen()

print('SEND MESSAGE: '
      '\n'
      '\n', M)

time.sleep(0.5*D)

clear_screen()

N = input('')

if N == M:
    print("Message Correct"
          "\n The war is over")
else:
    print("salah goblok"
          "\n" 'harus e kamu ketik: '
          "\n", M)

import sys
import numpy as np
import random
from collections import OrderedDict

# Reading input for how many test cases wanted.
print("Write input a number of values for test case (between 1 and 52, max number of cards in a deck)")
cases = int(input())

# Checking for valid input
if (cases < 1) or (cases > 52):
    print("Invalid input. Terminating program.")
    sys.exit()

# Creating .txt files
aGen = open('txtFiles/aGen.txt', 'w')
bGen = open('txtFiles/bGen.txt', 'w')

# Setting all values to 1
a_vals = np.ones((4, 13))
b_vals = np.ones((4, 13))

# Setting other values to -1, rest of values are left as 1.
for i in range (52-cases):
    x = random.randint(0, 3)
    y = random.randint(0, 12)

    while(a_vals[x][y] != 1):
        x = random.randint(0, 3)
        y = random.randint(0, 12)

    a_vals[x][y] = -1

for i in range (52-cases):
    x = random.randint(0, 3)
    y = random.randint(0, 12)

    while(b_vals[x][y] != 1):
        x = random.randint(0, 3)
        y = random.randint(0, 12)

    b_vals[x][y] = -1


a_true = np.argwhere(a_vals == 1)
b_true = np.argwhere(b_vals == 1)

np.random.shuffle(a_true)
np.random.shuffle(b_true)

for idx in a_true:
    # Inserting suit
    if idx[0] == 0:
        aGen.write('h ')
    if idx[0] == 1:
        aGen.write('s ')
    if idx[0] == 2:
        aGen.write('d ')
    if idx[0] == 3:
        aGen.write('c ')

    # Inserting number
    if idx[1] == 0:
        aGen.write('a')
    if idx[1] >= 1 and idx[1] <= 10:
        aGen.write(str(idx[1]))
    if idx[1] == 11:
        aGen.write('j')
    if idx[1] == 12:
        aGen.write('q')
    if idx[1] == 13:
        aGen.write('k')

    aGen.write('\n')

for idx in b_true:
    if idx[0] == 0:
        bGen.write('h ')
    if idx[0] == 1:
        bGen.write('s ')
    if idx[0] == 2:
        bGen.write('d ')
    if idx[0] == 3:
        bGen.write('c ')

    if idx[1] == 0:
        bGen.write('a')
    if idx[1] >= 1 and idx[1] <= 10:
        bGen.write(str(idx[1]))
    if idx[1] == 11:
        bGen.write('j')
    if idx[1] == 12:
        bGen.write('q')
    if idx[1] == 13:
        bGen.write('k')

    bGen.write('\n')

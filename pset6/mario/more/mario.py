from cs50 import get_int

h = 0
while not int(h) in range(1,9):
    h = get_int("Height:")

j = 0
for i in range (h):
    h -= 1
    j += 1
    print(" " * h + "#" * j + "  " + "#" * j)
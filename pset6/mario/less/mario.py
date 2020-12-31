from cs50 import get_int

h = 0
while not int(h) in range(1,9):
    h = get_int("Height:")

w = h
j = 0
for i in range (h):
    w -= 1
    j += 1
    print(" " * w, end = "")
    print("#" * j, end = "")
    print("")
from cs50 import get_string

card = get_string("Number: ")
sum = 0
i = 0
lenght = int(len(card))
len = lenght - 1

while True:
    lenght -= 2
    if lenght < 0:
        break
    if int(card[lenght]) * 2 > 9:
        sum += (int(card[lenght]) * 2) % 10 + 1
    else:
        sum += int(card[lenght]) * 2
    i += 1

while True:
    if len < 0:
        break
    sum += int(card[len])
    len -= 2
    i += 1

if sum % 10 == 0 and i == 15 and card[0] == '3' and (card[1] == '7' or card[1] == '4'):
    print("AMEX")
elif sum % 10 == 0 and i == 16 and card[0] == '5' and (card[1] == '1' or card[1] == '2' or card[1] == '3' or card[1] == '4' or card[1] == '5'):
    print("MASTERCARD")
elif sum % 10 == 0 and (i == 13 or i == 16) and card[0] == '4':
    print('VISA')
else:
    print('INVALID')

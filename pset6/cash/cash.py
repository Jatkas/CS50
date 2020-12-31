from cs50 import get_float

while True:
    cash = get_float("Change owed: ")
    if cash > 0:
        break

cents = round(cash * 100)
coins = int(cents / 25)
coins = coins + int((cents % 25)/10)
coins = coins + int(((cents % 25)%10)/5)
coins = coins + int((((cents % 25)%10)%5)/1)
print(coins)
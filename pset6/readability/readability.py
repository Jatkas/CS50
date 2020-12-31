from cs50 import get_string

text = get_string("Paste text here: ")
sent = 0
words = 0
letters = 0

for i in range(len(text)):
    if text[i] == ' ':
        words += 1
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        sent += 1
    if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
        letters += 1
words += 1

L = letters / words * 100
S = sent / words * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index > 15:
    print('Grade 16+')
elif index < 2:
    print('Before Grade 1')
else:
    print('Grade: ', index)
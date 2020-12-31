import sys
from cs50 import SQL
db = SQL("sqlite:///students.db")

if len(sys.argv) == 2:
    house = sys.argv[1]
else:
    sys.exit("Usage: python roster.py 'House'")

rows = db.execute('SELECT * FROM students WHERE house = ? ORDER BY last, first;', house)

for row in rows:
    if row['middle'] == None:
        print(row['first'] + ' ' + row['last'] + ', born ' + str(row['birth']))
    else:
        print(row['first'] + ' ' + row['middle'] + ' ' + row['last'] + ', born ' + str(row['birth']))
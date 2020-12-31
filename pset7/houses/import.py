import sys
from cs50 import SQL
import csv
db = SQL("sqlite:///students.db")

if len(sys.argv) == 2:
    characters = sys.argv[1]
else:
    sys.exit("Usage: python import.py characters.csv")

with open(characters, "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Iterate over CSV file
    for row in reader:

        name = row['name'].split()

        if len(name) == 3:
            first = name[0]
            middle= name[1]
            last =name[2]
        elif len(name) == 2:
            first = name[0]
            middle= None
            last =name[1]

        house = row['house']
        birth = row['birth']

        # Insert names
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)
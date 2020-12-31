import sys

if len(sys.argv) == 3:
    sequence = sys.argv[2]
    database = sys.argv[1]
else:
    sys.exit("Usage: python dna.py data.csv sequence.txt")

csv_file = open(database, 'r')

strands = []
persons = {}
for index, row in enumerate(csv_file):
    if index == 0:
        strands = [strand for strand in row.strip().split(',')][1:]
    else:
        current_row = row.strip().split(',')
        persons[current_row[0]] = [int(x) for x in current_row[1:]]

dna_strand = open(sequence, 'r').read()

final_strands = []
for strand in strands:
    current_max = 0
    i = 0
    max_strand = 0
    while i < len(dna_strand):
        current_window = dna_strand[i:i + len(strand)]
        if current_window == strand:
            current_max += 1
            max_strand = max(max_strand, current_max)
            i += len(strand)
        else:
            current_max = 0
            i += 1
    final_strands.append(max_strand)
    
for name,data in persons.items():
    if data == final_strands:
        sys.exit(name)
sys.exit('No match')
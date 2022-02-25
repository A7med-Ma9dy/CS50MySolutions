import sys
import csv

# using csv dictionary reader

def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    database = open(sys.argv[1])
    data = csv.DictReader(database)
    with open(sys.argv[2])as file:
        seq = file.read()

    count = {}
    # fields = data.fieldnames
    # print(fields)
    for sub in data.fieldnames[1:]:
        count[sub] = longest_match(seq, sub)
    # print(count)

    # print person name if strs count match
    for row in data:
        # print(row)
        # print([row[sub] for sub in count])
        if all(count[sub] == int(row[sub]) for sub in count):
            print(row["name"])
            database.close()
            return
    print("No match")
    database.close()


def longest_match(seq, sub):
    longest = 0
    length = len(sub)
    for i in range(len(seq)):
        count = 0
        while True:
            start = i + length * count
            end = start + length
            if seq[start:end] == sub:
                count += 1
            else:
                break
        longest = max(longest, count)
    return longest


main()

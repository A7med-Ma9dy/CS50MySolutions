from sys import argv, exit
import csv


def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    csvpath = argv[1]
    with open(csvpath) as csvfile:
        reader = csv.reader(csvfile)
        # for line in reader:
        #     print (line)
        strs = next(reader)[1:]
        # print(strs)
        # for line in reader:
        #    print (line)
        txtpath = argv[2]
        with open(txtpath) as txtfile:
            s = txtfile.read()
        # print(s)
            strCount = [maxcount(s, seq) for seq in strs]
        # print (strCount)
        printmatch(reader, strCount)

# func to count max successive counts of strs


def maxcount(s, sub):
    count = [0] * len(s)
    # start from end of text s
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            # basecase
            if i + len(sub) > len(s) - 1:
                count[i] = 1
            else:
                count[i] = 1 + count[i + len(sub)]
    return max(count)


def printmatch(reader, count):
    for line in reader:
        # print(line)
        person = line[0]
        # print(person)
        value = [int(val) for val in line[1:]]
        # print(value)
        if value == count:
            print(person)
            return
    print("No match")


if __name__ == "__main__":
    main()
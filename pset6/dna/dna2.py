from sys import argv

# no csv.reader

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

csvfile = open(argv[1], 'r')
dictionary = {}

for count, row in enumerate(csvfile):
    if count == 0:
        strs = row.strip().split(',')[1:]
    else:
        curr = row.strip().split(',')
        dictionary[curr[0]] = [int(x) for x in curr[1:]]

# for illustration of enumerate func
# for i in csvfile:
#     #print(i)
#     strs = i.strip().split(',')[1:]
#     for j in csvfile:
#         #print(j)
#         curr = list(j.strip().split(','))
#         dictionary[curr[0]] = [int(x) for x in curr[1:]]
# print(strs)
# print(dictionary)

txtfile = open(argv[2], 'r').read()
final_counts = []
for strand in strs:
    i = 0
    max_count = 0
    curr_count = 0
    while i < len(txtfile):
        curr_window = txtfile[i:i+len(strand)]
        if curr_window == strand:
            curr_count += 1
            max_count = max(max_count, curr_count)
            i += len(strand)
        else:
            curr_count = 0  # reset current count
            i += 1
    final_counts.append(max_count)

# to convert dictionary to list .items func
for name, data in dictionary.items():
    if final_counts == data:
        print(name)
        exit(0)

print('No match')

txtfile.close()
csvfile.close()
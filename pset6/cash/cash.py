from cs50 import get_float

counter = 0
# prompt user for +ve integar
while True:
    cents = get_float("Change Owned: ") * 100
    if cents > 0:
        break
# spits out the minimum number of coins    
while cents > 24:
    cents -= 25
    counter += 1
while cents > 9:
    cents -= 10
    counter += 1
while cents > 4:
    cents -= 5
    counter += 1

# sum of counters
counter += cents

# print counter
print(round(counter))
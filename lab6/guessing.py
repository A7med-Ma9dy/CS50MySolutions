import random

x = random.randint(1,10)
for i in range(3):
    a = int(input("Guess: "))
    if a == x:
        print("correct")
        break
        #return in function definitions only
    else:
        print("Incorrect")
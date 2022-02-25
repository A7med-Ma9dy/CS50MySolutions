from cs50 import get_int
# prompt the user with +ve integar
height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")
# create half pyramid
for i in range(height):
    # print space
    for space in range(height - i - 1):
        print(" ", end="")
    # print hash
    for ha in range(i+1):
        print("#", end="")
    # print double middle space
    print("  ", end="")
    # print hash
    for ha in range(i+1):
        print("#", end="")
    # print new line
    print("")
from cs50 import get_string

text = get_string("Text: ")

letters = sentences = 0
# to take the two words before and after space
words = 1
# check
for ch in text:
    if ch.isalpha():
        letters += 1
    if ch.isspace():
        words += 1
    if ch in ['.', '!', '?']:
        sentences += 1
# equation
L = (letters * 100.0) / words
S = (sentences * 100.0) / words
# u can add 0.5 to round it don't know why
Grade = int(round(0.0588 * L - 0.296 * S - 15.8))
# print grades
if Grade < 1:
    print("Before Grade 1")
elif Grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {Grade}")
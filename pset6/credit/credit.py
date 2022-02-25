from cs50 import get_string
# get credit card no as string
credit = get_string("Number: ")
# reverse card string
copyCredit = credit[::-1]
# by using list comprehension
# get first sum by multiply by 2
# if product equal 2 digits add each digit and sum all 
sum1 = sum([((int(x)*2 // 10)) + ((int(x)*2) % 10) for x in copyCredit[1::2]])
# get second sum
sum2 = sum([int(x) for x in copyCredit[0::2]])
totalSum = sum1 + sum2
# print card name
if totalSum % 10 == 0:
    if len(credit) == 15 and credit[0:2] in ['34', '37']:
        print('AMEX')
    elif len(credit) == 16 and 51 <= int(credit[0:2]) <= 55:
        print('MASTERCARD')
    elif len(credit) in [13, 16] and credit[0] == '4':
        print('VISA')
    else:
        print('INVALID')
else:
    print("INVALID")
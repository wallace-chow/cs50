import cs50
def checksum(no):
    def convertlist(no):
        return [int(d) for d in str(no)]
    digits = convertlist(no)
    every_other = digits[-2::-2]
    therest = digits[-1::-2]
    summ = 0
    summ += sum(therest)
    for d in every_other:
        summ += sum(convertlist(d * 2))
    return summ % 10

while True:
    cardno = cs50.get_int("Card Number: ")
    if cardno < 1:
        print("Provide A Proper Card Number With Only Digits")
    else:
        break

if checksum(cardno) == 0:
    cardno = str(cardno)
    if len(cardno) == 15 and (int(cardno[0:2]) in [34, 37]):
        print("AMEX")

    elif len(cardno) == 16 and (int(cardno[0:2]) in [51, 52, 53, 54, 55]):
        print("MASTERCARD")

    elif len(cardno) in [13, 16] and int(cardno[0]) == 4:
        print("VISA")

    else:
        print("INVALID")
else:
    print("INVALID")


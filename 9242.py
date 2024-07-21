code = [input() for _ in range(5)]

nums = [
    "**** ** ** ****",
    "  *  *  *  *  *",
    "***  *****  ***",
    "***  ****  ****",
    "* ** ****  *  *",
    "****  ***  ****",
    "****  **** ****",
    "***  *  *  *  *",
    "**** ***** ****",
    "**** ****  ****"
]

def check(y, x, guess):
    if y==5:
        return True
    if nums[guess][3*y:3*y+3] == code[y][x:x+3]:
        return check(y+1, x, guess)
    else:
        return False

real_num = ""
for x in range(len(code[0])//4+1):
    for guess in range(10):
        if check(0, 4*x, guess):
            real_num += str(guess)
            break
if int(real_num) % 6:
    print("BOOM!!")
else:
    print("BEER!!")
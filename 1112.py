num, n = map(int, input().split())
positive = n < 0 or (n >= 0 and num >= 0)
ans = []
if not positive:
    num *= -1
while num:
    q = num // n
    r = num % n
    if r < 0: # 나머지가 음수인 경우 받아내림
        q += 1
        r -= n
    ans.append(r)
    num = q
if ans:
    if not positive:
        print('-', end='')
    print(*ans[::-1], sep="")
else:
    print(0)
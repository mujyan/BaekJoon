a, b, c = map(int, input().split())
nums = [a-c, a-b, b-c, a+b-c, a+c-b, b+c-a]
if 0 in nums:
    print("S")
else:
    print("N")
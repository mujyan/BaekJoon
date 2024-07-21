N = int(input())
V = tuple(map(int, input().split()))

speed = 0
total = 0
for v in V[::-1]:
    if speed < v:
        speed += 1
    else:
        speed = v
    total += speed
print(total)
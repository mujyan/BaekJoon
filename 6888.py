x = int(input())
y = int(input())
for n in range(x, y+1):
    if (n-x) % 60 == 0:
        print(f"All positions change in year {n}")
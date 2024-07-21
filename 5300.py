N = int(input())
for a in range(1, N+1):
    print(a, end=' ')
    if a % 6 == 0:
        print("Go!", end=' ')
if N % 6:
    print("Go!")
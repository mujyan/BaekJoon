import sys
def input():
    return sys.stdin.readline()

dset = []

def find(x):
    if dset[x] == x:
        return x
    else:
        return find(dset[x])
    
def union(x, y):
    x = find(x)
    y = find(y)
    if x > y:
        dset[x] = y
    else:
        dset[y] = x

for t in range(int(input())):
    N = int(input())
    dset = [n for n in range(N+1)]
    seq = [0] + list(map(int, input().split()))
    for n in range(1, N+1):
        union(seq[n], n)
    ans = 0
    for i in range(1, N+1):
        if find(dset[i] == i):
            ans += 1
    print(ans)
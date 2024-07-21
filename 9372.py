import sys
def input():
    return sys.stdin.readline().rstrip()
for t in range(int(input())):
    N, M = map(int, input().split())
    [input()for _ in range(M)]
    print(N-1)
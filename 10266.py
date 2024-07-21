import sys
def input():
    return sys.stdin.readline().rstrip()
N = int(input())
A = [0] * 360000
for a in map(int, input().split()):
    A[a] = 1
B = [0] * 360000
for b in map(int, input().split()):
    B[b] = 1
B += B[:-1]

j = 0
pi = [0] * 360000
for i in range(1, 360000):
    while j>0 and A[i] != A[j]:
        j = pi[j-1]
    if A[i] == A[j]:
        j += 1
        pi[i] = j

j = 0
for i in range(len(B)):
    while j>0 and A[j] != B[i]:
        j = pi[j-1]
    if A[j] == B[i]:
        if j == 360000 - 1:
            print('possible')
            exit(0)
        else:
            j += 1
print('impossible')
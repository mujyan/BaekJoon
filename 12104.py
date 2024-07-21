import sys
def input():
    return sys.stdin.readline().rstrip()
A = input()
B = input()
j = 0
pi = [0] * len(A)
for i in range(1, len(A)):
    while j>0 and A[i] != A[j]:
        j = pi[j-1]
    if A[i] == A[j]:
        j += 1
        pi[i] = j
j = 0
origin_length = len(B)
B = B + B[:-1]
ans = []
for i in range(len(B)):
    while j>0 and A[j] != B[i]:
        j = pi[j-1]
    if A[j] == B[i]:
        if j == len(A) - 1:
            ans.append(i-len(A)+1)
            j = pi[j]
        else:
            j += 1
print(len(ans))
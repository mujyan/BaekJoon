import sys
def input():
    return sys.stdin.readline().rstrip()
L = int(input())
AD = input()
i, j = (1, 0)
pi = [0] * len(AD)
for i in range(1, len(AD)):
    while j>0 and AD[i] != AD[j]:
        j = pi[j-1]
    if AD[i] == AD[j]:
        j += 1
        pi[i] = j
print(L-pi[L-1])
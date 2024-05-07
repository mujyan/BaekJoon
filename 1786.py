import sys
def input():
    return sys.stdin.readline().rstrip('\n')
context = input()
pattern = input()
pi = [0] * len(pattern)
i = 0
j = 0
for i in range(1, len(pattern)):
    while j>0 and pattern[i] != pattern[j]:
        j = pi[j-1]
    if pattern[i] == pattern[j]:
        j+=1
        pi[i] = j

ans = []
j = 0
for i in range(len(context)):
    while j>0 and context[i] != pattern[j]:
        j = pi[j-1]
    if context[i] == pattern[j]:
        if(j==len(pattern)-1):
            ans.append(i-len(pattern)+2)
            j = pi[j]
        else:
            j+=1
print(len(ans))
print(*ans)
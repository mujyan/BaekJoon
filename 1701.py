import sys
origin_pattern = sys.stdin.readline().rstrip()
ans = 0
for f in range(len(origin_pattern)):
    pattern = origin_pattern[f:len(origin_pattern)]
    pi = [0 for _ in range(len(pattern))]
    j = 0
    for i in range(1, len(pattern)):
        while j > 0 and pattern[j] != pattern[i]:
            j = pi[j-1]
        if pattern[j] == pattern[i]:
            j += 1
            pi[i] = j
    ans = max(ans, max(pi))
print(ans)
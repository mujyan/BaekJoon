s = input()
ans = 0
for _ in range(int(input())):
    if input()[:5] == s[:5]:
        ans += 1
print(ans)
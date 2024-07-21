is_sosu = [True for _ in range(3000)]
is_sosu[0] = False
is_sosu[1] = False
for i in range(2, 3000):
    if is_sosu[i]:
        for j in range(i*2, 3000, i):
            is_sosu[j] = False

N = int(input())
nums = list(map(int, input().split()))
ans = []
for n in nums[1:]:
    if is_sosu[nums[0] + n]:
        ans.append(n)
if ans:
    print(*sorted(ans))
else:
    print(-1)
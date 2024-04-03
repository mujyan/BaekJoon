a,b=map(int,input().split())
print(*sorted([a+b,a-b])[::-1])
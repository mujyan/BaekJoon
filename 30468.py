n=list(map(int,input().split()))
print(max(0,n[-1]*4-sum(n[:4])))
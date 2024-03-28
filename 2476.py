a=0
for _ in range(int(input())):
    d=list(set(map(int,input().split())))
    if len(d)==1:
        a=max(a,d[0]*1000+10000)
    elif len(d)==2:
        a=max(a,1000+d[1]*100)
    else:
        a=max(a,max(d)*100)
print(a)
a,b=map(int,input().split())
c,d=map(int,input().split())
if a+d > b+c:
    print("Persepolis")
elif a+d < b+c:
    print("Esteghlal")
elif b > d:
    print("Esteghlal")
elif b < d:
    print("Persepolis")
else:
    print("Penalty")
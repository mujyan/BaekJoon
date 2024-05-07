a,b,c=map(int,input().split())
while a|b|c|0:
    if b-a==c-b:print(f"AP {b-a+c}")
    else:print(f"GP {c*c//b}")
    a,b,c=map(int,input().split())
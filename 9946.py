import sys
def input():
    return sys.stdin.readline().rstrip()
i=1
while True:
    A = input()
    B = input()
    if A==B=="END":
        break
    elif sorted(A)==sorted(B):
        print(f"Case {i}: same")
    else:
        print(f"Case {i}: different")
    i+=1
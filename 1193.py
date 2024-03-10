bunmo = 1
N = int(input())
pattern = 0
while N > bunmo:
    N -= bunmo
    bunmo += 1
if bunmo % 2:
    print(f"{bunmo-N+1}/{N}")
else:
    print(f"{N}/{bunmo-N+1}")
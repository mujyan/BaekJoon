N = float(input())
while N:
    print(f"{sum([N**exp for exp in range(5)]):.2f}")
    N = float(input())
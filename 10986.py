def main():
    N, M = map(int, input().split())
    A = list(map(int, input().split()))

    count = [0] * M
    count[0] = 1

    total_sum = 0
    result = 0
    for i in range(N):
        total_sum += A[i]
        remainder = total_sum % M
        result += count[remainder]

        count[remainder] += 1

    print(result)

if __name__ == "__main__":
    main()
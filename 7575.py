# KMP
import sys
def input():
    return sys.stdin.readline().rstrip('\n')
N, K = map(int, input().split())
first_code_length = int(input())
first_code_origin = list(map(int, input().split()))
codes = []
for tc in range(N-1):
    input()
    codes.append(list(map(int, input().split())))
for p in range(0, first_code_length-K+1):
    first_code = first_code_origin[p:p+K]
    pi = [0] * K
    j = 0
    for i in range(1, K): # 실패함수
        while j>0 and first_code[i] != first_code[j]:
            j = pi[j-1]
        if first_code[i] == first_code[j]:
            j += 1
            pi[i] = j
    # 실패함수2 뒤집은버전
    first_code_reversed = first_code[::-1]
    pi_reversed = [0] * K
    j = 0
    for i in range(1, K):
        while j>0 and first_code_reversed[i] != first_code_reversed[j]:
            j = pi_reversed[j-1]
        if first_code_reversed[i] == first_code_reversed[j]:
            j += 1
            pi_reversed[i] = j
    key = 0
    for code in codes:
        cur = 0
        length = len(code)
        j = 0
        chk = [0] * length
        for i in range(length):
            while j>0 and code[i] != first_code[j]:
                j = pi[j-1]
            if code[i] == first_code[j]:
                j += 1
                chk[i] = j
            if j == K:
                cur = 1
                break
        # reversed
        j = 0
        chk = [0] * length
        for i in range(length):
            while j>0 and code[i] != first_code_reversed[j]:
                j = pi_reversed[j-1]
            if code[i] == first_code_reversed[j]:
                j += 1
                chk[i] = j
            if j == K:
                cur = 1
                break
        key += cur
    if key == N-1:
        print('YES')
        exit(0)
print('NO')
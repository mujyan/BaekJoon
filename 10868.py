import sys
def input():
    return sys.stdin.readline().rstrip()

N, M = map(int, input().split())
numbers = [int(input()) for _ in range(N)]
tree = [0] * (4 * N)

def create(start, end, node):
    if start == end:
        tree[node] = numbers[start]
        return tree[node]
    mid = (start + end) // 2
    tree[node] = min(create(start, mid, node * 2), create(mid + 1, end, node * 2 + 1))
    return tree[node]

def find_min(start, end, left, right, node):
    if start > right or end < left:
        return float('inf')
    if left <= start and end <= right:
        return tree[node]
    mid = (start + end) // 2
    return min(find_min(start, mid, left, right, node * 2), find_min(mid + 1, end, left, right, node * 2 + 1))

create(0, N-1, 1)
for _ in range(M):
    a, b = map(int, input().split())
    ans = find_min(0, N-1, a-1, b-1, 1)
    print(ans)
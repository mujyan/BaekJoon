import sys
def input():
    return sys.stdin.readline().rstrip()

N, M = map(int, input().split())
numbers = [int(input()) for _ in range(N)]
tree_min = [0] * (4 * N)
tree_max = [0] * (4 * N)

def create_min(start, end, node):
    if start == end:
        tree_min[node] = numbers[start]
        return tree_min[node]
    mid = (start + end) // 2
    tree_min[node] = min(create_min(start, mid, node * 2), create_min(mid + 1, end, node * 2 + 1))
    return tree_min[node]

def find_min(start, end, left, right, node):
    if start > right or end < left:
        return float('inf')
    if left <= start and end <= right:
        return tree_min[node]
    mid = (start + end) // 2
    return min(find_min(start, mid, left, right, node * 2), find_min(mid + 1, end, left, right, node * 2 + 1))

def create_max(start, end, node):
    if start == end:
        tree_max[node] = numbers[start]
        return tree_max[node]
    mid = (start + end) // 2
    tree_max[node] = max(create_max(start, mid, node * 2), create_max(mid + 1, end, node * 2 + 1))
    return tree_max[node]

def find_max(start, end, left, right, node):
    if start > right or end < left:
        return float('-inf')
    if left <= start and end <= right:
        return tree_max[node]
    mid = (start + end) // 2
    return max(find_max(start, mid, left, right, node * 2), find_max(mid + 1, end, left, right, node * 2 + 1))

create_min(0, N-1, 1)
create_max(0, N-1, 1)
for _ in range(M):
    a, b = map(int, input().split())
    print(find_min(0, N-1, a-1, b-1, 1), find_max(0, N-1, a-1, b-1, 1))
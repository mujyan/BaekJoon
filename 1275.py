import sys
def input():
    return sys.stdin.readline().rstrip()
N, Q = map(int, input().split())
numbers = list(map(int, input().split()))
tree = [0] * (4 * N)

def create(start, end, node):
    if start == end:
        tree[node] = numbers[start]
        return tree[node]
    mid = (start + end) // 2
    tree[node] = create(start, mid, node*2) + create(mid + 1, end, node*2+1)
    return tree[node]

def sum(start, end, left, right, node):
    if start > right or end < left:
        return 0
    if left <= start <= end <= right:
        return tree[node]
    mid = (start + end) // 2
    return sum(start, mid, left, right, node*2) + sum(mid + 1, end, left, right, node*2+1)

def update(start, end, index, node, val):
    if not (start <= index <= end):
        return
    if start == end == index:
        tree[node] = val
        return
    mid = (start + end) // 2
    update(start, mid, index, node*2, val)
    update(mid+1, end, index, node*2+1, val)
    tree[node] = tree[node*2] + tree[node*2+1]
    return

create(0, N-1, 1)
for _ in range(Q):
    x, y, a, b = map(int, input().split())
    x, y = sorted((x, y))
    print(sum(0, N-1, x-1, y-1, 1))
    update(0, N-1, a-1, 1, b)
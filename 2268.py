import sys
def input():
    return sys.stdin.readline().rstrip()
N, M = map(int, input().split())
tree = [0] * (4 * N)

def sum(start, end, left, right, node):
    if start > right or end < left:
        return 0
    if left <= start <= end <= right:
        return tree[node]
    mid = (start + end) // 2
    return sum(start, mid, left, right, node*2) + sum(mid+1, end, left, right, node*2+1)

def update(start, end, node, index, val):
    if not (start <= index <= end):
        return
    if start == end == index:
        tree[node] = val
        return
    mid = (start + end) // 2
    update(start, mid, node*2, index, val)
    update(mid + 1, end, node*2+1, index, val)
    tree[node] = tree[node*2] + tree[node*2+1]
    return

for _ in range(M):
    q, a, b = map(int, input().split())
    if q == 0:
        a, b = sorted((a, b))
        print(sum(0, N-1, a-1, b-1, 1))
    else:
        update(0, N-1, 1, a-1, b)
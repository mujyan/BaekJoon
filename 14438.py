import sys
def input():
    return sys.stdin.readline().rstrip()
N = int(input())
numbers = list(map(int, input().split()))
hash = {numbers[i]:i for i in range(N)}
M = int(input())
tree = [0] * (4 * N)

def create(start, end, node):
    if start == end:
        tree[node] = numbers[start]
        return tree[node]
    mid = (start + end) // 2
    tree[node] = min(create(start, mid, node*2), create(mid+1, end, node*2+1))
    return tree[node]

def find_min(start, end, node, left, right):
    if end < left or start > right:
        return float('inf')
    if left <= start <= end <= right:
        return tree[node]
    mid = (start + end) // 2
    return min(find_min(start, mid, node*2, left, right), find_min(mid+1, end, node*2+1, left, right))

def update(start, end, node, index, value):
    if start == end == index:
        tree[node] = value
        return
    if not (start <= index <= end):
        return
    mid = (start + end) // 2
    update(start, mid, node*2, index, value)
    update(mid+1, end, node*2+1, index, value)
    tree[node] = min(tree[node*2], tree[node*2+1])
    return

create(0, N-1, 1)
for i in range(M):
    q, a, b = map(int, input().split())
    if q == 1:
        update(0, N-1, 1, a-1, b)
    else:
        print(hash[find_min(0, N-1, 1, a-1, b-1)]+1)
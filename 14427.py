import sys
def input():
    return sys.stdin.readline().rstrip()

N = int(input())
numbers = list(map(int, input().split()))
tree = [0] * (4 * N)

def compare(a, b):
    if a == -1:
        return b
    elif b == -1:
        return a
    elif numbers[a] == numbers[b]:
        return min(a, b)
    else:
        if numbers[a] > numbers[b]:
            return b
        else:
            return a

def create(start, end, node):
    if start == end:
        tree[node] = start
        return tree[node]
    mid = (start + end) // 2

    left = create(start, mid, node*2)
    right = create(mid+1, end, node*2+1)
    tree[node] = compare(left, right)
    return tree[node]

def min_find(start, end, node, left, right):
    if start > right or end < left:
        return -1
    if left <= start <= end <= right:
        return tree[node]
    mid = (start + end) // 2
    return compare(min_find(start, mid, node*2, left, right), min_find(mid+1, end, node*2+1, left, right))

def update(start, end, node, index):
    if not (start <= index <= end) or start == end:
        return tree[node]
    mid = (start + end) // 2
    left = update(start, mid, node*2, index)
    right = update(mid+1, end, node*2+1, index)
    tree[node] = compare(left, right)
    return tree[node]

create(0, N-1, 1)
for _ in range(int(input())):
    Q = list(map(int, input().split()))
    if Q[0] == 1:
        numbers[Q[1]-1] = Q[2]
        update(0, N-1, 1, Q[1]-1)
    else:
        print(min_find(0, N-1, 1, Q[1]-1, Q[2]-1)+1)
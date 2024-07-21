import sys
def input():
    return sys.stdin.readline().rstrip()
N, M, K = map(int, input().split())
numbers = [int(input()) for _ in range(N)]
tree = [0] * (4 * N)
def create(start, end, node):
    if start == end:  # 최하위 노드
        tree[node] = numbers[start]
        return tree[node]
    mid = (start + end) // 2
    # 부모 노드 = 왼쪽 자식 + 오른쪽 자식
    tree[node] = create(start, mid, node * 2) + create(mid + 1, end, node * 2 + 1)
    return tree[node]

# 현재 구간 [start, end], 구하고자 하는 구간 [left, right]
def sum(start, end, node, left, right):
    # 구하고자 하는 구간을 벗어난 경우(start >= end)
    if left > end or right < start:
        return 0
    if left <= start and end <= right:
        return tree[node]
    mid = (start + end) // 2
    # 구하고자 하는 구간과 일부 겹치는 경우
    childs = sum(start, mid, node*2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right)
    return childs

# index 위치의 원소 값을 val로 변경
def update(start, end, node, index, val):
    if start == end:  # 변경하려는 원소 수정
        tree[node] = val
        return
    mid = (start + end) // 2
    # 변경하려는 원소가 존재하는 범위인 경우
    if start <= index and index <= mid:
        update(start, mid, node*2, index, val)
    else:
        update(mid + 1, end, node*2 + 1, index, val)
    tree[node] = tree[node*2] + tree[node*2+1]
    return

create(0, N-1, 1)
for q in range(M + K):
    a, b, c = map(int, input().split())
    if a == 1:
        update(0, N-1, 1, b-1, c)
    elif a == 2:
        print(sum(0, N-1, 1, b-1, c-1))
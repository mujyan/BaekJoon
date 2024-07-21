import sys
def input():
    return sys.stdin.readline().rstrip()
N = int(input())
M = int(input())
route = [[float('inf') for _ in range(N+1)] for _ in range(N+1)]
for _ in range(M):
    s, e, v = map(int, input().split())
    route[s][e] = min(route[s][e], v)
start, end = map(int, input().split())
visited = [False for _ in range(N+1)]
weight = [float('inf') for _ in range(N+1)]

def find_min_node():
    min_idx = 0
    min_val = float('inf')
    for i in range(1, N+1):
        if visited[i]:
            continue
        if weight[i] < min_val:
            min_val = weight[i]
            min_idx = i
    return min_idx

def choidan():
    for i in range(1, N+1):
        weight[i] = route[start][i]
    
    weight[start] = 0
    visited[start] = True

    for _ in range(N-1):
        cur_node = find_min_node()
        visited[cur_node] = True
        for j in range(1, N+1):
            if visited[j]:
                continue
            elif weight[j] > weight[cur_node] + route[cur_node][j]:
                weight[j] = weight[cur_node] + route[cur_node][j]

choidan()
print(weight[end])
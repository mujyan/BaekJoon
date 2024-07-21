import sys
def input():
    return sys.stdin.readline().rstrip()

N, M, start = map(int, input().split())
route = [[float('inf') for _ in range(N+1)] for _ in range(N+1)]
reversed_route = [[float('inf') for _ in range(N+1)] for _ in range(N+1)]
for _ in range(M):
    s, e, v = map(int, input().split())
    route[s][e] = v
    reversed_route[e][s] = v
visited = [False for _ in range(N+1)]
reversed_visited = [False for _ in range(N+1)]
weight = [float('inf') for _ in range(N+1)]
reversed_weight = [float('inf') for _ in range(N+1)]

def find_min_node(visited, weight):
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
        cur_node = find_min_node(visited, weight)
        visited[cur_node] = True
        for j in range(1, N+1):
            if visited[j]:
                continue
            if weight[j] > weight[cur_node] + route[cur_node][j]:
                weight[j] = weight[cur_node] + route[cur_node][j]
    
    for i in range(1, N+1):
        reversed_weight[i] = reversed_route[start][i]
    reversed_weight[start] = 0
    reversed_visited[start] = True

    for _ in range(N-1):
        cur_node = find_min_node(reversed_visited, reversed_weight)
        reversed_visited[cur_node] = True
        for j in range(1, N+1):
            if reversed_visited[j]:
                continue
            if reversed_weight[j] > reversed_weight[cur_node] + reversed_route[cur_node][j]:
                reversed_weight[j] = reversed_weight[cur_node] + reversed_route[cur_node][j]

    max_val = 0
    for i in range(1, N+1):
        if weight[i] + reversed_weight[i] != float('inf') and weight[i] + reversed_weight[i] > max_val:
            max_val = weight[i] + reversed_weight[i]
    print(max_val)
choidan()
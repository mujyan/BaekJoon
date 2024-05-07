T = int(input())
for _ in range(T):
    N, W = map(int, input().split())
    sections = [list(map(int, input().split())) for _ in range(2)]
    ans = 0
    for i in range(2):
        for j in range(N):
            if sections[i][j]:
                print(f"({i}, {j}) 영역 진행 중")
                close = {
                            sections[i][j-1] : (i, j-1),
                            sections[i][(j+1)%N] : (i, (j+1)%N),
                            sections[(i+1)%2][j] : ((i+1)%2, j)
                        }
                tmp = sections[i][j]
                sections[i][j] = 0
                for enemy in sorted(close.keys(), reverse=True):
                    if tmp + enemy <= W and enemy!=0:
                        tmp += enemy
                        enemy_i, enemy_j = close[enemy]
                        print(f"({i}, {j})에서 {enemy_i} {enemy_j} 처리")
                        sections[enemy_i][enemy_j] = 0
                ans += 1
    print(ans)
#include<iostream>
using namespace std;
/*
map[i][j][x] -> (i, j) 위치에 대한
이동 가능 여부(0), 가로로 놓이는 경우(1), 세로로 놓이는 경우(2), 대각선으로 놓이는 경우(3)
*/
int N;
int map[22][22][4] = {0};
bool garo(int y, int x) {
    if(x+1 > N || map[y][x+1][0]) {
        return false;
    }
    else {
        return true;
    }
}
bool sero(int y, int x) {
    if(y+1 > N || map[y+1][x][0]) {
        return false;
    }
    else {
        return true;
    }
}
bool daegak(int y, int x) {
    if(y+1 > N || x+1 > N || map[y+1][x][0] || map[y][x+1][0] || map[y+1][x+1][0]) {
        return false;
    }
    else {
        return true;
    }
}
int main() {
    int i, j, x, tmp;
    map[1][2][1] = 1;
    cin >> N;
    for(i=1; i<=N; i++) {
        for(j=1; j<=N; j++) {
            cin >> tmp;
            if(tmp) {
                map[i][j][0] = 1;
            }
        }
    }
    for(i=1; i<=N; i++) {
        for(j=1; j<=N; j++) {
            if(garo(i, j)) {
                map[i][j+1][1] += map[i][j][1] + map[i][j][3];
            }
            if(sero(i, j)) {
                map[i+1][j][2] += map[i][j][2] + map[i][j][3];
            }
            if(daegak(i, j)) {
                map[i+1][j+1][3] += map[i][j][1] + map[i][j][2] + map[i][j][3];
            }
        }
    }
    cout << map[N][N][1] + map[N][N][2] + map[N][N][3] << '\n';
}
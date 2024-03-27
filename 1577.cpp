#include<iostream>
using namespace std;

int main() {
    int N, M, K;
    int a, b, c, d;
    long long int under, left;
    long long int map[202][202] = {0};
    cin >> N >> M >> K;
    int i, j;
    for(i=0; i<K; i++) {
        cin >> a >> b >> c >> d;
        if(a!=c) {
            map[(a < c ? a : c)*2+1][b*2] = -1;
        }
        else {
            map[a*2][(b < d ? b : d)*2+1] = -1;
        }
    }
    for(i=0; i<202; i+=2) {
        if(map[i-1][0] == -1) break;
        map[i][0] = 1;
    }
    for(j=0; j<202; j+=2) {
        if(map[0][j-1] == -1) break;
        map[0][j] = 1;
    }
    for(i=2; i<=N*2; i+=2) {
        for(j=2; j<=M*2; j+=2) {
            under = map[i-1][j] == 0 ? map[i-2][j] : 0;
            left = map[i][j-1] == 0 ? map[i][j-2] : 0;
            map[i][j] = under + left;
        }
    }
    cout << map[2*N][2*M];
}
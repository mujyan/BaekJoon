#include<iostream>
using namespace std;

int main() {
    int N;
    int i, j, ans=2;
    cin >> N;
    int route[2][N];
    for(i=0; i<2; i++) {
        for(j=0; j<N; j++) {
            cin >> route[i][j];
            if(!route[i][j]) {
                ans = 1;
            }
        }
    }
    // 검사
    for(i=1;i<N;i++) {
        if(!(route[0][i]+route[1][i-1])) {
            ans = 0;
        }
        else if(!(route[0][i]+route[1][i+1])) {
            ans = 0;
        }
        else if(!(route[0][i]+route[1][i])) {
            ans = 0;
        }
    }
    cout << ans;
}
#include<iostream>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, tmp;
    int dp[1026][1026] = {0};
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> tmp;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + tmp;
        }
    }
    int x1, y1, x2, y2;
    for(int i=0; i<M; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - (dp[y2][x1-1] + dp[y1-1][x2] - dp[y1-1][x1-1]) << '\n';
    }
}
#include<iostream>
using namespace std;
int main() {
    int N, dp[1002][10] = {0};
    int i, j, ormak;
    cin >> N;
    for(i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }
    for(i = 2; i <= N; i++) {
        for(j = 0; j <= 9; j++) {
            for(ormak = j; ormak <= 9; ormak++) {
                dp[i][j] += dp[i-1][ormak];
            }
            dp[i][j] %= 10007;
        }
    }
    int ans = 0;
    for(i = 0; i <= 9; i++) {
        ans += dp[N][i];
    }
    cout << ans % 10007;
}
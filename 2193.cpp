#include<iostream>
using namespace std;
int main() {
    int N;
    long long int dp[10000][2] = {0};
    dp[1][1] = 1;
    cin >> N;
    for(int i=1; i<=N; i++) {
        dp[i][0] += dp[i-1][0] + dp[i-1][1];
        dp[i][1] += dp[i-1][0];
    }
    cout << dp[N][0]+dp[N][1];
}
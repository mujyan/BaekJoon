#include<iostream>
using namespace std;
int main() {
    int N, dp[21] = {0};
    cin >> N;
    dp[1] = 1;
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N];
}
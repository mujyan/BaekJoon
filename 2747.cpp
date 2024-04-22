#include<iostream>
using namespace std;
int main() {
    long long int N, dp[50] = {0};
    dp[1] = 1;
    int i;
    cin >> N;
    for(i=2; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N];
}
#include<iostream>
using namespace std;
int main() {
    int N, T, P;
    int dp[100] = {0}, max = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> T >> P;
        max = max > dp[i] ? max : dp[i];
        dp[i+T] = dp[i+T] > max + P ? dp[i+T] : max + P;
    }
    max = max > dp[N] ? max : dp[N];
    cout << max;
}
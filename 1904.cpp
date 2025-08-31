#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> dp(1000001);
    dp[1]=1;
    dp[2]=2;
    int N, i;
    cin >> N;
    for(i=3; i<=N; i++) {
        dp[i] = (dp[i-2]+dp[i-1]) % 15746;
    }
    cout << dp[N];
    return 0;
}
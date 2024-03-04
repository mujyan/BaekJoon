#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main() {
    int N, K;
    int dp[10001] = {0};
    for(int i=0; i<10001; i++) {
        dp[i] = 10001;
    }
    dp[0] = 0;
    vector<int> coins;

    cin >> N >> K;
    int tmp;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        for(int j=0;j+tmp<10001;j++) {
            dp[j+tmp] = dp[j+tmp] > dp[j] + 1 ? dp[j] + 1 : dp[j+tmp];
        }
    }
    if(dp[K]==10001) {
        cout << -1;
    }
    else {
        cout << dp[K];
    }
}
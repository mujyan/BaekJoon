#include<iostream>
#include<vector>
using namespace std;

int main() {
    long long int N;
    cin >> N;
    vector<long long int> dp(N+1, 999999);
    dp[0] = 0;
    for(int i=0; i<=N; i++) {
        for(int j=1; j<=350; j++) {
            if(i+j*j > N) {
                break;
            }
            dp[i+j*j] = dp[i+j*j] < dp[i] + 1 ? dp[i+j*j] : dp[i] + 1;
        }
    }
    cout << dp[N];
}
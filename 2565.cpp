#include<iostream>
using namespace std;
int main() {
    int N, i, j, x, y, ans = 0;
    int line[501] = {0};
    int dp[501] = {0};
    cin >> N;
    for(i=0; i<N; i++) {
        cin >> x >> y;
        line[x] = y;
    }
    for(i=1; i<501; i++) {
        if(line[i]) {
            dp[i] = 1;
            for(j=1; j<i; j++) {
                if(line[j]) {
                    if(line[i] > line[j]) {
                        dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
                    }
                }
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
    }
    cout << N - ans;
}
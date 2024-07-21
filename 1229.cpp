#include<iostream>
using namespace std;
int main() {
    long long int N, i, j, cur=0, geo[710];
    cin >> N;
    for(i=1; i<=710; i++) {
        cur += i*4-3;
        geo[i-1] = cur;
        cout << cur << endl;
    }
    int dp[1000000] = {0};
    for(i=0; i<1000000; i++) {
        for(j=0; j<710; j++) {
            if(geo[j] + i <= 1000000) {
                dp[i+geo[j]] = dp[i] + 1 < dp[i+geo[j]] ? dp[i] + 1 : dp[i+geo[j]];
            }
        }
    }
}
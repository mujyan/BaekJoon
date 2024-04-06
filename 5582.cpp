#include<iostream>
using namespace std;
#define size 4001
int main() {
    char A[size]={0}, B[size]={0};
    int dp[size][size] = {0};
    int tmp, ans=0;
    scanf("%s %s", A, B);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(A[i]==B[j] && (A[i] || B[j])) {
                if(i>=1 && j>=1) {
                    tmp = dp[i-1][j-1];
                }
                else {
                    tmp = 0;
                }
                dp[i][j] = tmp + 1;
                ans = ans > dp[i][j] ? ans : dp[i][j]; 
            }
        }
    }
    cout << ans;
}
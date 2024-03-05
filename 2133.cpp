#include<iostream>
using namespace std;
int main() {
    long long int dp[35] = {0};
    int N, i, j;
    cin >> N;
    dp[0] = 1;
    dp[2] = 3;
    for(i=4; i<=N; i+=2) {
        // f(i)를 f(i-2)와 f(2)로 만드는 경우
        dp[i] += dp[i-2] * 3;
        for(j=i-4; j>=0; j-=2) {
            // 중복을 피하기 위해서 우측 부분은 f(2)와 달라야 한다.
            // f(2)와 다른 긴 모양이 우측에 존재하면 중복을 피할 수 있다.
            // f(i)를 f(j)와 f(i-j)로 만드는 경우의 수이다.
            // f(i-j)가 바로 긴 모양이며 경우의 수는 2이다.
            dp[i] += dp[j] * 2;
            // 예시로 f(8) = f(6) * f(2) + f(4) * f(4) + f(2) * f(4) 이며,
            // 위 식에서 f(4) * f(4) + f(2) * f(4) 부분을 계산 중이다.
        }
    }
    cout << dp[N];
}
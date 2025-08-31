#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int N, A, cnt, ans=0;
    cin >> N;
    cin >> cnt;
    for(int i=0; i<N-1; i++) {
        cin >> A;
        ans += cnt * A;
        cnt += A;
        ans %= 1000000007;
        cnt %= 1000000007;
    }
    cout << ans;
}
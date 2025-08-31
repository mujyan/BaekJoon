#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, ans=0;
    cin >> N;
    for(int i=1; i<=N; i++) {
        if(i<100) {
            ans++;
        }
        else if(i/100 - (i/10)%10 == (i/10)%10 - i%10) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
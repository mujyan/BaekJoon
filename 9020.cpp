#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int prime_chk[10001]={0};
    prime_chk[0]=1;
    prime_chk[1]=1;
    for(int i=2; i<10000; i++) {
        if(!prime_chk[i]) {
            for(int j=i*2; j<=10000; j+=i) {
                prime_chk[j]++;
            }
        }
    }
    int T, n;
    cin >> T;
    for(;T>0;T--) {
        cin >> n;
        for(int i=n/2+1; i>1; i--) {
            if(!prime_chk[i] && !prime_chk[n-i]) {
                cout << min(i, n-i) << " " << max(i, n-i) << "\n";
                break;
            }
        }
    }
    return 0;
}
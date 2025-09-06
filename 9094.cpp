#include<iostream>
using namespace std;

int main() {
    int a, b, n, m, T, ans=0;
    cin >> T;
    for(int i=0; i<T; i++) {
        ans=0;
        cin >> n >> m;
        for(b=2; b<n; b++) {
            for(a=1; a<b; a++) {
                if((a*a+b*b+m)%(a*b)==0) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
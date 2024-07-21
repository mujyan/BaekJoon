#include<iostream>
#define endl "\n"
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, N, cnt, i, j, tmp;
    cin >> T;
    for(i=0; i<T; i++) {
        cin >> N;
        cnt = 0;
        for(j=1; j<=N; j++) {
            cin >> tmp;
            if(tmp == j + cnt) {
                cnt++;
            }
        }
        cout << cnt+N << endl;
    }

}
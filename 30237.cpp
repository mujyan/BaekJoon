#include<iostream>
#define endl "\n"
using namespace std;

int main() {
    int T, N, i, j, k, t;
    cin >> T;
    for(; T>0; T--) {
        cin >> N;
        int set[51][51] = {0};
        int chk[51] = {0}, set_el_cnt = 0, ans = 0;
        for(i=0; i<N; i++) {
            cin >> k;
            set[i][0] = k;
            for(j=1; j<=k; j++) {
                cin >> t;
                set[i][j] = t;
                if(chk[t]==0) {
                    set_el_cnt++;
                }
                chk[t]++;
            }
        }
        for(i=0; i<N; i++) {
            int task = 0;
            k = set[i][0];
            for(j=1; j<=k; j++) {
                t = set[i][j];
                cout << i << ' ' << j << ' ' << t << ' ';
                if(chk[t] == 1) {
                    task++;
                    cout << "one";
                }
                cout << endl;
            }
            if(task) {
                ans = ans > set_el_cnt - task ? ans : set_el_cnt - task;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
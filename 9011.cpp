#include<iostream>
#define endl "\n"
using namespace std;
// time O(T*N*(N-1)/2) , O(T*N^2)
int main() {
    int T, N, i, max, t;
    cin >> T;
    for(; T>0; T--) {
        cin >> N;
        int S[101] = {0};
        int chk_max[101] = {0};
        int R[101] = {0};
        bool used[101] = {0};
        bool is_possible = false;
        for(i=0; i<N; i++) {
            cin >> R[i];
            if(i>0) {
                chk_max[i] = R[i] > chk_max[i-1] ? R[i] : chk_max[i-1];
            }
        }
        for(i=N-1; i>=0; i--) {
            t = -1;
            for(j=chk_max[i])
        }





        if(is_possible) {
            for(i=0; i<N; i++) {
                cout << R[i] << ' ';
            }
        }
        else {
            cout << "IMPOSSIBLE";
        }
        cout << "\n";
    }
    return 0;
}
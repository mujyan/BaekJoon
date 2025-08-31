#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

int main() {
    int t, n, m, tmp;
    cin >> t;
    while(t--) {
        vector<int> chk(101, 0);
        int ans = 0;
        cin >> n >> m;
        for(int i=0; i<n+m; i++) {
            cin >> tmp;
            chk[tmp]++;
            if(chk[tmp]==2) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}

// 주어지는 n개의 기차와 m개의 기차가 동일한 시간에 출발하면 충돌함
// 그러므로 중복되는 출발 시각의 개수를 출력하면 됨
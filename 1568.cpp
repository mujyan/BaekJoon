#include <iostream>
using namespace std;
int main() {
    int N; cin >> N;
    int ans = 0, cur = 1;
    while(N > 0) {
        if(cur > N) {
            cur = 1;
        }
        N -= cur;
        cur++;
        ans++;
    }
    cout << ans;
    return 0;
}
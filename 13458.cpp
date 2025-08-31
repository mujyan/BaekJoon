#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, ans=0;
    cin >> N;
    vector<int> rope(N);
    for(int i=0; i<N; i++) {
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end());
    for(int i=0; i<N; i++) {
        ans = ans > rope[i]*(N-i) ? ans : rope[i]*(N-i);
    }
    cout << ans;
    return 0;
}
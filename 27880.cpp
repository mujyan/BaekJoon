#include<iostream>
using namespace std;
int main() {
    string A;
    int N, ans = 0;
    for(int i=0; i<4; i++) {
        cin >> A >> N;
        if(A == "Es") {
            ans += N * 21;
        }
        else {
            ans += N * 17;
        }
    }
    cout << ans;
}
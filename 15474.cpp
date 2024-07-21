#include<iostream>
using namespace std;
int main() {
    int N, A, B, C, D, x, y, ans;
    cin >> N >> A >> B >> C >> D;
    x = N/A*B;
    y = N/C*D;
    if(N%A) {
        x += B;
    }
    if(N%C) {
        y += D;
    }
    ans = x < y ? x : y;
    cout << ans;
}
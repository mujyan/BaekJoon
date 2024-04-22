#include<iostream>
using namespace std;
int N, K;
bool bitCount(int num) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if ((num & 1) == 1) {
            cnt++;
        }
        num >>= 1;
    }
    if (cnt <= K) {
        return false;
    }
    return true;
}
int main() {
    int cur = 1, ans = 0;\
    cin >> N >> K;
    while (bitCount(N)) {
        if (N % 2 == 0) {
            N /= 2;
            cur *= 2;
        }
        else {
            ans += cur;
            N++;
        }
    }
    cout << ans;
}
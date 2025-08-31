#include<iostream>
using namespace std;

int main() {
    int N, ans=0;
    for(int val=3; val<=5; val++) {
        cin >> N;
        ans += N*val;
    }
    cout << ans;
    return 0;
}
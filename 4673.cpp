#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

int f(int num) {
    int rtn = 0;
    while(num>0) {
        rtn += num % 10;
        num /= 10;
    }
    return rtn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<bool> chk(20001, true);
    for(int i=0; i<10001; i++) {
        chk[i+f(i)] = false;
        if(chk[i]) {
            cout << i << endl;
        }
    }
    return 0;
}
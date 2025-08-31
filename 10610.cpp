#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string number;
    cin >> number;
    int zero=0, chk=0;
    vector<char> newNum;
    for(int i=0; i<number.length(); i++) {
        if(number[i]=='0') {
            zero++;
        }
        else {
            chk = (chk + int(number[i]))%3;
            newNum.push_back(number[i]);
        }
    }
    sort(newNum.begin(), newNum.end());
    if(zero && !chk) {
        while(newNum.size()) {
            cout << newNum.back();
            newNum.pop_back();
        }
        while(zero--) {
            cout << 0;
        }
    }
    else {
        cout << -1;
    }
    return 0;
}
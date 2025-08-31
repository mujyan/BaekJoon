#include<iostream>
#include<vector>
using namespace std;
int main() {
    int N, even=0, odd=0, tmp;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        if(tmp%2) {
            odd++;
        }
        else {
            even++;
        }
    }
    if(odd-even > 1 || odd-even < 0) {
        cout << 0;
    }
    else {
        cout << 1;
    }
}
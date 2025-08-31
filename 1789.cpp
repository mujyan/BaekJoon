#include<iostream>
using namespace std;

int main() {
    long long int S;
    cin >> S;
    for(long long int i=2;; i++) {
        if(S < i*(i+1)/2) {
            cout << i-1;
            break;
        }
    }
    return 0;
}
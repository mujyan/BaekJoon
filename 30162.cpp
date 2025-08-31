#include<iostream>
using namespace std;

int main() {
    long long int N;
    cin >> N;
    if(N%2) {
        cout << 0;
    }
    else {
        cout << (1<<(N/2));
    }
}
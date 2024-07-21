#include<iostream>
using namespace std;
int main() {
    int N, i, t = 1;
    cin >> N;
    while(N >= t*10) {
        N += t * 5;
        t *= 10;
        N -= N % t;
    }
    cout << N;
    return 0;
}
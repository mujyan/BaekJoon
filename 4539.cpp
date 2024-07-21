#include<iostream>
using namespace std;
int main() {
    int N, num, i, t;
    cin >> N;
    for(i=0; i<N; i++) {
        cin >> num;
        t = 1;
        while(num >= t*10) {
            num += t * 5;
            t *= 10;
            num -= num % t;
        }
        cout << num << endl;
    }
    return 0;
}
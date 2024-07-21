#include<iostream>
using namespace std;
int main() {
    long long int p, t;
    int T, i;
    cin >> T;
    for(i=0; i<T; i++) {
        cin >> p >> t;
        cout << p - t / 7 + t / 4 << "\n";
    }
}
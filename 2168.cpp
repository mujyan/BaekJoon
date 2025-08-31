#include<iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x, y;
    cin >> x >> y;
    int GCD = gcd(x, y);
    cout << GCD * ((x/GCD - 1) + (y/GCD - 1) + 1);
}
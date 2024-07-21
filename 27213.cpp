#include<iostream>
using namespace std;
int main() {
    long long int m, n;
    cin >> m >> n;
    if(m==1 || n==1) {
        cout << m + n - 1;
    }
    else {
        cout << 2*(m+n)-4;
    }
}
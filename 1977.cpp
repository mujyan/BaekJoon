#include<iostream>
using namespace std;

int main() {
    long long int M, N, sum=0, min;
    cin >> M >> N;
    for(long long int i=N; i>=M; i--) {
        for(long long int j=1; j<=100; j++) {
            if(j*j == i) {
                sum += i;
                min = i;
                break;
            }
        }
    }
    if(sum) {
        cout << sum << endl;
        cout << min;
    }
    else {
        cout << -1;
    }
    return 0;
}
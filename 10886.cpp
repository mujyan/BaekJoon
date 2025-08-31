#include<iostream>
using namespace std;
int main() {
    int N, tmp, cnt=0;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        cnt += tmp;
    }
    if(N/2 < cnt) {
        cout << "Junhee is cute!";
    }
    else {
        cout << "Junhee is not cute!";
    }
    return 0;
}
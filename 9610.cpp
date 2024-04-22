#include<iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a, b;
    int Q[5]={0};
    for(int i=0; i<N; i++) {
        cin >> a >> b;
        if(a==0 || b==0) {
            Q[0]++;
        }
        else if(a > 0) {
            if(b > 0) {
                Q[1]++;
            }
            else {
                Q[4]++;
            }
        }
        else {
            if(b > 0) {
                Q[2]++;
            }
            else {
                Q[3]++;
            }
        }
    }
    for(int i=1; i<=4; i++) {
        cout << "Q" << i << ": " << Q[i] << endl;
    }
    cout << "AXIS: " << Q[0];
}
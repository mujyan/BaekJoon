#include<iostream>
using namespace std;
int main() {
    int N, shirts[6] = {0}, i, T, P, ans_shirts = 0;
    cin >> N;
    for(i=0; i<6; i++) {
        cin >> shirts[i];
    }
    cin >> T >> P;
    for(i=0; i<6; i++) {
        ans_shirts += shirts[i] / T;
        if(shirts[i] % T) {
            ans_shirts++;
        }
    }
    cout << ans_shirts << "\n" << N / P << " " << N % P;
}
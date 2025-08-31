#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<bool> chk(1000002, false);
    long long int min, max, ans=0;
    cin >> min >> max;
    // 2에서 부터 차례대로 제곱수 생성
    for(long long int i=2; i<1000000; i++) {
        // 제곱수의 배수들을 기록
        for(long long int j=(min/(i*i) > 0 ? min/(i*i) : 1)*i*i; j<=max; j+=i*i) {
            if(min <= j && j <= max) {
                // 메모리를 아끼기 위해서,
                // (제곱수의 배수 - 최솟값 + 1)에 기록
                chk[j-min+1] = true;
            }
        }
    }
    // 제곱수의 배수 개수 계산
    for(int i=0; i<1000002; i++) {
        if(chk[i]) {
            ans++;
        }
    }
    // 구간의 크기 - 제곱수의 배수 개수
    cout << max - min - ans + 1;
    return 0;
}
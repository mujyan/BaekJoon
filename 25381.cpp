#include<iostream>
using namespace std;

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 문자열 S 입력
    string S;
    cin >> S;

    int A=0, B=0, ans=0, cnt=0;
    // A-B 쌍 짓기 최대 횟수 ans에 누적
    for(int i=0; i<S.length(); i++) {
        // A 
        if(S[i]=='A') {
            A++;
        }
        else if(S[i]=='B') {
            cnt++;
            if(A>0) {
                A--;
                ans++;
            }
        }
    }
    
    // B-C 쌍 짓기 최대 횟수 ans에 누적
    B=0;
    for(int i=0; i<S.length(); i++) {
        if(S[i]=='B') {
            B++;
        }
        else if(S[i]=='C') {
            if(B>0) {
                B--;
                ans++;
            }
        }
    }

    // A-B 쌍짓기와 B-C 쌍짓기가 각자 최대로 할 수 있는 횟수는 B의 총 개수를 넘지않는 선에서 최대값이다
    cout << min(ans, cnt);
}
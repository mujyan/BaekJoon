#include<iostream>
using namespace std;
int main() {
    long long int L, i, j, ans=0, n;
    string word;
    cin >> L >> word;
    for(i=0; i<word.length(); i++) {
        n=(word[i] - 'a' + 1);
        for(j=0; j<i; j++) {
            n = n * 31 % 1234567891;
        }
        ans += n;
    }
    cout << ans % 1234567891;
}
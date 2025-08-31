#include <iostream>
#include <string.h>
using namespace std;

int ans;
int recursion(const char *s, int l, int r){
    ans++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    int N;
    string str;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> str;
        ans = 0;
        cout << isPalindrome(str.c_str()) << ' ';
        cout << ans << "\n";
    }
}
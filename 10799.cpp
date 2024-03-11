#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<char> stick;
    string input;
    char cur;
    int ans = 0;
    cin >> input;
    for(int i=0; i<input.length(); i++) {
        cur = input[i];
        if(cur == '(') {
            stick.push(cur);
        }
        else if(cur == ')') {
            stick.pop();
            if(input[i-1] == '(') {
                ans += stick.size();
            }
            else {
                ans += 1;
            }
        }
    }
    cout << ans;
}
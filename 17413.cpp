#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
    int i, key=true;
    string input;
    stack<char> reverse;
    getline(cin, input);
    for(i=0; i<input.length(); i++) {
        if(input[i] == '<') {
            key = false;
            while(!reverse.empty()) {
                cout << reverse.top();
                reverse.pop();
            }
            cout << input[i];
        }
        else if(input[i] == '>') {
            key = true;
            cout << input[i];
        }
        else if(key) {
            if(input[i] == ' ') {
                while(!reverse.empty()) {
                    cout << reverse.top();
                    reverse.pop();
                }
                cout << input[i];
            }
            else {
                reverse.push(input[i]);
            }
        }
        else {
            cout << input[i];
        }
    }
    while(!reverse.empty()) {
        cout << reverse.top();
        reverse.pop();
    }
}
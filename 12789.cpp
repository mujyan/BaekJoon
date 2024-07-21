#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> waiting;
    int N, cur = 1, student;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> student;
        if(cur == student) {
            cur++;
        }
        else {
            waiting.push(student);
        }
        while(!waiting.empty()) {
            if(waiting.top() == cur) {
                cur++;
                waiting.pop();
            }
            else {
                break;
            }
        }
    }
    if(waiting.empty()) {
        cout << "Nice";
    }
    else {
        cout << "Sad";
    }
    return 0;
}
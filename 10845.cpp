#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    queue<int> nums;
    string command;
    int tmp;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> command;
        if(command == "push") {
            cin >> tmp;
            nums.push(tmp);
        }
        else if(command == "pop") {
            if(nums.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << nums.front() << '\n';
                nums.pop();
            }
        }
        else if(command == "size") {
            cout << nums.size() << '\n';
        }
        else if(command == "empty") {
            cout << (nums.empty() ? 1 : 0) << '\n';
        }
        else if(command == "front") {
            cout << (nums.empty() ? -1 : nums.front()) << '\n';
        }
        else if(command == "back") {
            cout << (nums.empty() ? -1 : nums.back()) << '\n';
        }
    }
}
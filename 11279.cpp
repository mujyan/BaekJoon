#include<iostream>
#include<queue>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> pq;
    int N, x;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> x;
        if(x) {
            pq.push(x);
        }
        else if(pq.empty()) {
            cout << 0 << endl;
        }
        else {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
    return 0;
}
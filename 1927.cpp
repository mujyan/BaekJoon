#include<iostream>
#include<queue>
#define endl "\n"
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int> pq;
    int N, i, q;
    cin >> N;
    for(i=0; i<N; i++) {
        cin >> q;
        if(q) {
            pq.push(-q);
        }
        else if(!pq.empty()) {
            cout << -pq.top() << endl;
            pq.pop();
        }
        else {
            cout << 0 << endl;
        }
    }
}
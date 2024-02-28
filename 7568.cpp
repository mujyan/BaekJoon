#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    vector<pair<int, int>> V;
    cin >> N;
    int x, y;
    for(int i=0; i<N; i++) {
        cin >> x >> y;
        V.push_back(make_pair(x, y));
    }
    for(int i=0; i<N; i++) {
        int place=1;
        for(int j=0; j<N; j++) {
            if(V[i].first < V[j].first && V[i].second < V[j].second) {
                place++;
            }
        }
        cout << place << ' ';
    }
}
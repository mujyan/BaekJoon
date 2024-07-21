#include<iostream>
using namespace std;
int set[1001];

int find(int x) {
    if(set[x] == x) {
        return x;
    }
    return find(set[x]);
}

void unioon(int x, int y) {
    x = find(x);
    y = find(y);
    if(x < y) {
        set[y] = x;
    }
    else {
        set[x] = y;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, i, u, v, ans=0;
    cin >> N >> M;
    for(i=0; i<1001; i++) {
        set[i] = i;
    }
    for(i=0; i<M; i++) {
        cin >> u >> v;
        unioon(u, v);
    }
    for(i=1; i<=N; i++) {
        if(set[i] == i) {
            ans++;
        }
    }
    cout << ans;
}
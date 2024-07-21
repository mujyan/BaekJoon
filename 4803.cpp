#include<iostream>
#define endl "\n"
using namespace std;

int set[501];
int N, M;
int find(int x) {
    if(set[x] == x) {
        return x;
    }
    else {
        set[x] = find(set[x]);
        return set[x];
    }
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if(x < y) {
        set[y] = x;
    }
    else if(x > y) {
        set[x] = y;
    }
    else {
        set[x] = 0;
        set[y] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans, i, j, x, y, case_num = 0;
    while(true) {
        cin >> N >> M;
        if(N==0 && M==0) {
            break;
        }
        ans = 0;
        case_num++;
        for(i=0; i<=N; i++) {
            set[i] = i;
        }
        for(i=0; i<M; i++) {
            cin >> x >> y;
            uni(x, y);
        }
        for(i=1; i<=N; i++) {
            if(set[i] == i) {
                ans++;
            }
        }
        cout << "Case " << case_num;
        if(ans == 0) {
            cout << ": No trees." << endl;
        }
        else if(ans == 1) {
            cout << ": There is one tree." << endl;
        }
        else {
            cout << ": A forest of " << ans << " trees." << endl;
        }
    }
}
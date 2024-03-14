#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct dc {
    int weight;
    int num;
};

bool cmp(int x, int y) {
    if(x > y) {
        return true;
    }
    return false;
}

int main() {
    int T, N, M, i, tmp, ans;
    struct dc docu;
    cin >> T;
    for(;T>0;T--) {
        ans = 0;
        queue<struct dc> input;
        queue<int> sorted;
        cin >> N >> M;
        for(i=0; i<N; i++) {
            cin >> tmp;
            docu.weight = tmp;
            docu.num = i;
            input.push(docu);
            sorted.push(tmp);
        }
        sort(&sorted.front(), &sorted.back()+1, cmp);
        while(!input.empty()) {
            docu = input.front();
            if(docu.weight == sorted.front()) {
                ans++;
                if(docu.num == M) {
                    break;
                }
                input.pop();
                sorted.pop();
            }
            else {
                input.pop();
                input.push(docu);
            }
        }
        cout << ans << '\n';
    }
}
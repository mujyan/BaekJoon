#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

vector<pair<int, int>> sample;

pair<int, int> find(int x) {
    if(sample[x].first == x) {
        return sample[x];
    }
    pair<int, int> tmp = find(sample[x].first);
    sample[x].first = tmp.first;
    sample[x].second += tmp.second;
    return sample[x];
}

void uni(int a, int b, int v) {
    pair<int, int> x = find(a);
    pair<int, int> y = find(b);
    if(x.first < y.first) {
        sample[y.first].first = x.first;
        sample[y.first].second = x.second - y.second - v;
    }
    else {
        sample[x.first].first = y.first;
        sample[x.first].second = y.second - x.second + v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int M, N, a, b, v;
    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) {
            break;
        }
        sample.clear();
        for(int i = 0; i <= N; i++) {
            sample.push_back(make_pair(i, 0));
        }

        char query;
        for(int i = 0; i < M; i++) {
            cin >> query;
            if(query == '!') {
                cin >> a >> b >> v;
                uni(a, b, v);
            }
            else {
                cin >> a >> b;
                if(find(a).first == find(b).first) {
                    cout << find(a).second - find(b).second << endl;
                } else {
                    cout << "UNKNOWN" << endl;
                }
            }
        }
    }
    return 0;
}

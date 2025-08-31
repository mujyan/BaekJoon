#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<pair<int, int>> road;
    vector<pair<int, int>> drive;

    int N, M, d, s, ans=0, i, j;
    cin >> N >> M;
    road.push_back({0, 0});
    for(i=0; i<N; i++) {
        cin >> d >> s;
        road.push_back({road.back().first + d, s});
    }
    drive.push_back({0, 0});
    for(i=0; i<M; i++) {
        cin >> d >> s;
        drive.push_back({drive.back().first + d, s});
    }
    i=0; j=0;
    for(int p=0; p<=100; p++) {
        if(p > road[i].first) {
            i++;
        }
        if(p > drive[j].first) {
            j++;
        }
        ans = max(ans, drive[j].second - road[i].second);
    }
    cout << ans;
    return 0;
}
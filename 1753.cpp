#include<iostream>
#include<vector>
#include<queue>
#define INF 10*19999+1
#define endl "\n"
using namespace std;

vector<pair<int, int>> map[20001];
int route[20001];
int V, E, start;

void dijkstra() {
    int i, j, cur_node, cur_weight;
    
    route[start] = 0;
    priority_queue<pair<int, int>> task;
    task.push(make_pair(0, start));
    while(!task.empty()) {
        cur_weight = -task.top().first;
        cur_node = task.top().second;
        task.pop();
        if(route[cur_node] >= cur_weight) {
            for(i=0; i<map[cur_node].size(); i++) {
                int next_node = map[cur_node][i].first;
                int next_weight = cur_weight + map[cur_node][i].second;
                if(next_weight < route[next_node]) {
                    route[next_node] = next_weight;
                    task.push({-next_weight, next_node});
                }
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, s, e, v;
    cin >> V >> E >> start;
    for(i=0; i<E; i++) {
        cin >> s >> e >> v;
        map[s].push_back(make_pair(e, v));
    }
    for(i=0; i<20001; i++) {
        route[i] = INF;
    }
    dijkstra();
    for(i=1; i<=V; i++) {
        if(route[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << route[i] << endl;
        }
    }
}
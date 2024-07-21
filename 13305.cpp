#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main() {
    long long int N, i, tmp, cur_price = INT64_MAX, ans = 0;
    vector<long long int> road;
    cin >> N;
    for(i=0; i<N-1; i++) {
        cin >> tmp;
        road.push_back(tmp);
    }
    for(i=0; i<N-1; i++) {
        cin >> tmp;
        cur_price = cur_price < tmp ? cur_price : tmp;
        ans += cur_price * road[i];
    }
    cin >> tmp;
    cout << ans;
}
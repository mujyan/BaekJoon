#include<iostream>
#include<vector>
using namespace std;
int main() {
    long long int N, K, i, tmp;
    vector<long long int> suffix;
    cin >> N >> K;

    cin >> tmp;
    suffix.push_back(tmp);
    for(i=1; i<N; i++) {
        cin >> tmp;
        suffix.push_back(tmp+suffix[i-1]);
    }

    long long int ans = suffix[K-1];
    for(i=K; i<N; i++) {
        ans = ans > suffix[i] - suffix[i-K] ? ans : suffix[i] - suffix[i-K];
    }
    cout << ans;
}
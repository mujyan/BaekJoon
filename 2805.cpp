#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long int N, M, i;
    cin >> N >> M;
    vector<long long int> trees(N);
    for(i=0; i<N; i++) {
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end());
    long long int L=0, R=trees[N-1], H=0, mid;
    while(L<=R) {
        mid = (L+R)/2;
        long long int sum=0;
        for(i=0; i<N; i++) {
            sum += trees[i] - mid > 0 ? trees[i] - mid : 0;
        }
        if(sum>=M) {
            L = mid+1;
            H = H>mid?H:mid;
        }
        else {
            R = mid-1;
        }
    }
    cout << H;
    return 0;
}
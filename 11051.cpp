#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> triangle = {{0}};
    for(int i=1; i<=N; i++) {
        vector<int> cur = {1};
        for(int j=1; j<=i-1; j++) {
            cur.push_back((triangle[i-1][j-1]+triangle[i-1][j])%10007);
        }
        cur.push_back(1);
        triangle.push_back(cur);
    }
    cout << triangle[N][K];
}
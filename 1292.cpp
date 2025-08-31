#include<iostream>
#include<vector>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    vector<int> prefix_sum(1, 0);
    for(int i=1; i<50; i++) {
        for(int j=0; j<i; j++) {
            prefix_sum.push_back(prefix_sum.back()+i);
        }
    }
    cout << prefix_sum[B]-prefix_sum[A-1];
}
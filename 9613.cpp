#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;

long long int gcd(int a, int b) {
    int mod=1;
    while(mod) {
        mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

int main() {
    long long int T;
    cin >> T;
    while(T--) {
        long long int N, ans=0;
        cin >> N;
        vector<long long int> nums(N);
        for(int i=0; i<N; i++) {
            cin >> nums[i];
        }
        for(int i=0; i<N-1; i++) {
            for(int j=i+1; j<N; j++) {
                ans += gcd(nums[i], nums[j]);
            }
        }
        cout << ans << endl;
    }
}
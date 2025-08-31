#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long int t, n, nums, cur;
    cin >> t;
    while(t--) {
        vector<long long int> nums;
        long long int ex, ans=0;
        long long int subtrahend = 0;
        cin >> n;
        cin >> cur;
        nums.push_back(cur);
        for(int i=1; i<n; i++) {
            cin >> cur;
            nums.push_back(cur);
            ans += abs(nums[i] - nums[i-1]);
        }
        for(int i=1; i<n-1; i++) {
            subtrahend = max(subtrahend, abs(nums[i]-nums[i-1])+abs(nums[i]-nums[i+1])-abs(nums[i-1]-nums[i+1]));
        }
        subtrahend = max(subtrahend, abs(nums[0]-nums[1]));
        subtrahend = max(subtrahend, abs(nums[n-1]-nums[n-2]));
        cout << ans - subtrahend << endl;
    }
}
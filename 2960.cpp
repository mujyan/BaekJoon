#include<iostream>
using namespace std;
int main() {
    int N, K, num = 2;
    int nums[1001] = {0};
    cin >> N >> K;
    int cnt = 0, ans;
    while(cnt < K) {
        if(nums[num] == 0) {
            for(int i=num; i<=N; i+=num) {
                if(nums[i] == 0) {
                    nums[i] = 1;
                    cnt++;
                    if(cnt == K) {
                        ans = i;
                    }
                }
            }
        }
        num++;
    }
    cout << ans;
}
#include<iostream>
#include<vector>
using namespace std;
int ans[5];
vector<int> primes;
bool f(int cur, int ex, int remain) {
    if(remain==0) {
        if(cur==0) {
            return true;
        }
        else {
            return false;
        }
    }
    for(int i=ex; i<primes.size(); i++) {
        if(primes.at(i) > cur) {
            return false;
        }
        else {
            if(f(cur-primes.at(i), i, remain-1)) {
                ans[4-remain] = primes.at(i);
                return true;
            }
        }
    }
    return false;
}
int main() {
    int N, numbers[1000001] = {0};
    cin >> N;
    int num=2, i;
    while(num<1000001) {
        if(numbers[num] == 0) {
            primes.push_back(num);
            for(i=num; i<=1000000; i+=num) {
                numbers[i] = 1;
            }
        }
        num++;
    }
    f(N, 0, 4);
    if(ans[0]==0) {
        cout << -1;
    }
    else {
        for(i=0; i<4; i++) {
            cout << ans[i] << ' ';
        }
    }
}
#include<iostream>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int array[1001]={0};
    int step = K, cnt = 0, index = K;
    cout << '<';
    while(true) {
        if(index > N) {
            index = 1;
        }
        if(array[index] == 0) {
            if(step % K == 0) {
                cnt++;
                array[index] = 1;
                cout << index;
                if(cnt == N) {
                    cout << '>';
                    return 0;
                }
                cout << ", ";
            }
            step++;
        }
        index++;
    }
}
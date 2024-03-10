#include<iostream>
using namespace std;
int main() {
    int cnt=0;
    float N, a, b;
    scanf("%f", &N);
    for(a=1; a<N/2; a++) {
        for(b=a; b>0; b--) {
            if(N-a-b > 0 && N-a-b <= b && N-a-b <= a) {
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}
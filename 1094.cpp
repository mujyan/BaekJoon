#include<iostream>
using namespace std;

int main() {
    int E, S, M, e, s, m, i;
    cin >> E >> S >> M;
    for(i=1, e=0, s=0, m=0; E!=e%15+1 || S!=s%28+1 || M!=m%19+1; i++, e++, s++, m++);
    cout << i;
    return 0;
}
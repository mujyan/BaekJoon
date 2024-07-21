#include<iostream>
#define endl "\n"
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool set[21] = {0};
    int M, i, x;
    string command;
    cin >> M;
    for(i=0; i<M; i++) {
        cin >> command;
        if(command == "add") {
            cin >> x;
            set[x] = 1;
        }
        else if(command == "remove") {
            cin >> x;
            set[x] = 0;
        }
        else if(command == "check") {
            cin >> x;
            cout << set[x] << endl;
        }
        else if(command == "toggle") {
            cin >> x;
            set[x] = !set[x];
        }
        else if(command == "all") {
            for(int j=1; j<=20; j++) {
                set[j] = 1;
            }
        }
        else if(command == "empty") {
            for(int j=1; j<=20; j++) {
                set[j] = 0;
            }
        }
    }
}
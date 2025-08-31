#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int origin;
int ans=1000000;
void f(string *X, string *cur) {
    if(cur->size() == X->size()) {
        if(stoi(*cur) > origin) {
            ans = ans < stoi(*cur) ? ans : stoi(*cur);
        }
        return;
    }
    for(int i = 0; i < X->size(); i++) {
        if((*X)[i] != '=') {
            cur->append(1, (*X)[i]);
            (*X)[i] = '=';
            f(X, cur);
            (*X)[i] = (*cur)[cur->size() - 1];
            cur->pop_back();
        }
    }
    return;
}

int main() {
    string X;
    string cur;
    cin >> X;
    origin = stoi(X);
    f(&X, &cur);
    if(ans == 1000000) {
        cout << 0;
    }
    else {
        cout << ans;
    }
}
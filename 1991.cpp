#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> seq;
vector<pair<int, int>> tree(26);

void preorder() {
    int cur=seq.back();
    seq.pop_back();
    int a=tree[cur].first, b=tree[cur].second;
    cout << char(cur+'A');
    if(a>=0) {
        seq.push_back(a);
        preorder();
    }
    if(b>=0) {
        seq.push_back(b);
        preorder();
    }
    return;
}

void inorder() {
    int cur=seq.back();
    seq.pop_back();
    int a=tree[cur].first, b=tree[cur].second;
    if(a>=0) {
        seq.push_back(a);
        inorder();
    }
    cout << char(cur+'A');
    if(b>=0) {
        seq.push_back(b);
        inorder();
    }
    return;
}

void postorder() {
    int cur=seq.back();
    seq.pop_back();
    int a=tree[cur].first, b=tree[cur].second;
    if(a>=0) {
        seq.push_back(a);
        postorder();
    }
    if(b>=0) {
        seq.push_back(b);
        postorder();
    }
    cout << char(cur+'A');
    return;
}

int main() {
    int N, i;
    char a, b, c;
    cin >> N;
    for(i=0; i<N; i++) {
        cin >> a >> b >> c;
        tree[a-'A']={b-'A', c-'A'};
    }
    seq.push_back(0);
    preorder();
    cout << endl;

    seq.push_back(0);
    inorder();
    cout << endl;

    seq.push_back(0);
    postorder();
    return 0;
}
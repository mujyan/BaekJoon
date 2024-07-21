#include<iostream>
#define INF 1000001
#define endl "\n"
using namespace std;
int tree_max[200001];
int tree_min[200001];
int numbers[50001];

int create_max(int start, int end, int node) {
    if(start == end) {
        tree_max[node] = numbers[start];
        return tree_max[node];
    }
    int mid = (start + end) / 2;
    int left = create_max(start, mid, node*2);
    int right = create_max(mid+1, end, node*2+1);
    return tree_max[node] = left > right ? left : right;
}

int create_min(int start, int end, int node) {
    if(start == end) {
        tree_min[node] = numbers[start];
        return tree_min[node];
    }
    int mid = (start + end) / 2;
    int left = create_min(start, mid, node*2);
    int right = create_min(mid+1, end, node*2+1);
    return tree_min[node] = left < right ? left : right;
}

int find_max(int start, int end, int node, int left, int right) {
    if(end < left || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree_max[node];
    }
    int mid = (start + end) / 2;
    int c1 = find_max(start, mid, node*2, left, right);
    int c2 = find_max(mid+1, end, node*2+1, left, right);
    return c1 > c2 ? c1 : c2;
}

int find_min(int start, int end, int node, int left, int right) {
    if(end < left || right < start) {
        return INF;
    }
    if(left <= start && end <= right) {
        return tree_min[node];
    }
    int mid = (start + end) / 2;
    int c1 = find_min(start, mid, node*2, left, right);
    int c2 = find_min(mid+1, end, node*2+1, left, right);
    return c1 < c2 ? c1 : c2;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, Q, i, A, B;
    cin >> N >> Q;
    for(i=0; i<N; i++) {
        cin >> numbers[i];
    }
    create_max(0, N-1, 1);
    create_min(0, N-1, 1);
    for(i=0; i<Q; i++) {
        cin >> A >> B;
        cout << find_max(0, N-1, 1, A-1, B-1) - find_min(0, N-1, 1, A-1, B-1) << endl;
    }
}
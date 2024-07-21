#include<iostream>
#define endl "\n";
using namespace std;
int N, M;
int numbers[100000];
int tree_even[400000];
int tree_odd[400000];
int create_even(int start, int end, int node) {
    if(start == end) {
        if(numbers[start]%2 == 0) {
            tree_even[node] = 1;
        }
        return tree_even[node];
    }
    int mid = (start + end) / 2;
    return tree_even[node] = create_even(start, mid, node*2) + create_even(mid+1, end, node*2+1);
}
int create_odd(int start, int end, int node) {
    if(start == end) {
        if(numbers[start]%2 == 1) {
            tree_odd[node] = 1;
        }
        return tree_odd[node];
    }
    int mid = (start + end) / 2;
    return tree_odd[node] = create_odd(start, mid, node*2) + create_odd(mid+1, end, node*2+1);
}

int count_even(int start, int end, int node, int left, int right) {
    if(start > right || end < left) {
        return 0;
    }
    if(left <= start &&  end <= right) {
        return tree_even[node];
    }
    int mid = (start + end) / 2;
    return count_even(start, mid, node*2, left, right) + count_even(mid+1, end, node*2+1, left, right);
}

int count_odd(int start, int end, int node, int left, int right) {
    if(start > right || end < left) {
        return 0;
    }
    if(left <= start &&  end <= right) {
        return tree_odd[node];
    }
    int mid = (start + end) / 2;
    return count_odd(start, mid, node*2, left, right) + count_odd(mid+1, end, node*2+1, left, right);
}

void update_even(int start, int end, int node, int idx) {
    if(start == end && start == idx) {
        if(numbers[idx] % 2 == 0) {
            tree_even[node] = 1;
        }
        else {
            tree_even[node] = 0;
        }
        return;
    }
    if(idx < start || end < idx) {
        return;
    }
    int mid = (start + end) / 2;
    update_even(start, mid, node*2, idx);
    update_even(mid+1, end, node*2+1, idx);
    tree_even[node] = tree_even[node*2] + tree_even[node*2+1];
    return;
}

void update_odd(int start, int end, int node, int idx) {
    if(start == end && start == idx) {
        if(numbers[idx] % 2 == 1) {
            tree_odd[node] = 1;
        }
        else {
            tree_odd[node] = 0;
        }
        return;
    }
    if(idx < start || end < idx) {
        return;
    }
    int mid = (start + end) / 2;
    update_odd(start, mid, node*2, idx);
    update_odd(mid+1, end, node*2+1, idx);
    tree_odd[node] = tree_odd[node*2] + tree_odd[node*2+1];
    return;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, q, l, r;
    cin >> N;
    for(i=0; i<N; i++) {
        cin >> numbers[i];
    }
    create_even(0, N-1, 1);
    create_odd(0, N-1, 1);
    cin >> M;
    for(i=0; i<M; i++) {
        cin >> q >> l >> r;
        if(q == 1) {
            numbers[l-1] = r;
            update_even(0, N-1, 1, l-1);
            update_odd(0, N-1, 1, l-1);
        }
        else if(q == 2) {
            cout << count_even(0, N-1, 1, l-1, r-1) << endl;
        }
        else {
            cout << count_odd(0, N-1, 1, l-1, r-1) << endl;
        }
    }
}
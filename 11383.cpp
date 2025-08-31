#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> img;
    string tmp;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        img.push_back(tmp);
    }
    for(int i=0; i<N; i++) {
        cin >> tmp;
        for(int j=0; j<M; j++) {
            if(!(tmp[j*2]==tmp[j*2+1] && tmp[j*2]==img[i][j])) {
                cout << "Not Eyfa";
                return 0;
            }
        }
    }
    cout << "Eyfa";
}
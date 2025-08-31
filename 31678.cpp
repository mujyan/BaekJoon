// 구현 문제 싫어요
#include<iostream>
#include<vector>
#include<string>
#define endl "\n"
using namespace std;

int N;
vector<string> names;
vector<vector<vector<int>>> bingo;
vector<vector<vector<bool>>> marked;
vector<vector< pair<int, int> >> num_to_pos;

bool has_bingo(int p) {
    // 행 검사
    for(int i=0; i<5; i++) {
        bool row_bingo = true;
        for(int j=0; j<5; j++) {
            if(!marked[p][i][j]) {
                row_bingo = false;
                break;
            }
        }
        if(row_bingo) return true;
    }

    // 열 검사
    for(int j=0; j<5; j++) {
        bool col_bingo = true;
        for(int i=0; i<5; i++) {
            if(!marked[p][i][j]) {
                col_bingo = false;
                break;
            }
        }
        if(col_bingo) return true;
    }

    // 주요 대각선 검사
    bool diag_bingo = true;
    for(int i=0; i<5; i++) {
        if(!marked[p][i][i]) {
            diag_bingo = false;
            break;
        }
    }
    if(diag_bingo) return true;

    // 역대각선 검사
    diag_bingo = true;
    for(int i=0; i<5; i++) {
        if(!marked[p][i][4 - i]) {
            diag_bingo = false;
            break;
        }
    }
    if(diag_bingo) return true;

    // 빙고가 없음
    return false;
}

int main() {
    cin >> N;
    names.resize(N);
    bingo.resize(N, vector<vector<int>>(5, vector<int>(5)));
    marked.resize(N, vector<vector<bool>>(5, vector<bool>(5, false)));
    num_to_pos.resize(N, vector< pair<int,int> >(91, make_pair(-1, -1)));

    for(int p=0; p<N; p++) {
        cin >> names[p];
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                int num;
                cin >> num;
                bingo[p][i][j] = num;
                num_to_pos[p][num] = make_pair(i, j);
            }
        }
    }

    int m;
    cin >> m;
    vector<int> drawn_numbers(m);
    for(int i=0; i<m; i++) {
        cin >> drawn_numbers[i];
    }

    // 숫자 마킹
    for(int i=0; i<m; i++) {
        int x = drawn_numbers[i];
        for(int p=0; p<N; p++) {
            pair<int,int> pos = num_to_pos[p][x];
            if(pos.first != -1) {
                int row = pos.first;
                int col = pos.second;
                marked[p][row][col] = true;
            }
        }
    }

    // 빙고를 가진 플레이어 찾기
    vector<string> bingo_players;
    for(int p=0; p<N; p++) {
        if(has_bingo(p)) {
            bingo_players.push_back(names[p]);
        }
    }

    cout << bingo_players.size() << endl;
    for(auto name : bingo_players) {
        cout << name << endl;
    }

    return 0;
}
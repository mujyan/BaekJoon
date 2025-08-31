#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    string board[10][2] = {{"11", "A B C D E F G H J L M"},
					   {"9", "A C E F G H I L M"},
					   {"9", "A C E F G H I L M"},
					   {"9", "A B C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A C E F G H L M"},
					   {"8", "A B C F G H L M"}};
    cout << board[N-1][0] << endl << board[N-1][1];
}
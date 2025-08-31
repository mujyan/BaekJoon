#include<iostream>
#include<vector>
using namespace std;

int main() {
    int h, w, garo=0;
    bool found = false;
    cin >> h >> w;
    vector<string> pic;
    for(int i=0; i<h; i++) {
        string tmp;
        cin >> tmp;
        pic.push_back(tmp);
    }
    pic.push_back("");
    for(int i=0; i<h && !found; i++) {
        for(int j=1; j<w-1 && !found; j++) {
            if(pic[i][j]=='*') {
                found = true;
                pic[i][j]='.';
                for(int d=i+1; d<h; d++) {
                    if(pic[d][j]=='.') {
                        break;
                    }
                    if(pic[d][j-1]=='*' && pic[d][j+1]=='*' && pic[d+1][j]=='*') {
                        garo++;
                        for(int left=j-1; left>=0; left--) {
                            if(pic[d][left]=='.') {
                                break;
                            }
                            else {
                                pic[d][left] = '.';
                            }
                        }
                        for(int right=j+1; right<=w; right++) {
                            if(pic[d][right]=='.') {
                                break;
                            }
                            else {
                                pic[d][right] = '.';
                            }
                        }
                    }
                    pic[d][j]='.';
                }
            }
        }
    }
    if(found && garo==1) {
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(pic[i][j]=='*') {
                    cout << "NO";
                    return 0;
                }
            }
        }
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
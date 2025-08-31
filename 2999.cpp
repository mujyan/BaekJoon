#include<iostream>
#include<vector>
using namespace std;;

int main() {
    string cypher;
    int R, C;
    cin >> cypher;
    for(int i=cypher.length()/2; i>0; i--) {
        if(cypher.length()%i==0) {
            R=i;
            C=cypher.length()/i;
            if(R<=C)
                break;
        }
    }
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cout << cypher[j*R+i];
        }
    }
}
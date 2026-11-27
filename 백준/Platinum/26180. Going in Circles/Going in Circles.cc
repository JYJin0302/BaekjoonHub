#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

string base = "010110000011100001011010100010110001101101110010110100101110"; // len 60


int state[202020];
int curPos = 101010;

string ans = "0100101001";
int ansLen = (int)ans.size();
int ansPos = 0;


void left(){
    cout << "? left" << endl;
    curPos--;
    cin >> state[curPos];
}

void right(){
    cout << "? right" << endl;
    curPos++;
    cin >> state[curPos];
}

void flip(){
    cout << "? flip" << endl;
    cin >> state[curPos];
}

void solve(){
    
    // len <= 60 check

    int pos1 = curPos;
    cin >> state[curPos];
    while(curPos < pos1 + 70){
        if (state[curPos]) {
            flip();
        }
        else {
            right();
        }
    }

    if(!state[curPos]) flip();

    int pos2 = curPos;

    while(curPos > pos1){
        left();
        if(state[curPos]){
            cout << "! " << pos2 - curPos << endl;
            return;
        }
    }
    int len = (int)base.size();
    
    pos1 = curPos;
    while(curPos < pos1 + len){
        int ix = curPos - pos1;
        if (state[curPos] != base[ix] - '0') flip();
        right();
    }

    while(1){
        // cycle check
        bool ok = 1;
        for(int j =0; j < len; j++){
            if (state[pos1+j] == state[curPos - len + j + 1]) {}
            else ok = 0;
        }

        if (ok){
            cout << "! " << curPos - pos1 + 1 - len << endl;
            return;
        }
        right();
    }


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}


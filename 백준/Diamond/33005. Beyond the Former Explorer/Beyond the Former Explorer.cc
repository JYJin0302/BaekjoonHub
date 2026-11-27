#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<int,int> pi;

int cx = 2500, cy = 2500;
char G[5050][5050];


int n;
char getInput(){
    char c;
    cin >> c;

    if (c == 'G') exit(0);
    return c;
}

int totCnt = 0;
void move(char c){
    cout << c << endl;
    if (c == '^') cy++;
    else if (c == 'v') cy--;
    else if (c == '>') cx++;
    else cx--;
    G[cx][cy] = getInput();
    totCnt++;
}

void moveTo(int x, int y){
    while(cx > x) move('<');
    while(cx < x) move('>');
    while(cy > y) move('v');
    while(cy < y) move('^');
}

int cntBox(int x1, int y1, int x2, int y2){
    int res = 0;
    for(int i = x1; i <= x2; i++){
        if (G[i][y1-1] == '^') res++;
        if (G[i][y1] == 'v') res--;

        if(G[i][y2+1] == 'v') res++;
        if(G[i][y2] == '^') res--;
    }

    for(int i = y1; i <= y2; i++){
        if (G[x1-1][i] == '>') res++;
        if (G[x1][i] == '<') res--;

        if (G[x2+1][i] == '<') res++;
        if (G[x2][i] == '>') res--;
    }
    return res;
}

bool checkIN(int x1, int y1, int x2, int y2){
    return x1 <= 2500 && 2500 <= x2 && y1 <= 2500 && 2500 <= y2;
}

void fillG(int x1, int y1, int x2, int y2){
    int mx = (x1 + x2) >> 1;
    int my = (y1 + y2) >> 1;
    
    int area = (x2 - x1 + 1) * (y2 - y1 + 1);
    if (area * 2 + totCnt <= 30000){
        moveTo(x1, y1);
        while(cy <= y2){
            if (cx == x1){
                while(cx != x2) move('>');
            }
            else{
                while(cx != x1) move('<');
            }
            move('^');
        }
        // must be end
        assert(0);
    }

    bool vertical = 0;
    if (abs(mx - cx) <= abs(my - cy)) vertical = 1;


    if(vertical){
        moveTo(mx, cy);
        int tx = cx, ty = cy;
        moveTo(tx, y2);
        moveTo(tx+1, y2);
        moveTo(tx+1, y1);
        moveTo(tx, y1);
        moveTo(tx, ty);

        int res = cntBox(mx+1, y1, x2, y2);
        if (res > 0 || (res == 0 && checkIN(mx+1, y1, x2, y2))){
            moveTo(mx+1, my);
            fillG(mx+1, y1, x2, y2);
        }
        else{
            moveTo(mx, my);
            fillG(x1, y1, mx, y2);
        }
        return;
    }

    moveTo(cx, my);
    int tx = cx, ty = cy;
    moveTo(x2, ty);
    moveTo(x2, ty+1);
    moveTo(x1, ty+1);
    moveTo(x1, ty);
    moveTo(tx, ty);

    int res = cntBox(x1, my+1, x2, y2);
    if (res > 0 || (res == 0 && checkIN(x1, my+1, x2, y2))){
        moveTo(mx, my+1);
        fillG(x1, my+1, x2, y2);
    }
    else{
        moveTo(mx, my);
        fillG(x1, y1, x2, my);
    }

}

void solve(){
    
    cin >> n;
    fillG(cx - n, cy - n, cx + n, cy + n);

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
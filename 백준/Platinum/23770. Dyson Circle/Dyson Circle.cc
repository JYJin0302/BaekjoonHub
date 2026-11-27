#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<pair<int, int>> ans;

bool isE(int nx, int ny, pair<int,int>p){
    return nx == p.x && ny == p.y;
}

int oper(int a, int b){
    // a-b/2
    int x = a-b;
    if(x %2 == 0 || x >= 0) return x/2;
    return x/2-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >>n;
    int UR = -1e7, DL= 1e7;
    int DR = 1e7, UL = -1e7;

    vector<pair<int, int>> P(n);
    for(auto&i : P) {
            cin >>i.x >>i.y;
            UR = max(UR, i.x+i.y);
            DL= min(DL, i.x+i.y);
            DR = min(DR, i.y-i.x);
            UL= max(UL, i.y-i.x);
    }

    UR++, DL--;
    DR--, UL++;
    if (n == 1){
        cout << 4;
        return 0;
    }

    //cout << UR<<' ' << DR<<' ' << DL << ' ' <<UL <<'\n';

    if(UR == DL + 2){

        int d = (UL - DR) / 2;
        cout <<2*d+3;

        return 0;
    }
    if (UL == DR+2){
        int d = (UR - DL)/2;
        cout <<2*d+3;
        return 0;

    }


    pair<int,int> p1, p11, p2, p22, p3, p33, p4, p44;
    int tx = oper(UR, DR);
    p1 = {tx, UR-tx};
    p11 = {tx, tx+ DR};

    tx = oper(DL, DR);
    if(abs(DL - DR)%2 == 1){
        p2 = {tx+1, tx+1 + DR};
    }
    else p2 = {tx, tx+DR};
    p22 = {tx, DL-tx};

    tx = oper(DL, UL);
    if (abs(DL - UL) % 2 == 1){
        p3 = {tx+1, DL - tx-1};
        p33 = {tx+1, UL + tx+1};
    }
    else{
        p3 = {tx, DL - tx};
        p33 = {tx, UL + tx};
    }

    tx = oper(UR, UL);
    if (abs(UR - UL) % 2 == 1){
        p4 = {tx, UL + tx};
        p44 = {tx+1, UR - tx-1};
    }
    else{
        p4 = {tx, UL + tx};
        p44 = {tx, UR - tx};
    }
/*
    cout << "TEST;\n";
    for(auto i : {p1, p11, p2, p22, p3, p33, p4, p44}){
        cout <<i.x <<' '<< i.y << '\n';
    }
*/
    ans.push_back(p1);
    int px, py;
    tie(px, py) = p11;
    while(!isE(px, py, p2)){
        ans.push_back({px, py});
        px--, py--;
    }
    ans.push_back(p2);
    tie(px, py) = p22;
    while(!isE(px, py, p3)){
        ans.push_back({px, py});
        px--, py++;
    }
    ans.push_back(p3);

    tie(px, py) = p33;
    while(!isE(px, py, p4)){
        ans.push_back({px, py});
        px++, py++;
    }
    ans.push_back(p4);

    tie(px, py) = p44;
    while(!isE(px, py, p1)){
        ans.push_back({px, py});
        px++, py--;
    }

    //for(auto i :ans) cout << i.x << ' ' <<i.y <<'\n';
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size();
}


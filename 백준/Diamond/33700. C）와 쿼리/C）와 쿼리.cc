#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
struct Node{
    int U, C, uCnt;
    Node(){
        U = C = 0;
        uCnt = 0;
    }
 
    void setVal(char c){
        if (c == 'U') U = 1, uCnt = 1, C = 0;
        else U = 0, uCnt = 0, C = 1;
    }
    void pf(){
        cout << "(" << U << ' ' << C << ' ' << uCnt << ")";
    }
 
    Node operator+(const Node& o) const {
        Node res;
        res.U = U + o.U - min(C, o.U);
        res.C = C + o.C - min(C, o.U);
        res.uCnt = uCnt + o.uCnt;
        return res;
    }
} seg[606060];
 
char state[202020];
void update(int l, int r, int n, int u, char c){
    if (l > u || r < u) return;
    if (l == u && r == u){
        seg[n].setVal(c);
        return;
    }
 
    int md =(l+r)>>1;
    update(l, md, n*2, u, c);
    update(md+1, r, n*2+1, u, c);
    seg[n] = seg[n*2] + seg[n*2+1];
    // cout << "Seg "<< l << ' ' << r << ": ";
    // seg[n].pf();
    // cout << endl;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n ;i++){
        cin >> state[i];
        update(0, n-1, 1, i, state[i]);
    }
    
    Node res = seg[1];
    cout << (res.C + 1) / 2 * 2 + res.uCnt << '\n';
 
    while(q--){
        int x;
        cin >> x;
        x--;
        state[x] = char('U' + 'C' - state[x]);
 
        update(0, n-1, 1, x, state[x]);
 
        Node res = seg[1];
        cout << (res.C + 1) / 2 * 2 + res.uCnt << '\n';
    }       
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}

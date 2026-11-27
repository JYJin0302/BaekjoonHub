#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
vector<int> up[202020], dw[202020];
 
void solve(){
     
    int n, m, q;
    cin >> n >> m >> q;
 
    while(m--){
        int a, b;
        cin >> a >> b;  
        if (a > b)swap(a, b);
        up[a].push_back(b);
        dw[b].push_back(a);
    }
 
    vector<pair<int, int>> upQ(n+1), dwQ(n+1);
    for(int i = 1; i <= q; i++){
        int x, d, c;
        cin >> x >> d >> c;
        if (d == 1) upQ[x] = mp(c, i);
        else dwQ[x] = mp(c, i);
    }
 
    for(int i = 1; i <= n; i++){
        if (upQ[i].x == 0) continue;
        for(auto f : up[i]){
            if (upQ[f].y <= upQ[i].y) upQ[f] = upQ[i];
        }
    }
    for(int i = n; i >= 1; i--){
        if (dwQ[i].x == 0) continue;
        for(auto f : dw[i]){
            if (dwQ[f].y <= dwQ[i].y) dwQ[f] = dwQ[i];
        }
    }
 
    for(int i = 1; i <= n ;i++){
        //cout << upQ[i].x << ' ' << upQ[i].y << " | " << dwQ[i].x << ' ' << dwQ[i].y << '\n';
        if (upQ[i].y >= dwQ[i].y) cout << upQ[i].x << ' ';
        else cout << dwQ[i].x << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
   // cin >> t;
    while (t--) solve();
}

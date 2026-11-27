#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll g_P[3][3];

ll solve_P(ll x, ll y){
    if (x > y) swap(x, y);
    
    if (g_P[x][y] != -1) return g_P[x][y];
    if (x == 0 && y == 0) return g_P[x][y] = 0;
    
    vector<ll> cnt(5);
    for(ll i = 0; i < x; i++) cnt[solve_P(i, y)]++;
    for(ll j = 0; j < y; j++) cnt[solve_P(x, j)]++;
    if (x > 0 && y > 0) cnt[solve_P(x-1, y-1)]++;
    
    ll r = 0;
    while(cnt[r] > 0) r++;
    return g_P[x][y] = r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(g_P, -1, sizeof(g_P));
    
    ll n;
    cin >> n;
    
    ll ans = 0;
    while(n--){
        
        char c;
        ll x, y;
        cin >> x >> y >> c;
        if (x > y) swap(x,y);
        
        if (c == 'R') ans ^= (x^y);
        else if (c == 'B') ans ^= min(x, y);
        else if (c == 'K'){
            if (x % 2 == 0) ans ^= y % 2;
            else ans ^= 3 - y%2;
        }
        else if (c == 'N'){
            ll ta = 0;
            if (x == y) ta = (x % 3) == 2;
            else if (x % 3 == 2) ta = 2 - (y - x == 1);
            else ta = x % 3;
            ans ^= ta;
        }
        else {
            ll tx = x / 3, ty = y / 3;
            ans ^= solve_P(x%3, y%3) + (tx^ty)*3;
        }
    }
    
    if (ans != 0) cout << "koosaga";
    else cout << "cubelover";
}
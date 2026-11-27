#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


int dx [] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve(){
    
    ll tx, ty;
    cin >> tx >> ty;

    string s;
    cin >> s;

    array<ll, 3> ans = {tx*tx + ty*ty, 0, 0};
    ll x = 0, y = 0;
    int ix = 0;
    int sn = (int)s.size();

    int dir = 2;
    while(ix< sn){
        char c= s[ix++];

        ll val = 0;
        while(ix < sn && isdigit(s[ix])){
            val = val * 10 + s[ix] - '0';
            ix++;
        }

        if (c == 'S'){
            ll nx = x, ny = y;
            nx += val * dx[dir];
            ny += val * dy[dir];

            ll dx = abs(nx - tx);
            ll dy = abs(ny - ty);

            bool ok = 1;
            if(dx && ans[0] / dx < dx) ok = 0;
            if (dy && ans[0] / dy < dy) ok = 0;

            ans = min(ans, {dx*dx + dy*dy, nx, ny});

            if (min(x, nx) <= tx && tx <= max(x, nx)){
                ll dy = abs(y - ty);
                if (dy && ans[0] / dy < dy) {}
                else ans = min(ans, {dy*dy, tx, y});
            }

            if(min(y, ny) <= ty && ty <= max(y, ny)){
                ll dx = abs(x - tx);
                if (dx && ans[0] / dx < dx) {}
                else ans = min(ans, {dx*dx, x, ty});
            }
            
            x = nx, y = ny;
        }
        else{
            val %= 4;
            val = 4- val;
            dir = (dir + val) % 4;
        }

    }

    if (ans[0] == 0) cout << -1 << '\n';
    else cout << ans[1] << ' '<< ans[2] << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

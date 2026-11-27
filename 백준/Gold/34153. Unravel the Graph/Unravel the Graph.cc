#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 1e15;
ll D[505][505];

void solve() {
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            D[i][j] = INF;
        }
        D[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;

        D[a][b] = min(D[a][b], c);
        D[b][a] = min(D[b][a], c);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
            }
        }
    }

    ll ans = 0;
    int a1= 0 , a2 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n; j++){
            ans = max(ans, D[i][j]);
            if (ans == D[i][j]){
                a1 = i, a2 = j;
            }
        }
    }
    
    vector<ll> res(n+1);
    for(int i = 1; i <= n; i++){
        res[i] = D[a1][i];
    }

    for(int i = 1; i <= n; i++) cout << res[i] << ' ';
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
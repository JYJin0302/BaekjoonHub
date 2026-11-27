#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 998244353;
vector<pair<ll, ll>> adj[101010];

ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1){
            res = res * b % mod;
        }
        b = b  * b % mod;
        ex >>= 1;
    }
    return res;
}

ll S[101010];
ll cnt[101010];

void solve() {
 
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a>> b >> c;

        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    S[1] = 0;
    cnt[1] = 1;
    vector<int> dist(n+1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){

        int a = q.front(); q.pop();

        for(auto [u,v]: adj[a]){
            if (dist[u] == -1 || dist[u] == dist[a] + 1){
                if (dist[u] == -1) q.push(u);
                dist[u] = dist[a] + 1;
                S[u] += S[a] + cnt[a] * v % mod;
                S[u] %= mod;
                cnt[u] += cnt[a];
                cnt[u] %= mod;
            }
        }
    }
    
    for(int i =2; i<= n; i++){
        cout << S[i] * fastPow(cnt[i], mod-2) % mod << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[101010];
int buk = 300;
ll cnt[101010];
bool isB[101010];

const int mod = 1e9 + 7;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edg;
    while(m--){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edg.push_back(mp(a, b));
    }

    for(int i = 1; i <= n; i++) sort(all(adj[i]));

    
    vector<int> B, S;
    for(int i = 1; i <= n; i++){
        if (adj[i].size() >= buk){
            B.push_back(i);
            isB[i] = 1;
        }
        else{
            S.push_back(i);
        }
    }

    ll ans = 0;
    for(auto f : B){
        for(auto v1 : adj[f]){
            if (v1 > f && isB[v1]) continue;
            for(auto v2 : adj[v1]){
                if (v2 > f && isB[v2]) continue;
                if (v2 == f) continue;
                ans += cnt[v2];
                ans %= mod;
                cnt[v2]++;
            }
        }


        for(auto v1 : adj[f]){
            if (v1 > f && isB[v1]) continue;
            for(auto v2 : adj[v1]){
                if (v2 > f && isB[v2]) continue;
                if(v2 == f) continue;
                cnt[v2]--;
            }
        }
    }
    
    ll ans2 = 0;
    for(auto f : S){
        for(auto v1 : adj[f]){
            if (isB[v1]) continue;
            for(auto v2 : adj[v1]){
                if (isB[v2] || v2 == f) continue;
                ans2 += cnt[v2];
                ans2 %= mod;
                cnt[v2]++;
            }
        }

        for(auto v1 : adj[f]){
            if (isB[v1]) continue;
            for(auto v2 : adj[v1]){
                if (isB[v2] || v2 == f) continue;
                cnt[v2]--;
            }
        }
    }
   // cout << ans << ' ' << ans2 << '\n';
    ans += ans2 * ((mod + 1) / 4) % mod;
    ans %= mod;
    cout << ans << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
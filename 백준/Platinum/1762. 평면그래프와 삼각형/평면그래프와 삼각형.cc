#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[101010];
int buk = 500;
ll cnt[101010];
bool isB[101010];

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
            if (isB[v1] && v1 < f) continue;
            ans += cnt[v1];
            for(auto v2 : adj[v1]){
                if (!isB[v2] || v2 > v1){
                    cnt[v2]++;
                }
            }
        }

        for(auto v1 : adj[f]){
            if (isB[v1] && v1 < f) continue;
            for(auto v2 : adj[v1]){
                if (!isB[v2] || v2 > v1){
                    cnt[v2]--;
                }
            }
        }
    }
    
    ll ans2 = 0;
    for(auto[a,b] : edg){
        if(isB[a] || isB[b]) continue;
        for(auto f : adj[a]) if (!isB[f]) cnt[f]++;
        for(auto f : adj[b]) ans2 += cnt[f];
        for(auto f : adj[a]) if (!isB[f]) cnt[f]--;
    }
    
    cout << ans + ans2 / 3 << '\n';

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
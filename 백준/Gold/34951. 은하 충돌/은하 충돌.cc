#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<pair<int, int>> adj[404040], rev[404040];

int topo[404040];
int ord[404040];
int S[404040];

ll dp[404040];
bool inQ[404040];

void solve(){

    int n, m, e;
    cin >> n >> m >> e;

    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if (u < 0) u = n - u;
        if (v < 0) v = n - v;
        adj[u].push_back(mp(v, w));
        topo[v]++;
        rev[v].push_back(mp(u, w));
    }
    for(int i =1; i <= m; i++){
        cin >> S[i + n];
    }

    int G; cin >> G;
    int target = 1e9 + 10;
    for(auto [a,b] : adj[G]) target = min(target, b);
    for(auto [a,b] : rev[G]) target = min(target, b);

    if (target > 1e9 + 5){
        cout << "SAD\n";
        return;
    }

    int o = 0;
    queue<int> q;
    for(int i = 1; i <= n+m; i++){
        if (topo[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int a= q.front();q.pop();
        ord[a] = ++o;
        for(auto[u, v] : adj[a]){
            topo[u]--;
            if (topo[u] == 0) q.push(u);
        }
    }

    set<pair<int, int>> st;

    ll res = 0;
    dp[1] = 0;
    inQ[1] = 1;
    st.insert(mp(ord[1], 1));
    while(!st.empty()){
        auto f = *st.begin();
        st.erase(st.begin());

        res = max(res, dp[f.y]);

        for(auto[a,b] : adj[f.y]){
            dp[a] = max(dp[a], dp[f.y] + S[a]);
            if (!inQ[a]){
                inQ[a] =1;
                st.insert({ord[a], a});
            }
        }
    }

    if (res >= target) cout << "HAPPY\n";
    else cout << "SAD\n";

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
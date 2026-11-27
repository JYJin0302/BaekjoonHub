#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[101010];
int dist[101010];
pair<int, int> ret;

void dfs(int v, int pv = -1){
    ret= max(ret, mp(dist[v], v));
    for(auto f : adj[v]) if (f != pv){
        dist[f] = dist[v] + 1;
        dfs(f, v);
    }
}

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int >> edg;
    for(int i = 0; i < (n-1) * 2; i++){
        int a, b;
        cin >> a>> b;
        if (a > b) swap(a, b);
        edg.push_back(mp(a, b));
    }

    sort(all(edg));
    for(int i = 1; i < (int)edg.size(); i++){
        if (edg[i] == edg[i-1]){
            auto[a,b] = edg[i];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    memset(dist, -1, sizeof dist);

    array<int, 3> ans = {-1, 0, 0};

    for(int i =1; i <= n; i++){
        if (dist[i] == -1){
            dist[i] = 0;
            ret = mp(-1, 0);
            dfs(i);

            int r = ret.y;
            dist[r] = 0;
            ret = mp(-1, 0);
            dfs(r);

            ans = max(ans, {ret.x, r, ret.y});
        }
    }

    if (ans[1] == ans[2]) cout << -1 << '\n';
    else cout << ans[1] << ' ' << ans[2] << '\n';

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

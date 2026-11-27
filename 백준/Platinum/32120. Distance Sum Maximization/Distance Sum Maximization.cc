#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair

int U[303030], D[303030];
int spt[20][303030];
int p[20][303030];

vector<pair<int, int>> tmp[303030];

int dep[303030];

vector<int> adj[303030];
void dfs(int v, int pv = -1){
    vector<pair<int, int>> mx;
    mx.push_back(mp(0, v));
    for(auto f : adj[v]) if (f != pv) {
        p[0][f] = v;
        dep[f] = dep[v] + 1;
        dfs(f, v);
        mx.push_back(mp(D[f] + 1, f));
    }
    sort(mx.rbegin(), mx.rend());

    for(auto f : adj[v]) if (f != pv) {
        for(auto d : mx){
            if (d.second == f) continue;
            spt[0][f] = d.first;
            break;
        }
    }

    if(mx.size() != 1) D[v] = mx[0].first;

    while(mx.size() < 3) mx.push_back(mp(0, 0));

    for(int i = 0; i < 3; i++){
        tmp[v].push_back(mx[i]);
    }
}

void dfs2(int v, int pv = -1, int uVal = 0){
    U[v] = uVal;
   // cout << "Go: " << v << ' '<< pv << ' '<< uVal << '\n';

    vector<pair<int, int>> mx;
    for(auto f: adj[v]) if (f != pv){
        mx.push_back(mp(D[f] + 1, f));
    }

    mx.push_back(mp(uVal, pv));
    sort(mx.rbegin(), mx.rend());
    //for(auto f : mx) cout << f.first << ' ' << f.second << '\n';

    for(auto f: adj[v]) if (f != pv){
        for(auto d : mx){
            if(d.second != f && d.second != pv){
                spt[0][f] = d.first;
                break;
            }
        }

        for(auto d : mx){
            if(d.second != f){
                dfs2(f, v, d.first + 1);
                break;
            }
        }
    }
}

void solve(){

    int n;
    cin >> n;
    for(int i =0 ;i < n- 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    dfs2(1);

    //for(int i= 1; i <= n; i++) cout << D[i] << ' '<< U[i] << '\n';
    for(int i = 1; i < 20 ;i++){
        for(int j = 1; j <= n; j++){
            p[i][j] = p[i-1][p[i-1][j]];
        }
        for(int j = 1; j <= n; j++){
            spt[i][j] = max(spt[i-1][j], spt[i-1][p[i-1][j]]);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;

        if(dep[u] > dep[v]) swap(u, v);

        int dif = dep[v] - dep[u];

        int ad = 0;
        int res = D[v];

        for(int i =0 ; i < 20; i++){
            if (dif & (1 << i)){
                res = max(res, spt[i][v]);
                v = p[i][v];
                ad += 1 << i;
            }
        }

        if(v == u){
            res = max(res, U[v]);
        }
        else{
            res = max(res, D[u]);
            for(int i = 19; i >= 0; i--){
                if (p[i][u] != p[i][v]){
                    res = max({res, spt[i][u], spt[i][v]});
                    u = p[i][u];
                    v = p[i][v];
                    ad += 2 << i;
                }
            }
            ad += 2;
            int lm = p[0][u];

            for(auto f: tmp[lm]){
                if(f.second != u && f.second != v) {
                    res = max(res, f.first);
                    break;
                }
            }

            res = max(res, U[lm]);
        }

        cout << ad + 2 * res << '\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()

vector<int> adj[20][1010];
int A[1010];

bool dfs(int v, int D, int pv = -1){
    if (D == 0) return 1;

    for(auto f : adj[D][v]){
        if (f != pv){
            if (A[f] == D && dfs(f, D-1, v)) return 1;
        }
    }
    return 0;
}

void solve(){
    
    int n, k, m;
    cin >> n >> k >> m;

    vector<array<int, 3>> edg;

    for(int i = 0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        edg.push_back({d, a, b});
        A[a] = max(A[a], d);
        A[b] = max(A[b], d);
    }

    for(auto f : edg){
        int u = f[1], v = f[2];
        int d = f[0];

        if (d + 1 < A[u] || d + 1 < A[v]){
            // ignore
        }
        else{
            adj[d][u].push_back(v);
            adj[d][v].push_back(u);
        }
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if (dfs(i, k)) ans.push_back(i);
    }

    cout << (int)ans.size() << '\n';
    for(auto f : ans) cout <<f << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
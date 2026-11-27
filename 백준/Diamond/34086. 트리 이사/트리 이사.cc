#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define x first
#define y second

vector<int> adj[2020];

int edg[2020][2020];

vector<int> leaf;
void dfs(int v, int pv = -1){
    for(auto f: adj[v]) if(f != pv){
        dfs(f, v);
    }

    if (adj[v].size() == 1) leaf.push_back(v);
}

int ans[2020][2020];

void solve(){
    
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);

    int len = (int)leaf.size();
    int D = (len+ 1) / 2;
    
    for(int i = 1; i <= D; i++){
        int u = leaf[i-1];
        int v = leaf[(i-1 + len / 2)];

        // get path

        vector<int> from(n+1, -1);
        from[u] = u;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int a= q.front(); q.pop();

            for(auto f :adj[a]) if (from[f] == -1){
                from[f] = a;
                q.push(f);
            }
        }

        vector<int> route;
        int cur = v;
        while(cur != u){
            route.push_back(cur);
            cur = from[cur];
        }
        route.push_back(u);
        reverse(all(route));

        // cout <<" Route: ";
        // for(auto f : route) cout << f << ' ';
        // cout << '\n';

        int tn = (int)route.size();

        for(int j = 1; j < tn; j++){
            int tu = route[j-1];
            int tv=  route[j];

            if (edg[tu][tv] == 0 && edg[tv][tu] == 0){
                edg[tu][tv] = i;
                edg[tv][tu] = -i;
            }
        }
    }

    vector<bool> done(n+1);
    done[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int a= q.front(); q.pop();
        for(auto f : adj[a]){
            if (!done[f]){
                for(int j = 0; j < D; j++){
                    ans[f][j] = ans[a][j];
                }
                int val = edg[a][f];
                if (val > 0) ans[f][val-1]++;
                else ans[f][-val - 1]--;

                done[f] = 1;
                q.push(f);
            }
        }
    }

    cout << D << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < D; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[1010], rev[1010];
int vis[1010];
int topo[1010];

void solve(){
    
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a>> b;

        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    memset(vis, -1, sizeof vis);

    vector<pair<int, int>> ans;

    queue<int> q;
    vector<int> tmp;
    for(int i =1; i <= n ;i++){
        if (vis[i] != -1) continue;

        vector<int> vertexSet;
        vis[i] = 0;
        q.push(i);
        while(!q.empty()){
            int a= q.front(); q.pop();
            vertexSet.push_back(a);
            for(auto f : adj[a]) if (vis[f] == -1){
                vis[f] = 0;
                q.push(f);
            }

            for(auto f : rev[a]) if (vis[f] == -1){
                vis[f] = 0;
                q.push(f);
            }
        }

        int sz = (int)vertexSet.size();
        int ansi = -1;

        for (auto target : vertexSet){            
            for(auto f : vertexSet){
                topo[f] = (int)rev[f].size();
                if (f== target) topo[f] = 0;
                if (topo[f] == 0) {
                    q.push(f);
                }
            }

            int tot = 0;
            bool nd = 0;
            while(!q.empty()){
                int a = q.front(); q.pop();
                tot++;

                for(auto f : adj[a]){
                    if (f == target) nd = 1;
                    topo[f]--;
                    if (topo[f] == 0) q.push(f);
                }
            }

            if (tot == sz){
                ansi = target;
                if (!nd) break;
            }
        }

        if (ansi == -1){
            cout << -1 << '\n';
            return;
        }

        int target = ansi;
        tmp.clear();
            
        for(auto f : vertexSet){
            topo[f] = (int)rev[f].size();
            if (f== target) topo[f] = 0;
            if (topo[f] == 0) {
                q.push(f);
                vis[f] = 1;
            }
        }

        bool nd = 0;
        while(!q.empty()){

            int a = q.front(); q.pop();
            tmp.push_back(a);

            for(auto f : adj[a]){
                if (f == target) nd = 1;
                topo[f]--;
                if (topo[f] == 0) q.push(f);
            }
        }

        for(int j = 1; j < sz; j++){
            ans.push_back(mp(tmp[j-1], tmp[j]));
        }
        if(nd){
            ans.push_back(mp(tmp.back(), target));
        }
    }

    cout<< (int)ans.size() << '\n';
    for(auto[a,b]: ans) cout << a<< ' ' << b << '\n';


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
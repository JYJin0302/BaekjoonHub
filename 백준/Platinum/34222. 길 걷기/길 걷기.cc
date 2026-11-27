#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[505050];
array<int, 4> edg[505050];

int topo[505050];
bool done[505050];
ll val1 = 0, val2 = 0;
int s = 0;

vector<int> rec;

void dfs(int a, int pv = -1){

    //cout << "Go dfs: " << a << ' ' << pv << '\n';
    rec.push_back(a);
    for(auto f : adj[a]) {
        if (f == pv) continue;
        int u = edg[f][0];
        int v = edg[f][1];
        int c1 = edg[f][2], c2 = edg[f][3];
        if (u == a) swap(u, v), swap(c1, c2);

        if (done[u]) continue;

        val1 += c2;
        val2 += c1;

        if (u != s) dfs(u, f);
    }
}


void solve() {
 
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m));
    vector<vector<int>> CA(n, vector<int>(m));
    vector<vector<int>> CB(n, vector<int>(m));

    for(int i = 0 ;i <  n;i ++){
        for(int j = 0; j < m-1; j++){
            int x;
            cin >> x;
            A[i][j] = x - 1;
        }
    }
    for(int i = 0 ;i <  n;i ++){
        for(int j = 0; j < m-1; j++){
            int x;
            cin >> x;
            B[i][j] = x - 1;
        }
    }
    for(int i = 0 ;i <  n;i ++){
        for(int j = 0; j < m-1; j++){
            int x;
            cin >> x;
            CA[i][j] = x;
        }
    }
    for(int i = 0 ;i <  n;i ++){
        for(int j = 0; j < m-1; j++){
            int x;
            cin >> x;
            CB[i][j] = x;
        }
    }

    ll ans = 0;
    for(int j = 0; j < m-1; j++){

        for(int i = 0 ;i < n; i++){
            topo[i] = 0;
            done[i] = 0;
            adj[i].clear();
        }

        for(int i = 0; i < n; i++){
            int u = A[i][j], v = B[i][j];
            int c1 = CA[i][j], c2 = CB[i][j];

            topo[u]++;
            topo[v]++;
            edg[i] = {u, v, c1, c2};
            //cout << "EDge made: " << u << ' '<< v << ' ' << c1 << ' ' << c2 << endl;
            adj[u].push_back(i); 
            adj[v].push_back(i);
        }

        queue<int> q;
        for(int i = 0; i< n; i++){
            if(topo[i] == 1){
                done[i] = 1;
                q.push(i);
            }
        }

        ll res = 0;
        while(!q.empty()){
            int a = q.front(); q.pop();
            for(auto f : adj[a]) {
                int u = edg[f][0];
                int v = edg[f][1];
                int c1 = edg[f][2], c2 = edg[f][3];
                if (u == a) swap(u, v), swap(c1, c2);

                if (done[u]) continue;
                
                res += c2;
                topo[u]--;
                if (topo[u] == 1){
                    done[u] = 1;
                    q.push(u);
                }
            }
        }

        for(int i =0 ; i < n; i++){
            if (!done[i] && topo[i] != 2){
                cout << -1 << '\n';
                return;
            }
        }

        for(int i = 0; i < n ;i++){
            if(done[i]) continue;

            val1 = -1, val2 = -1;
            vector<int> nxt;
            for(auto f : adj[i])  {
                
                int u = edg[f][0];
                int v = edg[f][1];
                int c1 = edg[f][2], c2 = edg[f][3];
                if (u == i) swap(u, v), swap(c1, c2);
                if (done[u]) continue;

                nxt.push_back(f);
                if (u == i) val1 = c1, val2 = c2;
            }

            if (val1 != -1) {
                rec.push_back(i);
            }
            else{
                val1 = 0, val2 = 0;
                s = i;
                
                dfs(i, nxt[0]);
            }

            for(auto f : rec) {
                done[f] = 1;
            }
            rec.clear();
            
            res += min(val1, val2);

        }

        ans += res;

       // cout << "STeep: "<< j << " : " << res << '\n';
    }
    cout << ans << '\n';

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
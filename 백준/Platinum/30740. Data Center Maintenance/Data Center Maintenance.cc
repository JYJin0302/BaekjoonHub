#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[101010];

int ord = 0;
int dfsn[101010];
int scc[101010];
int sz[101010];
stack<int> stk;
int dfs(int v){
    dfsn[v] = ++ord;
    int ret = dfsn[v];
    stk.push(v);

    for(auto f : adj[v]){
        if (dfsn[f] == 0){
            ret = min(ret, dfs(f));
        }
        else if (scc[f] == 0){
            ret = min(ret, dfsn[f]);
        }
    }

    if (ret == dfsn[v]){
        //cout << "SCC found: ";
        while(!stk.empty()){
            int a = stk.top();stk.pop();
            sz[v]++;
            scc[a] = v;
            //cout << a<< ' ';
            if(a == v) break;
        }
        //cout << '\n';
    }
    return ret;
}

int H[101010];

void solve(){
    
    int n, m, h;
    cin >> n >> m >> h;
    for(int i = 1; i<= n; i++){
        cin>>H[i];
    }

    while(m--){
        int a, b;
        cin >> a>> b;
        if ((H[a] + 1) % h == H[b]) adj[a].push_back(b);
        if ((H[b] + 1) % h == H[a]) adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if (adj[i].empty()){
            cout<< "1\n" << i << '\n';
            return;
        }
    }


    for(int i = 1; i <= n; i++){
        if(dfsn[i] == 0){
            dfs(i);
        }
    }

    for(int i= 1; i <= n; i++){
        for(auto f: adj[i]){
            int u = scc[i];
            int v = scc[f];
            if(u == v) continue;
            sz[u] = n + 100;
        }
    }

    pair<int, int> ans = mp(n + 100, 0);
    for(int i =1 ; i <= n; i++){
        if (scc[i] == i){
            ans = min(ans, mp(sz[i], i));
        }
    }

    vector<int> res;
    for(int i = 1; i <= n; i++){
        if(scc[i] == ans.y) res.push_back(i);
    }

    cout << (int)res.size() << '\n';
    for(auto f: res) cout << f<< ' ';
    cout << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

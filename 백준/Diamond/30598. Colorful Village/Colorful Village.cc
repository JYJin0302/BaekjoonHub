#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> ans;
int col[202020], p[202020];
vector<int> A[101010];
vector<int> adj[202020], adj2[404040];
int n;

void dfs(int v, int pv = -1){
    for(auto f : adj[v]) if (f != pv){
        p[f] = v;
        dfs(f, v);
    }
}

int ord, sccC;
int rep[404040];
int dfsn[404040];
stack<int> stk;

int dfs2(int v){
    dfsn[v] = ord++;
    int ret = dfsn[v];
    stk.push(v);
    for(auto f : adj2[v]){
        if (dfsn[f] == -1) ret = min(ret, dfs2(f));
        else if (rep[f] == -1) ret = min(ret, dfsn[f]);
    }

    if(ret == dfsn[v]){
        sccC++;
        while(!stk.empty()){
            int a = stk.top(); stk.pop();
            rep[a] = sccC;
            if(a == v) break;
        }
    }
    return ret;
}



void goSolve(int root, int k){

    for(int i = 1; i <= n*2; i++){
        p[i] = -1;
    }
    for(int i = 1; i <= n*4; i++){
        adj2[i].clear();
        rep[i] = -1;
        dfsn[i] = -1;
    }
    
    p[root] = 0;
    dfs(root);

    // valid check    
    for(int i = 1; i <= n; i++){
        int a = A[i][0], b = A[i][1];

        adj2[a+2*n].push_back(b);
        adj2[a].push_back(b+2*n);
        adj2[b+2*n].push_back(a);
        adj2[b].push_back(a+2*n);

        if(p[a] != 0){
            adj2[a].push_back(p[a]);
            adj2[p[a]+2*n].push_back(a+2*n);
        }

        if(p[b] != 0){
            adj2[b].push_back(p[b]);
            adj2[p[b]+2*n].push_back(b+2*n);
        }
    }
    adj2[root + 2*n].push_back(root);
    adj2[k].push_back(k + 2*n);

    sccC = 1;
    ord = 1;
    for(int i = 1; i <= n*4; i++){
        if(dfsn[i] == -1) dfs2(i);
    }

    for(int i = 1; i <= n*2; i++){
        if(rep[i] == rep[i+2*n]) return;
    }
    
    
    for(int i = 1; i <= n; i++){
        int a = A[i][0], b = A[i][1];
        if (rep[a] > rep[a+2*n] && rep[b] < rep[b+2*n]) ans.push_back(b);
        else if (rep[a] < rep[a+2*n] && rep[b] > rep[b+2*n]) ans.push_back(a);
        else assert(0);
    }

}

void solve(){
    
    cin >> n;

    for(int i = 1; i <= n ;i++) A[i].clear();
    for(int i = 1; i <= n*2; i++){
        adj[i].clear();
        cin >> col[i];
        A[col[i]].push_back(i);
    }

    for(int i = 0; i < n*2-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans.clear();

    goSolve(A[1][0], A[1][1]);
    if(ans.empty()) goSolve(A[1][1], A[1][0]);
    
    if(ans.empty()) cout << -1 << '\n';
    else {
        for(auto f : ans) cout << f << ' ';
        cout << '\n';
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc; cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}
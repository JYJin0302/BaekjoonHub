#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

vector<int> adj[200001];
vector<int> A;
ll dep[200001];
pair<int, int> idx[200001];
int n, q;
int p = 1;
void dfs(int v, int pv = -1, ll d = 1){
    idx[v].x = p++;
    dep[v] = d;
    for(auto i : adj[v]) if (i != pv){
        dfs(i, v, d+1);
    }
    idx[v].y = p++;
}

void update(int i, int v){
    while(i <= n*2){
        A[i]+= v;
        i += (i & -i);
    }
}

ll ssum(int i){
    ll r = 0;
    while(i > 0){
        r += A[i];
        i -= (i&-i);
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    
    A = vector<int>(2*n+1);
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        if (x == -1) continue;
        adj[x].push_back(i+1);
        adj[i+1].push_back(x);
    }
    dfs(1);
    
    while(q--){
        
        int t, a, b;
        cin >> t >> a;
        
        int l = idx[a].x;
        int r = idx[a].y;
        
        if (t == 1){
            cin >> b;
            
            update(l, b);
            update(r+1, -b);
        }
        else{
            cout << ssum(l) << '\n';
        }
    }
    
}
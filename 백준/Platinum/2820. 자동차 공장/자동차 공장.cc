#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, sn;
ll o = 1;
vector<ll> tr;

vector<int> adj[500001];

void update(int i, ll v){
    while(i <= sn){
        tr[i] += v;
        i += (i & -i);
    }
}

ll ssum(int i){
    ll res = 0;
    while(i > 0){
        res += tr[i];
        i -= (i & -i);
    }
    return res;
}

vector<pair<int, int>> idx;

void dfs(int v, int pv = 0){
    idx[v].first = o++;
    for(auto i : adj[v]) if (i != pv){
        dfs(i, v);
    }
    idx[v].second = o++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    sn = 1;
    while(sn < n*2) sn *= 2;
    
    tr = vector<ll> (sn+1);
    
    vector<int> A(n+1);
    for(int i =1 ; i <= n; i++) {
        cin >> A[i];
        if (i != 1){
            int x;
            cin >> x;
            
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    
    idx = vector<pair<int, int>>(n+1);
    dfs(1);
    
    while(m--){
        
        char c;
        int a, b;
        cin >> c;
        
        if (c == 'p'){
            cin >> a >> b;
            int l = idx[a].first, r = idx[a].second;
            update(l+1, b);
            update(r, -b);
        }
        else{
            cin >> a;
            cout << ssum(idx[a].first) + A[a] << '\n';
        }
    }
}
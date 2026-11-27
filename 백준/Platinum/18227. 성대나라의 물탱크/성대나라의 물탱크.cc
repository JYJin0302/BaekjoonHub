#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

vector<int> adj[200001];
vector<int> A;
ll dep[200001];
pair<int, int> idx[200001];
int n, c;
int p = 1;
void dfs(int v, int pv = -1, ll d = 1){
    idx[v].x = p++;
    dep[v] = d;
    for(auto i : adj[v]) if (i != pv){
        dfs(i, v, d+1);
    }
    idx[v].y = p++;
}

void update(int i){
    while(i <= n*2){
        A[i]++;
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
    
    cin >> n >> c;
    
    A = vector<int>(2*n+1);
    
    for(int i = 0; i < n -1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(c);
    
    int q;
    cin >> q;
    
    while(q--){
        
        int a, b;
        cin >> a >> b;
        int l = idx[b].x;
        int r = idx[b].y;
        if (a == 1){
            update(l), update(r);
        }
        else{
            cout << (ssum(r) - ssum(l-1)) / 2ll * dep[b] << '\n';
        }
    }
}
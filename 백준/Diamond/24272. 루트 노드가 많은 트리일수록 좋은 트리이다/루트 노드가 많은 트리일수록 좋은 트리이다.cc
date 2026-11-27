#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define all(x) x.begin(), x.end()

struct Node{
    int minVal = 0, minCnt = 0;
    Node(int _v = 0, int _c = 0){
        minVal = _v, minCnt = _c;
    }

    Node operator+(Node o) const{
        if (minVal < o.minVal) return {minVal, minCnt};
        if (minVal > o.minVal) return {o.minVal, o.minCnt};
        return {minVal, minCnt + o.minCnt};
    }

} seg[303030];
int lazy[303030];

void goLazy(int l, int r, int n){
    if (lazy[n]){
        seg[n].minVal += lazy[n];
        if (l != r){
            lazy[n*2]  += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }
}


vector<int> adj[101010];

int o = 1;
int In[101010], Out[101010];
void dfs(int v, int pv = -1){
    In[v] = o++;
    for(auto f: adj[v]) if (f != pv){
        dfs(f, v);
    }
    Out[v] = o;
}


void init(int l, int r, int n){
    if (l == r) {
        seg[n].minCnt = 1;
        return;
    }
    int md = (l+r)>>1;
    init(l, md, n*2);
    init(md+1, r, n*2+1);
    seg[n] = seg[n*2]+ seg[n*2+1];
}


void update(int l, int r, int n, int sl, int sr, int val){
    goLazy(l, r, n);
    if ( l > sr || r < sl) return;
    if (l >= sl && r <= sr) {
        lazy[n] += val;
        goLazy(l, r, n);
        return;
    }
    int md = (l+r)>>1;
    update(l, md, n*2, sl, sr, val);
    update(md+1, r, n*2+1, sl, sr, val);
    seg[n] = seg[n*2] + seg[n*2+1];
}

Node getRes(int l, int r, int n, int sl, int sr){
    goLazy(l ,r, n);
    if (l > sr || r < sl) return Node(121212, 0);
    if(l >= sl && r <= sr) return seg[n];
    int md = (l+r)>>1;
    return getRes(l, md, n*2, sl, sr) + getRes(md+1, r, n*2+1, sl, sr);
}



void solve() { 
    
    int n;
    cin >> n;

    vector<array<int, 3>> edg;

    for(int i = 0; i < n-1; i++){
        int a, b;
        string s;
        cin >> a >> s >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        int c = 0;
        if (s == "--"){
            c = 2;
        }
        else if(s == "->") c = 1;
        else c = 0;

        edg.push_back({a, b, c});
    }

    dfs(1);

    //for(int i = 1; i <= n; i++) cout << In[i] << ' ' << Out[i] << '\n';

    init(1, n, 1);

    vector<int> curVal(n+1);
    for(auto f : edg){
        int a = f[0], b = f[1], c = f[2];
        if (In[a] > In[b]) swap(a, b), c ^= 1;

        if (c >= 2){}
        else if (c == 1){
            update(1, n, 1, In[b], Out[b]-1, 1);
        }
        else{
            update(1, n, 1, In[1], Out[1]-1, 1);
            update(1, n, 1, In[b], Out[b]-1, -1);
        }
        curVal[b] = c;
    }

    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        string s;
        cin >> a>> s >> b;
        if (s == "--"){
            c = 2;
        }
        else if(s == "->") c = 1;
        else c = 0;

        if (In[a] > In[b]) swap(a, b), c ^= 1;

        // curVal remove
        if (curVal[b] >= 2) {}
        else if (curVal[b] == 1){
            update(1, n, 1, In[b], Out[b]-1, -1);
        }
        else{
            update(1, n, 1, In[1], Out[1]-1, -1);
            update(1, n, 1, In[b], Out[b]-1, 1);
        }

        // curVal update
        curVal[b] = c;
        if (curVal[b] >= 2) {}
        else if (curVal[b] == 1){
            update(1, n, 1, In[b], Out[b]-1, 1);
        }
        else{
            update(1, n, 1, In[1], Out[1]-1, 1);
            update(1, n, 1, In[b], Out[b]-1, -1);
        }

        Node res = getRes(1, n, 1, 1, n);

        if (res.minVal == 0) cout << res.minCnt << '\n';
        else cout << 0 << '\n';
    }


    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

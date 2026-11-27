#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[505050];
ll A[505050];
ll B[505050];
int P[505050];

int In[505050];
int Out[505050];
int Rev[505050];

int ord = 0;
void dfs(int v, int pv = -1){
    P[v] = pv;
    In[v] = ++ord;
    Rev[ord] = v;
    for(auto f : adj[v]) if(f != pv){
        B[f] = max(A[f], B[v]);
        dfs(f ,v);
    }
    Out[v] = ord;
}

const ll INF = 1e15;

ll seg[1202020];
ll lazy[1202020];
bool done[1202020];

void init(int l, int r, int n){
    lazy[n] = INF;
    if (l == r){
        int tl = Rev[l];
        seg[n] = A[tl];
        return;
    }
    int md = (l+r)>>1;
    init(l ,md, n*2);
    init(md+1, r, n*2+1);
    seg[n] =seg[n*2] + seg[n*2+1];
}

void goLazy(int l, int r, int n){
    if (lazy[n] != INF){
        done[n] = 1;
        seg[n] = lazy[n] * (r - l + 1);
        if (l != r){
            done[n*2] = 1;
            done[n*2+1] = 1;
            lazy[n*2] = lazy[n];
            lazy[n*2+1] = lazy[n];
        }
        lazy[n] = INF;
    }
}

void update(int l, int r, int n, int sl, int sr, int val){
    goLazy(l, r, n);
    if (l > sr || r < sl) return;
    if (l >=sl && r <= sr){
        lazy[n] = val;
        goLazy(l, r, n);
        return;
    }
    
    int md = (l+r)>>1;
    update(l, md, n*2, sl ,sr, val);
    update(md+1, r, n*2+1, sl, sr, val);
    seg[n] = seg[n*2] + seg[n*2+1];
}

ll getVal(int l, int r, int n, int sl, int sr){
    goLazy(l, r, n);
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr){
        return seg[n];
    }

    int md = (l+r)>>1;
    return getVal(l, md, n*2, sl, sr) + getVal(md+1, r, n*2+1, sl, sr);    
}

int n, q;
int fw[1202020];
void update(int ix ,int val){
    while(ix <= n){
        fw[ix] += val;
        ix += ix & -ix;
    }
}

int getS(int ix){
    int res = 0;
    while(ix){
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

void solve(){
    
    cin >> n >> q;

    for(int i =1; i <= n;i++){
        cin >> A[i];
        B[i] = A[i];
    }

    for(int i =0 ; i< n-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    init(1, n, 1);

    while(q--){
        int t, i;
        cin >> t >> i;

        //cout << "Go qur : " << t << ' ' << i << '\n';
        if(t == 1){
            int l = In[i], r = Out[i];
            if (getS(l) != 0) continue;
            update(1, n, 1, l, r, B[P[i]]);
            update(l, 1);
            update(r+1, -1);
        }
        else{
            int l = In[i], r = Out[i];
            cout << getVal(1, n, 1, l, r) << '\n';
        }
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, m, p;
vector<int> adj[303030];

int L[303030], R[303030];

int tot = 0;
int cnt[303030];

void addNum(int x){
    cnt[x]++;
    if (cnt[x] == 1) tot++;
}

void subNum(int x){
    cnt[x]--;
    if (cnt[x] == 0) tot--;
}

ll seg[1203030];
ll val[303030];
void init(int l, int r, int n){
    if (l == r) {
        seg[n] = val[l];
        return;
    }
    int md = (l+r)>>1;
    init(l, md, n*2);
    init(md+1, r, n*2+1);
    seg[n] = min(seg[n*2], seg[n*2+1]);
}

ll getMin(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return 1e12;
    if (l >= sl && r <= sr) return seg[n];
    int md = (l+r)>>1;
    return min(getMin(l, md, n*2, sl, sr), getMin(md+1, r, n*2+1, sl, sr));
}

void solve(){
    
    cin >> n >> m >> p;


    vector<int> num;
    vector<pair<int, int>> edg;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b>> c;
        num.push_back(c);
        edg.push_back(mp(c, b));
    }
    sort(all(num));
    num.erase(unique(all(num)), num.end());
    for(auto [a,b] : edg){
        int ix = lower_bound(all(num), a) - num.begin();
        adj[ix].push_back(b);
    }
    memset(L, -1, sizeof L);
    memset(R, -1, sizeof R);

    int sn = (int)num.size();


    // cal R
    int r = 0;
    for(int i = 0; i < sn; i++){
        r = max(r, i);
        while(tot != n-1 && r < sn){
            for(auto f: adj[r]) addNum(f);
            r++;
            if (tot == n-1) break;
        }

        if (tot == n-1){
            R[i] = r-1;
        }
        for(auto f : adj[i]) subNum(f);
    }

    int l = sn-1;
    for(int i = sn-1; i >= 0; i--){
        l = min(l, i);
        while(tot != n-1 && l >= 0){
            for(auto f: adj[l]) addNum(f);
            l--;
            if (tot == n-1) break;
        }

        if (tot == n-1){
            L[i] = l+1;
        }
        for(auto f : adj[i]) subNum(f);
    }

    for(int i = 0; i < sn; i++){
        if (R[i] != -1) val[i] = num[R[i]] - num[i];
        else val[i] = 1e12;
    }
    init(0, sn-1, 1);


    int q;
    cin >> q;
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;

        bool ok = 0;
        int ix = lower_bound(all(num), l) - num.begin();
        if(ix < sn && R[ix] != -1){
            int tl = num[ix];
            int tr = num[R[ix]];

            ll cost = 0;
            if(tl < l) cost += l - tl;
            if (tr > r) cost += tr - r;
            if (cost <= k) ok = 1;
        }

        ix = lower_bound(all(num), r + 1) - num.begin() - 1;
        if(ix >= 0 && ix < sn && L[ix] != -1){
            int tl = num[L[ix]];
            int tr = num[ix];

            ll cost = 0;
            if(tl < l) cost += l - tl;
            if (tr > r) cost += tr - r;
            if (cost <= k) ok = 1;
        }


        int tl = -1;
        int lo = 0, hi = sn-1;
        while(lo <= hi){
            int md = (lo + hi)>> 1;
            if (R[md] == -1 || num[R[md]] >= r){
                tl = md;
                hi = md - 1;
            }
            else lo = md +1;
        }

        if (tl == -1 || R[tl] == -1){}
        else{
            int tr = lower_bound(all(num), l) - num.begin() - 1;
            if (tl <= tr){
                ll mv = getMin(0, sn-1, 1, tl, tr);
                if (mv - (r - l) <= k) ok = 1;
            }
        }


        if (ok) cout << "Yes\n";
        else cout << "No\n";


    }
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
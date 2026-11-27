#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


ll seg[1202020];
ll lazy[1202020];

void goLazy(int l, int r, int n){
    if (lazy[n]){
        seg[n] += lazy[n];
        if (l != r){
            lazy[n*2] +=lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

void init(int l, int r, int n){
    seg[n] = (ll)1e18;
    if(l==r)return;
    int md = (l+r)>>1;
    init(l, md, n*2);
    init(md+1,r ,n*2+1);
}

void update(int l, int r, int n, int sl, int sr, ll val){
    goLazy(l, r, n);    

    if (l > sr || r < sl) return;;
    if (l >= sl && r <= sr) {
        lazy[n] += val;
        goLazy(l, r, n);
        return;
    }

    int md= (l+r)>>1;
    update(l, md, n*2, sl, sr, val);
    update(md+1,r, n*2+1, sl, sr, val);
    seg[n] = min(seg[n*2], seg[n*2+1]);
}

ll getM(int l, int r, int n, int sl, int sr){
    goLazy(l, r, n);
    if (l > sr || r< sl) return (ll)1e18;
    if (l>= sl && r <= sr) return seg[n];

    int md = (l+r)>>1;
    return min(getM(l, md, n*2, sl, sr), getM(md+1, r, n*2+1, sl, sr));
}


void solve(){
    
    int n; cin >> n;

    vector<ll> V(n+1);
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        V[i] = x;
    }

    vector<pair<ll, ll>> A;
    for(int i = 1; i <= n;i++){
        ll x;
        cin >> x;
        A.push_back(mp(x, i));
    }
    sort(all(A));

    ll val = 0;
    for(int i = 1; i <= n; i++){
        val += V[i];
        update(1, n, 1, i, i, val);
    }


    int ans = 0;
    vector<int> res;
    for(auto[a,b]: A){
        if (getM(1, n, 1, b, n) >= a){
            ans++;
            res.push_back(b);
            update(1, n, 1, b, n, -a);
        }
    }

    sort(all(res));
    cout << ans << '\n';
    for(auto f : res) cout << f<< ' ';
    cout << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

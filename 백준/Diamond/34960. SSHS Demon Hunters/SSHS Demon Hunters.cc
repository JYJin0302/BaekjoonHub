#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


vector<int> L[101010];

int lazy[303030];
int seg[303030]; // max

void goLazy(int l, int r, int n){
    if (lazy[n]){
        if(l != r){
            lazy[n*2] += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        seg[n] += lazy[n];
        lazy[n] = 0;
    }
}

void init(int l, int r, int n){
    lazy[n] = 0;
    seg[n] = 0;
    if(l == r) return;
    int md=  (l+r)>>1;
    init(l, md, n*2);
    init(md+1,r ,n*2+1);
}

void update(int l, int r, int n, int sl, int sr, int val){
    goLazy(l, r, n);
    if(l > sr || r < sl) return;
    if (l >= sl&& r <= sr){
        lazy[n] = val;
        goLazy(l, r, n);
        return;
    }
    int md = (l+r)>>1;
    update(l, md, n*2, sl, sr, val);
    update(md+1,r, n*2+1, sl, sr,val);
    seg[n] = max(seg[n*2], seg[n*2+1]);
}

int getMax(int l, int r, int n, int sl, int sr){
    goLazy(l, r, n);
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];
    int md = (l+r)>>1;
    return max(getMax(l, md, n*2, sl, sr), getMax(md+1,r ,n*2+1, sl, sr));
}


void solve(){
    
    int n;
    cin >> n;
    vector<pair<ll, ll>> A;
    vector<ll> num;
    for(int i =0; i < n; i++){
        ll x, y;
        cin >> x>> y;

        ll L = max(1ll, y - x + 1);
        ll R = min((ll)1e18, y + x - 1);
        A.push_back(mp(L, R));
        num.push_back(R);
    }
    
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    int tn = (int)num.size();
    sort(all(A));

    vector<pair<int, int>> rec;
    for(auto&[a,b]:A){
        a = lower_bound(all(num), a) - num.begin() + 1;
        b = lower_bound(all(num), b) - num.begin() + 1;
        rec.push_back(mp(a, 1));
        rec.push_back(mp(b+1, -1));
        L[b].push_back(a);
        L[a-1].push_back(-1);
    }


    // cout << "RES: \n";
    // for(auto[a,b]: A) cout << a<< ' '<< b<< '\n';

    vector<int> cnt(tn + 2);
    sort(all(rec));
    int ix = 0;
    int val = 0;

    int pre = 0;
    while(ix < (int)rec.size()){
        int nx = ix;
        while(pre < rec[ix].x){
            cnt[pre++] = val;
        }

        while(nx < (int)rec.size() && rec[ix].x == rec[nx].x) {
            val += rec[nx].y;
            nx++;
        }

        cnt[rec[ix].x] = val;
        ix = nx;
    }

    vector<int> dp(tn+2);
    dp = cnt;
    vector<int> ndp(tn+2);

    init(1, tn, 1);
    // setup
    for(int i= 1; i <= tn; i++){
        update(1, tn, 1, i, i, dp[i]);
    }

    int ans = 0;
    for(auto f : dp) ans = max(ans, f);

    // for(auto f: dp) cout << f<< ' ';
    // cout << '\n';

    for(int i = tn; i >= 1; i--){
        for(auto l : L[i]){
            if (l > 0) update(1, tn, 1, 1, l-1, 1);
            else update(1, tn, 1, 1, i, -1);
        }

        int v = getMax(1, tn, 1, 1, i-1);
        ndp[i] = v;
    }

    for(auto f : ndp) ans = max(ans, f);

    swap(dp, ndp);
    // for(auto f: dp) cout << f<< ' ';
    // cout << '\n';


    init(1, tn, 1);
    // setup
    for(int i= 1; i <= tn; i++){
        update(1, tn, 1, i, i, dp[i]);
    }
    
    for(int i = tn; i >= 1; i--){
        for(auto l : L[i]){
            if (l > 0) update(1, tn, 1, 1, l-1, 1);
            else update(1, tn, 1, 1, i, -1);
        }

        int v = getMax(1, tn, 1, 1, i-1);
        ndp[i] = v;
    }

    // for(auto f: ndp) cout << f<< ' ';
    // cout << '\n';

    for(auto f : ndp) ans = max(ans, f);

    cout << n - ans << '\n';


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

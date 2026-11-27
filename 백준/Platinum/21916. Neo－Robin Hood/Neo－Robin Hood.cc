#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

pair<ll, ll> segL[303030], segR[303030];
// sum, cnt

void update(int l, int r, int n, int u, ll val, int dif, pair<ll,ll> seg[]){
    if (l > u || r < u) return;
    if (l == u && r == u){
        seg[n].y += dif;
        seg[n].x += val * dif;
        return;
    }
    int md = (l+r)>>1;
    update(l,md, n*2, u, val, dif, seg);
    update(md+1, r, n*2+1, u, val, dif, seg);
    seg[n].x = seg[n*2].x + seg[n*2+1].x;
    seg[n].y = seg[n*2].y + seg[n*2+1].y;
}

ll getS(int l, int r, int n, int k, pair<ll, ll> seg[]){
    if (k == 0) return 0;
    //cout << "Go get s: " << l << ' '<< r << ' ' << n << ' ' << k << endl;
    if (seg[n].y <= k){
        return seg[n].x;
    }
    if (l == r){
        ll val = seg[n].x / seg[n].y;
        return val * k;
    }
    ll ret = 0;
    int md =(l+r)>>1;
    if (seg[n*2].y<=k){
        k -= seg[n*2].y;
        ret += seg[n*2].x;
        ret += getS(md+1,r, n*2+1, k, seg);
    }else{
        ret = getS(l, md, n*2, k, seg);
    }
    return ret;
}

void solve(){
    
    int n;
    cin >> n;
    vector<pair<ll, ll>> A(n);
    for(auto& i : A) cin >> i.x;
    for(auto& i : A) cin >> i.y;
    sort(all(A));
    reverse(all(A));
    //for(auto[a,b]: A) cout << a << ' '<< b <<" || ";
    //cout << endl;

    vector<ll> num;
    for(int i = 0; i < n;i++) num.push_back(A[i].x + A[i].y);
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    vector<ll> num2;
    for(int i = 0; i < n;i++) num2.push_back(A[i].y);
    sort(all(num2));
    num2.erase(unique(all(num2)), num2.end());

    for(int i = 0;i < n; i++){
        int ix = lower_bound(all(num2), A[i].y) - num2.begin();
        update(0, n-1, 1, ix, num2[ix], 1, segR);
    }


    int L = 1, R = n / 2;
    int ans = 0;
    while(L <= R){  
        int ix = 0;
        int md = (L+R)>>1;
        ll valL = 0;

        bool ok = 0;
        while(ix < 2 * md){

            //cout << "go ix: "<< ix << endl;
            int iter;
            iter = lower_bound(all(num2), A[ix].y) - num2.begin();
            update(0, n-1, 1, iter, num2[iter], -1, segR);
            iter = lower_bound(all(num), A[ix].x + A[ix].y) - num.begin();
            update(0, n-1, 1, iter, num[iter], 1, segL);
            valL += A[ix].x;
            ix++;

            // cout << "Go ans: " << endl;
            if (ix >= md){
                int cntL = ix - md;
                int cntR = md - cntL;
                ll v1 = getS(0, n-1, 1, cntL, segL);
                ll v2 = getS(0, n-1, 1, cntR, segR);
                // cout << v1 << ' ' << v2 << endl;

                if (valL - v1 - v2 >= 0){
                    //cout << "Found: " << cur << endl;
                    ok = 1;
                    break;
                }
            }
        }

        // rollback
        for(int i = 0; i < ix; i++){
            int iter;
            iter = lower_bound(all(num2), A[i].y) - num2.begin();
            update(0, n-1, 1, iter, num2[iter], +1, segR);
            iter = lower_bound(all(num), A[i].x + A[i].y) - num.begin();
            update(0, n-1, 1, iter, num[iter], -1, segL);
        }

        if (ok){
            ans = md;
            L = md + 1;
        }
        else R = md - 1;
    }
    cout << ans << '\n';
    

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
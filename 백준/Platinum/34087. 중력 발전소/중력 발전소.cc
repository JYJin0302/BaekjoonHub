#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define x first
#define y second

vector<ll> seg[303030], segS[303030];
ll B[101010];

void init(int l, int r, int n){
    if(l == r){
        seg[n].push_back(B[l]);
        segS[n].push_back(B[l]);
        return;
    }

    int md = (l+r)>>1;
    init(l, md, n*2);
    init(md+1, r, n*2+1);

    int lx = 0, rx = 0;
    while(lx < (int)seg[n*2].size() && rx < (int)seg[n*2+1].size()){
        if (seg[n*2][lx] < seg[n*2+1][rx]){
            seg[n].push_back(seg[n*2][lx++]);
        }
        else{
            seg[n].push_back(seg[n*2+1][rx++]);
        }
    }
    while(lx < (int)seg[n*2].size()){
        seg[n].push_back(seg[n*2][lx++]);
    }
    while(rx < (int)seg[n*2+1].size()){
        seg[n].push_back(seg[n*2+1][rx++]);
    }

    ll val = 0;
    for(auto f: seg[n]){
        val += f;
        segS[n].push_back(val);
    }

    //cout << "Seg: "<< n << " || ";
    //for(auto f : seg[n]) cout << f<< ' ';
    //cout << '\n';
}

int getCnt(int l, int r, int n, int sl, int sr, ll val){ // val 이상인 것의 개수
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr){
        int ix = lower_bound(all(seg[n]), val) - seg[n].begin();
        return (int)seg[n].size() - ix;
    }
    int md = (l+r)>>1;
    return getCnt(l, md, n*2, sl, sr, val) + getCnt(md+1, r, n*2+1, sl, sr, val);
}

pair<ll, ll> getRes(int l, int r, int n, int sl, int sr, ll val){
    if (l > sr || r < sl) return mp(0, 0);
    if(l >= sl && r <= sr){
        int ix = lower_bound(all(seg[n]), val) - seg[n].begin();
        ll res = segS[n].back();
        if (ix) res -= segS[n][ix-1];
        return mp(res, (int)segS[n].size() - ix);
    }
    int md = (l+r)>>1;
    pair<ll, ll> p1 = getRes(l, md, n*2, sl, sr, val), p2 = getRes(md+1, r, n*2+1, sl, sr, val);
    return mp(p1.x + p2.x, p1.y + p2.y);
}

void solve(){
    
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> A(n);
    for(auto& i : A) cin >> i;

    for(int i = 0; i < n; i++){
        B[i+1] = A[i] - k + B[i];
    }

    //for(int i = 0; i <= n; i++) cout << B[i]<< ' ';
    //cout << '\n';
    init(0, n, 1);

    ll L = 1, R = 1e9 + 10, ans = 1, ansCnt = 0;

    while(L <= R){
        ll md = (L+R)>>1;

        ll cnt = 0;
        for(int i = 0; i < n; i++){
           // cout << "Go Qur: " << i+1 << ' ' << n << " | " << md - B[i] << " => " << getCnt(0, n, 1, i+1, n, md + B[i]) << '\n';
            cnt += getCnt(0, n, 1, i+1, n, md + B[i]);
        }

        //cout << "Que: " << md << ' ' << cnt << '\n';

        if(cnt <= m){
            ans = md;
            ansCnt = cnt;
            R = md - 1;
        }
        else L = md + 1;
    }

   // cout << ans << ' ' << ansCnt << '\n';

    ll ret = (m - ansCnt) * (ans - 1);
    for(int i = 0; i < n ;i++){
        pair<ll, ll> tmp = getRes(0, n, 1, i+1, n, B[i] + ans);
        ret += tmp.x - tmp.y * B[i];
        //cout << "Add: " << tmp.x << ' ' << tmp.y << '\n';
    }
    for(auto f : A) ret += f;

    cout << ret << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

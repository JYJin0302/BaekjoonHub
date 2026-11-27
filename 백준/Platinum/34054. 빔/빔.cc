#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2){
    return p1.x + p1.y < p2.x + p2.y;
}
bool cmp2(pair<pair<ll, ll>, int> p1, pair<pair<ll, ll>, int> p2){
    return p1.x.x + p1.x.y < p2.x.x + p2.x.y;
}

bool cmp3(pair<ll, ll> p1, pair<ll, ll> p2){
    return p1.y < p2.y;
}
bool cmp4(pair<ll, ll> p1, pair<ll, ll> p2){
    return p1.x > p2.x;
}

void solve(){
    
    int n, q;
    cin >> n >> q;

    vector<pair<ll, ll>> A(n);
    for(auto&[a,b]: A) cin >> a >> b;

    vector<pair<pair<ll, ll>, int>> qur;
    for(int i = 0 ;i < q; i++){
        int a, b;
        cin >> a>> b;
        qur.push_back(mp(mp(a, b), i));
    }

    sort(all(A), cmp);
    sort(all(qur), cmp2);

    vector<ll> len(n);
    for(int i = 0;i < n; i++){
        len[i] = A[i].y - A[i].x;
        if (i)len[i] += len[i-1];
    }

    vector<ll> sL(n);
    for(int i =0 ; i < n;i++){
        sL[i] = A[i].y * (A[i].y - A[i].x);
        if(i) sL[i] += sL[i-1];
    }

    vector<ll> sR(n);
    for(int i = 0; i < n; i++){
        sR[i] = A[i].x * (A[i].y - A[i].x);
        if (i) sR[i] += sR[i-1];
    }

    vector<pair<ll, ll>> tL = A;
    vector<pair<ll, ll>> tR = A;
    sort(all(tL), cmp3);
    sort(all(tR), cmp4);

    vector<ll> tLLen(n), tRLen(n);
    for(int i =0 ; i < n;i ++){
        tLLen[i] = tL[i].y - tL[i].x + (i ? tLLen[i-1]: 0);
        tRLen[i] = tR[i].y - tR[i].x + (i ? tRLen[i-1]: 0);
    }
    vector<ll> stL(n), stR(n);
    for(int i =0  ; i < n; i++){
        stL[i] = tL[i].y * (tL[i].y - tL[i].x);
        if (i) stL[i] += stL[i-1];
    }
    for(int i = 0 ; i < n; i++){
        stR[i] = tR[i].x * (tR[i].y - tR[i].x);
        if (i) stR[i] += stR[i-1];
    }

    vector<ll> ans(q);
    int ix = 0;
    for(auto f : qur){
        while(ix < n && A[ix].x + A[ix].y <= f.x.x + f.x.y) ix++;

        // 0 ~ ix-1 : left
        // ix ~ n-1 : right

        ll val = 0;
        if (ix) val += sL[ix-1] - f.x.x * len[ix-1];


        val += f.x.y * (len[n-1] - (ix ? len[ix-1] : 0));
        val -= sR[n-1] - (ix ? sR[ix-1] : 0);

        // redunt 제거

        int ix = -1;
        int l = 0, r = n-1;
        while(l <= r){
            int md = (l+r)>>1;
            if (tL[md].y <= f.x.x) {
                ix = md;
                l = md + 1;
            }
            else r = md - 1;
        }

        if (ix != -1){
            val += tLLen[ix] * f.x.x;
            val -= stL[ix];
        }

        ix = -1;
        l = 0, r = n-1;
        while(l <= r){
            int md = (l+r)>>1;
            if (tR[md].x >= f.x.y) {
                ix = md;
                l = md + 1;
            }
            else r = md - 1;
        }

        if (ix != -1){
            val -= tRLen[ix] * f.x.y;
            val += stR[ix];
        }

        ans[f.y] = val;
    }

    for(auto f : ans) cout << f*2 << '\n';
    cout << '\n';

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


int seg[1202020];
int lazy[1202020];

void goLazy(int l, int r, int n){
    if (lazy[n] != -1){
        seg[n] = lazy[n];
        if (l != r){
            lazy[n*2] = lazy[n];
            lazy[n*2+1] = lazy[n];
        }
        lazy[n] = -1;
    }
}

void update(int l, int r, int n, int ul, int ur, int val){
    goLazy(l, r, n);
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur){
        lazy[n] = val;
        goLazy(l ,r, n);
        return;
    }

    int md = (l+r)>>1;
    update(l, md, n*2, ul, ur, val);
    update(md+1, r, n*2+1, ul, ur, val);
}

int getVal(int l, int r, int n, int ix){
    goLazy(l, r, n);
    if (l > ix || r < ix) return -1;
    if (l == ix && r == ix) return seg[n];

    int md = (l+r)>>1;
    int v1 = getVal(l , md, n*2, ix);
    if (v1 != -1) return v1;
    return getVal(md+1, r, n*2+1, ix);
}


void solve(){
    
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    memset(lazy, -1, sizeof lazy);
    deque<pair<int, int>> dq;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        dq.push_back(mp(x, 1));
    }

    int tlen = min(n, m);
    int tx = 0;
    while(tlen){
        auto[a,b] = dq.front(); dq.pop_front();

        int mn = min(b, tlen);
        b -= mn, tlen -= mn;

        update(0, m-1, 1, tx, tx + mn - 1, a);
        tx += mn;
        if (b) dq.push_front(mp(a, b));
    }

    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r;
            cin >> l >> r;
            l--, r--;

            int len = r - l + 1;
            int cur = l;
            while(len && !dq.empty()){
                auto [a,b] = dq.front(); dq.pop_front();
                int mn = min(b, len);
                len -= mn;
                b -= mn;

                if (b) dq.push_front(mp(a, b));

                update(0, m-1, 1, cur, cur + mn - 1, a);
                cur += mn;
            }

            if (cur <= r){
                update(0, m-1, 1, cur, r, 0);
            }
        }
        else if (t == 2){
            int ix;
            cin >> ix;
            ix--;

            cout << getVal(0, m-1, 1, ix) << ' ';
        }
        else if (t == 3){
            int p, q;
            cin >> p >> q;
            dq.push_back(mp(p, q));
        }
        else if (t == 4){
            ll len;
            cin >> len;

            while(len){
                auto[a,b] = dq.front(); dq.pop_front();
                ll mn = min(len, (ll)b);
                b -= mn;
                len -= mn;
                if (b) dq.push_front(mp(a, b));
            }
        }
    }

    cout << '\n';
    for(int i = 0; i < m; i++){
        cout << getVal(0, m-1, 1, i) << ' ';
    }
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

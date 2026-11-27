#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int maxN = 100010;
pair<ll, ll> seg[555050];

void update(int l, int r, int n, int u, int val){
    if (l > u || r < u) return;
    if (l == u && r == u){
        seg[n].y += val;
        seg[n].x = u * seg[n].y;
        return;
    }

    int md  = (l+r)>>1;
    update(l ,md, n*2, u, val);
    update(md+1, r, n*2+1, u, val);
    seg[n] = mp(seg[n*2].x + seg[n*2+1].x, seg[n*2].y + seg[n*2+1].y);
}

ll getAns(int l, int r, int n, ll T){
    if (seg[n].x <= T){
        return seg[n].y;
    }
    if (l == r){
        return min(T / l, seg[n].y);
    }

    int md = (l+r)>>1;
    if (seg[n*2].x <= T){
        T -= seg[n*2].x;
        return seg[n*2].y + getAns(md+1, r, n*2 + 1, T);
    }
    return getAns(l ,md, n*2, T);
}

void solve(){
    
    int n, q;
    cin >> n >> q;

    vector<int> T(n+201010);
    for(int i = 1; i <= n; i++) {
        cin >> T[i];
        update(1, maxN, 1, T[i], 1);
    }

    int tdx = n;

    while(q--){
        int t;
        cin >> t;

        if (t == 1){
            int x, v;
            cin >> x >> v;
            update(1, maxN, 1, T[x], -1);
            T[x] = v;
            update(1, maxN, 1, T[x], 1);
        }
        else if (t == 2){
            ll x;
            cin >> x;
            cout << getAns(1, maxN, 1, x) << '\n';
        }
        else{
            int v;
            cin >> v;
            T[++tdx] = v;
            update(1, maxN, 1, v, 1);
        }

    }

    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}
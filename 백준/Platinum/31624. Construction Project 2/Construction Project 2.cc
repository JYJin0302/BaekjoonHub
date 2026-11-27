#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define all(x) x.begin(), x.end()

vector<pair<ll, ll>> adj[202020];

ll distL[202020], distR[202020];

void solve() { 
    
    int n, m;
    cin >> n >> m;

    ll s, t, q, k;
    cin >> s >> t >> q >> k;

    for(int i =0 ; i< m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    set<pair<ll, ll>> st;
    memset(distL, -1, sizeof distL);
    st.insert(mp(0, s));
    while(!st.empty()){
        auto[a,b] = *st.begin();
        st.erase(st.begin());

        if (distL[b] != -1) continue;
        distL[b] = a;

        for(auto[u,v] : adj[b]){
            if (distL[u] == -1){
                st.insert(mp(a + v, u));
            }
        }
    }

    memset(distR, -1, sizeof distR);
    st.insert(mp(0, t));
    while(!st.empty()){
        auto[a,b] = *st.begin();
        st.erase(st.begin());

        if (distR[b] != -1) continue;
        distR[b] = a;

        for(auto[u,v] : adj[b]){
            if (distR[u] == -1){
                st.insert(mp(a + v, u));
            }
        }
    }

    if (distL[t] != -1 && distL[t] <= k){
        ll res = 1ll * n * (n-1) / 2;
        cout << res << '\n';
        return;
    }

    vector<ll> L, R;
    for(int i = 1; i <= n; i++){
        if (distL[i] != -1) L.push_back(distL[i]);
        if (distR[i] != -1) R.push_back(distR[i]);
    }

    sort(all(L));
    sort(all(R));
    ll ans = 0;
    for(auto f : L){
        int ix = lower_bound(all(R), k - q - f + 1) - R.begin();
        ans += ix;
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

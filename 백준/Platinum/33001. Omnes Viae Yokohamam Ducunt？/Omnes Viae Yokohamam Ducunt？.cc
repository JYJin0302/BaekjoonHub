#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<int,int> pi;

ll p[101010];
vector<pair<ll, ll>> adj[101010];
ll dist[101010];

void solve(){
    
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> p[i];

    for(int i =0 ; i < m; i++){
        ll a, b, c;
        cin >> a >> b>> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    memset(dist, -1, sizeof dist);
    set<pair<ll, ll>> st;
    st.insert(mp(0, 1));
    while(!st.empty()){
        auto[a,b] = *st.begin();
        st.erase(st.begin());

        if(dist[b] != -1) continue;
        dist[b] = a;

        for(auto[u, v] : adj[b]){
            if (dist[u] != -1) continue;
            st.insert(mp(a + v, u));
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += 1ll * dist[i] * p[i];
    }
    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<pair<ll, ll>> adj[2020];
int C[2020];

ll dist[2020][2020];

void solve() {
    
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp( b, c));
    }

    for(int i = 1; i <= n; i++) cin >> C[i];

    ll A, B;
    cin >> A >> B;

    memset(dist, -1, sizeof dist);
    set<pair<ll, ll>> st;

    for(int i = 1; i <= n; i++){
        if (!C[i]){
            st.insert(mp(0, i));
            while(!st.empty()){
                auto f = *st.begin(); st.erase(st.begin());

                if(dist[i][f.y] != -1) continue;
                dist[i][f.y] = f.x;

                for(auto [u,v] : adj[f.y]){
                    if (dist[i][u] == -1){
                        st.insert(mp(f.x + v, u));
                    }
                }
            }
        }
    }

    queue<int> q, tq;
    q.push(1);

    vector<bool> vis(n+1);
    vis[1] = 1;
    ll cnt = 0;
    while(1){
        ll ans = -1;
        while(!q.empty()){
            auto f = q.front() ;q.pop();
            if (dist[f][n] != -1 && dist[f][n] <= A){
                if (ans == -1 || ans > dist[f][n]) ans = dist[f][n];
            }

            for(int i = 1; i <= n;i++){
                if(!vis[i] && !C[i] && dist[f][i] != -1 && dist[f][i] <= A ){
                    vis[i] = 1;
                    tq.push(i);
                }
            }
        }
        if(ans != -1){
            cout << cnt * (A + B) + ans << '\n';
            return;
        }
        cnt++;

        if (tq.empty()) break;
        swap(q, tq);
    }

    cout << -1 << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
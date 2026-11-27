#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
vector<pair<ll, ll>> adj[101010];
ll dist[101010], dist2[101010];
int from[101010];
int G[101010];
 
void setDist(int s){
    memset(dist, -1, sizeof dist);
    dist[s] = 0;
    from[s] = s;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int a= q.front(); q.pop();
        for(auto[b, c] : adj[a]){
            if(dist[b] == -1){
                dist[b] = dist[a] + c;
                from[b] = a;
                q.push(b);
            }
        }
    }
}
 
bool isD[101010];
 
int setGroup(int x){
    if (isD[x]) from[x] = x;
    else from[x] = setGroup(from[x]);
    return G[x] = from[x];
}
 
void solve() {
    
    int n;
    cin >> n;
    for(int i =0;i < n-1; i++){
        ll a, b, c;
        cin >>a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }
 
    setDist(1);
    int dia1 = 1;
    for(int i = 1; i <= n; i++){
        if (dist[i] > dist[dia1]) dia1 = i;
    }
 
    setDist(dia1);
    int dia2 = 1;
    for(int i = 1; i <= n; i++){
        if (dist[i] > dist[dia2]) dia2 = i;
    }
 
   // cout << "Diameter: " << dia1 << ' ' << dia2 << '\n';
 
    vector<int> route;
    int cur = dia2;
    while(cur != dia1){
        route.push_back(cur);
        isD[cur] = 1;
        cur = from[cur];
    }
    route.push_back(cur);
    isD[cur] = 1;
    reverse(all(route));
 
    for(int i = 1; i <= n; i++){
        setGroup(i);
        dist2[G[i]] = max(dist2[G[i]], dist[i]);
    }
 
 
    for(int i = 1; i <= n; i++){
        if (G[i] == i) dist2[i] -= dist[i];
    }
 
    int D = (int) route.size(); 
    vector<ll> dpL(D), dpR(D);// L[i] : dia1 ~ i, R[i] = i ~ dia2
    vector<int> Ddx(n+1, -1);
    for(int i = 0; i < D; i++){
        Ddx[route[i]] = i;
    }
 
    // for(auto f: route) cout <<f << ' ';
    // cout << '\n';
    // for(auto f : route) cout << dist[f] << ' ';
    // cout << '\n';
    // for(auto f : route) cout << dist2[f] << ' ';
    // cout << '\n';
 
    // dpL
    int pos = 0;
    set<pair<ll, ll>, greater<pair<ll, ll>>> st;
    for(int i = 1; i < D; i++){
        st.insert(mp(dist[route[i]] + dist2[route[i]], i));
        ll d1 = dist[route[pos]];
        ll d2 = (*st.begin()).x - d1;
        dpL[i] = max(d1, d2);
 
        while(pos < i){
            assert(!st.empty());
            ll d1 = dist[route[pos+1]];
            ll d2 = (*st.begin()).x - d1;
            if (dpL[i] >= max(d1, d2)){
                dpL[i] = max(d1, d2);
                pos++;
                st.erase(st.find(mp(dist[route[pos]] + dist2[route[pos]], pos)));
            }
            else break;
        }
    }
 
    // cout << "DPL : ";
    // for(auto f :dpL) cout <<f << ' ';
    // cout << '\n';
    // ok
 
    // Dpr
    pos = D-1;
    st.clear();
    for(int i = D-2; i >= 0; i--){
        st.insert(mp(dist[dia2] - dist[route[i]] + dist2[route[i]], i));
        ll d1 = dist[dia2] - dist[route[pos]];
        ll d2 = (*st.begin()).x - d1;
        dpR[i] = max(d1, d2);
 
        while(pos > i){
            assert(!st.empty());
            ll d1 = dist[dia2] - dist[route[pos-1]];
            ll d2 = (*st.begin()).x - d1;
            if (dpR[i] >= max(d1, d2)){
                dpR[i] = max(d1, d2);
                pos--;
                st.erase(st.find(mp(dist[dia2] - dist[route[pos]] + dist2[route[pos]], pos)));
            }
            else break;
        }
    }
 
    st.clear();
    // cout << "DPR : ";
    // for(auto f :dpR) cout <<f << ' ';
    // cout << '\n';
    
    vector<ll> ndL(D), ndR(D);
    for(int i =0 ; i < D; i++){
        ndL[i] = dist[route[i]] + dist2[route[i]];
        if (i) ndL[i] = max(ndL[i] ,ndL[i-1]);
    }
    for(int i = D-1; i >= 0 ;i--){
        ndR[i] = dist[dia2] - dist[route[i]] + dist2[route[i]];
        if (i != D-1) ndR[i] = max(ndR[i], ndR[i+1]);
    }
 
    vector<ll> ans(n+1, dpL[D-1]);
    for(int i = 1; i <= n; i++){
 
        int gx = Ddx[G[i]];
        assert(gx != -1);
        ll td1 = dist[i]; // connect left: use DpR
        ll td2 = dpR[gx];
        
        int l = gx, r = D-1;
        ans[i] = min(ans[i], max(td1, td2));
 
        while(l <= r){
            int md = (l+r)>>1;
 
            ll d1 = max(dist[i], ndL[md] - dist[route[gx]] + dist[i] - dist[route[gx]]);
            ll d2 = (md == D-1 ? 0 : dpR[md+1]);
 
            ans[i] = min(ans[i], max(d1, d2));
            if (d1 <= d2){
                l = md + 1;
            }
            else r = md - 1;
        }
        
 
        td1 = dist[dia2] - dist[G[i]] + dist[i] - dist[G[i]]; // connect right, use dpL
        td2 = dpL[gx];
        l = 0, r = gx;
 
        ans[i] = min(ans[i] ,max(td1, td2));
        while(l <= r){
            int md = (l+r)>>1;
 
            ll d1 = (md ? dpL[md-1] : 0);
            ll d2 = max(td1, ndR[md] - (dist[dia2] - dist[G[i]]) + dist[i] - dist[G[i]]);
 
            ans[i] = min(ans[i], max(d1, d2));
            if (d1 <= d2){
                l = md + 1;
            }
            else r = md - 1;
        }
    }
 
    for(int i =1 ; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
 
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

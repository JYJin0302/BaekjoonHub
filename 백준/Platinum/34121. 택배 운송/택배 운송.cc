#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<pair<ll, ll>> adj[202020];
ll dist[202020];
int from[202020];
bool inD[202020];

void dfs(int v, int pv = -1){
    for(auto [a,b] : adj[v]) if (a != pv){
        dist[a] = dist[v] + b;
        from[a] = v;
        dfs(a, v);
    }
}

int setG(int x){
    if (inD[x]) return from[x] = x;
    return from[x] = setG(from[x]);
}

int lazy[1206060];
int seg[1206060];
void update(int l, int r, int n, int sl, int sr, int val){
    if (l > sr || r < sl) return;
    if (l >= sl && r <= sr){
        lazy[n] += val;
    }
    else{
        int md = (l+r)>>1;
        update(l ,md ,n*2, sl, sr, val);
        update(md+1 ,r, n*2+1, sl, sr, val);
    }

    if (lazy[n]) seg[n] = r - l + 1;
    else{
        seg[n] = 0;
        if (l != r) seg[n] = seg[n*2] + seg[n*2+1];
    }
}

void solve() {

    int n ,q;
    cin >> n >> q;
    for(int i = 0; i < n -1; i++){
        ll a, b, c;
        cin >> a>> b >> c;
        adj[a].push_back(mp( b, c));
        adj[b].push_back(mp(a, c));
    }

    dist[1] = 0;
    dfs(1);

    vector<int> route;
    int cur = n;
    while(cur != 1){
        route.push_back(cur);
        cur = from[cur];
    }
    route.push_back(1);
    reverse(all(route));

    int sn = (int)route.size();

    vector<ll> num;
    num.push_back(0);
    num.push_back(dist[n]);

    for(auto f : route) inD[f] = 1;

    for(int i = 1; i <= n; i++) setG(i);


    vector<pair<ll, ll>> qur(q+1);
    for(int i = 1; i <= q; i++){
        int t;
        cin >> t;
        if (t == 1){
            ll a, b;
            cin >> a>> b;

            ll dif = dist[a] - dist[from[a]];
            if (b <= dif) {
                qur[i] = mp(0, 0);
            }
            else{
                b -= dif;
                a = from[a];

                ll l = max(0ll, dist[a] - b);
                ll r = min(dist[n], dist[a] + b);
                qur[i] = mp(l, r);
                num.push_back(l);
                num.push_back(r);
                //update(0, sn-1, 1, l, r-1, 1);
            }
            //cout << qur[i].x << ' ' << qur[i].y << '\n';

        }
        else{
            // erase
            int x;
            cin >> x;
            qur[i] = mp(-1, x);
        }
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());
    int tn = (int)num.size();

    for(int i = 1; i <= q; i++){
        if(qur[i].x == -1){
            int x = qur[i].y;
            auto[li, ri] = qur[x];
            update(0, tn- 1, 1, li, ri-1, -1);
        }
        else{
            auto[l, r] = qur[i];

            int li = lower_bound(all(num), l) - num.begin();
            int ri = lower_bound(all(num), r) - num.begin();
            qur[i] = mp(li, ri);
            update(0, tn- 1, 1, li, ri-1, 1);
        }

        if(seg[1] == tn-1) cout << "YES\n";
        else cout << "NO\n";
    }

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
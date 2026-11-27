#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ld long double
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

struct P{
    int x, y;
    P(int _x = 0, int _y = 0){
        x = _x, y = _y;
    }

    bool operator<(const P& o) const {
        return mp(x, y) < mp(o.x, o.y);
    }
    bool operator==(const P& o) const {
        return mp(x, y) == mp(o.x, o.y);
    }

    int cross(P p1, P p2){
        return x * p1.y + p1.x * p2.y + p2.x * y - (y * p1.x + p1.y * p2.x  + p2.y * x);
    }
};


vector<P> Plst;
vector<int> adj[1010];

bool vis[1010][1010];
vector<int> route;

void go(int v, int nxt){
    vis[v][nxt] = 1;
    if (nxt == route[0]){
        return;
    }
    int ix = -1;
    for(int i = 0; i < (int)adj[nxt].size(); i++){
        if (adj[nxt][i] == v){
            ix = (i+1)% (int)adj[nxt].size();
            break;
        }
    }

    if (ix == -1){
        cout << "ERRR\n";
        return;
    }
    route.push_back(nxt);
    go(nxt, adj[nxt][ix]);
}

void solve(){   
    
    int n;
    cin >> n;

    vector<pair<P, P>> F;
    for(int i = 0; i < n ;i++){
        int a, b, c, d;
        cin >> a>> b >> c >> d;
        F.push_back(mp(P(a, b), P(c, d)));
        Plst.push_back(P(a, b));
        Plst.push_back(P(c, d));
    }   
    sort(all(Plst));
    Plst.erase(unique(all(Plst)), Plst.end());

    for(auto [a,b] : F){
        int ix = lower_bound(all(Plst), a) - Plst.begin();
        int ix2 = lower_bound(all(Plst), b) - Plst.begin();

        adj[ix].push_back(ix2);
        adj[ix2].push_back(ix);
    }

    n = Plst.size();

    // cout << "Point lst\n";
    // for(int i = 0; i < n; i++){
    //     cout << Plst[i].x << ' '<< Plst[i].y << '\n';
    // }

    for(int i =0; i < n; i++){
        // sort in ccw
        
        vector<pair<ld, int>> tmp;
        for(auto f : adj[i]){
            tmp.push_back(mp(atan2(Plst[f].x - Plst[i].x, Plst[f].y - Plst[i].y), f));
        }

        sort(all(tmp));
        adj[i].clear();
        for(auto [a,b] : tmp) adj[i].push_back(b);

        // cout << i << " | ";
        // for(auto f : adj[i]) cout <<f << ' ';
        // cout << '\n';
    }

    ld ans = 0;
    for(int i = 0; i < n;i++){
        for(auto f : adj[i]){
            if (vis[i][f]) continue;
            route.clear();
            route.push_back(i);
            go(i, f);           
            
            // cout << "route found: ";
            // for(auto k : route) cout << k << ' ';
            // cout << '\n';

            ll tot = 0;
            for(int j = 1; j + 1< (int)route.size(); j++){
                tot += Plst[i].cross(Plst[route[j]], Plst[route[j+1]]);
            }
            if (tot >= 0){
                ld tmp = 0.5 * tot;
                ans += tmp * tmp;
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << ans << '\n';
}


int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
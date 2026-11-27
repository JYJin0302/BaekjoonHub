#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


int N[1001010];
vector<pair<int, int>> edge[1001010];

vector<int> adj[40];
int sz[40];
int G[40];
int groupCount = 0;

void setup(int idx){
    groupCount = 0;
    int n = N[idx];
    assert(n <= 30);
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        sz[i] = 0;
        G[i] = -1;
    }
    for(auto[a,b]: edge[idx]) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void getSize(int v, int pv = -1){
    sz[v] = 1;
    G[v] = groupCount;
    for(auto f : adj[v]) if (f != pv && G[f] == -1){
        getSize(f, v);
        sz[v] += sz[f];
    }
}

pair<int, int> getCent(int v, int pv = -1){
    ++groupCount;
    getSize(v, pv);
    int totS = sz[v];
    int ret = v;
    while(1){
        bool mv = 0;
        for(auto f : adj[ret]) if (f != pv && G[f] == groupCount){
            if (sz[f] * 2 >= totS) {
                pv = ret;
                ret = f;
                mv = 1;
                break;
            }
        }
        if (!mv) break;
    }

    if(sz[ret] == totS - sz[ret]){
        // two centroid
        return mp(ret, pv);
    }
    return mp(ret, ret);
}

ll h(ll x){
    return x* x* x* 234523 + 941823;
}
ll fun(ll x){
    ll res = h(x & ((1 << 31) - 1)) + h(x >> 31);
    return res;
}

ll getHash(int v, int pv = -1, int groupNum = -1){
    vector<ll> res;
    for(auto f : adj[v]) if (f != pv && G[f] == groupNum){
        res.push_back(getHash(f, v, groupNum));
    }
    
    ll ret = 1;
    for(auto f :res) ret += fun(f);
    return ret;
}

void solve(){
	
	int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> N[i];
        for(int j =0; j < N[i] - 1; j++){
            int a, b;
            cin >> a>> b;
            a++,b++;
            edge[i].push_back(mp(a, b));
        }
    }

    map<ll, int> H;
    for(int i = 0; i < m; i++){
        setup(i);

        // get Entire hash
        pair<int, int> cent = getCent(1, -1);

        if (cent.x != cent.y){
            ll v1 = getHash(cent.x, cent.y, groupCount);
            ll v2 = getHash(cent.y, cent.x, groupCount);

            if (v1 > v2) swap(v1,v2);
            ll res = h(v1) + h(v2) + 100;
            H[res]++;
            //cout << "T2: " << i<< ' '<< res << '\n';
        }
        else{
            ll v1 = getHash(cent.x, cent.y, groupCount);
            H[v1]++;
           // cout << "T1: " << i << ' '<< v1 << '\n';
        }
    }

    int ans = 0;
    for(auto f : H) ans++;
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
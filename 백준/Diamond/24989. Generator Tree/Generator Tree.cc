#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


int N[202020];
vector<pair<int, int>> edge[202020];

const int p1 = 1000003;
const int mod = 1e9 + 7;

vector<int> adj[202020];
int sz[202020];
int G[202020];
int groupCount = 0;

void setup(int idx){
    groupCount = 0;
    int n = N[idx];
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
    sort(all(res));
    ll ret = 1;
    for(auto f :res) ret += fun(f);
    return ret;
}



ll curHash = -1;
bool dfs(int v, int pv = -1, int tarSize = 1){
    sz[v] = 1;
    for(auto f: adj[v]) if (f != pv){
        if (!dfs(f, v, tarSize)) return 0;
        sz[v] += sz[f];
    }

    if(sz[v] > tarSize) return 0;
    if (sz[v] == tarSize){
        // getCentroid
       // cout << "Go get cent: " << v << ' ' << pv << '\n';
        auto res = getCent(v, pv);
        //cout << res.x << ' ' << res.y << '\n';

        if(res.x != res.y) {
            ll v1 = getHash(res.x, res.y, groupCount);
            ll v2 = getHash(res.y, res.x, groupCount);
            if (v1 > v2) swap(v1, v2);
            ll ret = (v1 * p1 % mod * p1 + v2 + 10) % mod;
            //cout << "T2 : " << ret << '\n';
            if (curHash == -1 || curHash == ret) curHash = ret;
            else return 0;
        }
        else{
            ll ret = getHash(res.x, res.y, groupCount);
            //cout << "T1 : " << ret << '\n';
            if (curHash == -1 || curHash == ret) curHash = ret;
            else return 0;
        }
        sz[v] = 0;
    }
    if (v == 1 && sz[v]) return 0;
    return 1;
}

void solve(){
	
	int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> N[i];
        for(int j =0; j < N[i] - 1; j++){
            int a, b;
            cin >> a>> b;
            edge[i].push_back(mp(a, b));
        }
    }

    map<int, int> h;
    for(int i = 0; i < m; i++){
        setup(i);

        // get Entire hash
        pair<int, int> cent = getCent(1, -1);

        if (cent.x != cent.y){
            ll v1 = getHash(cent.x, cent.y, groupCount);
            ll v2 = getHash(cent.y, cent.x, groupCount);

            if (v1 > v2) swap(v1,v2);
            ll res = v1 * p1 % mod * p1 + v2 + 10;
            res %= mod;

            h[res]++;

            //cout << "T2: " << i<< ' '<< res << '\n';
        }
        else{
            ll v1 = getHash(cent.x, cent.y, groupCount);
            h[v1]++;
           // cout << "T1: " << i << ' '<< v1 << '\n';
        }
    }

    vector<int> ans(m);

    for(int i = 0; i < m;i++){
        // get Answer

        int n = N[i];
        for(int j = 2; j <= n; j++){
            if (n % j) continue;
            
            setup(i);
            curHash = -1;
            //cout << " Go search: " << i << ' ' << j << '\n';
            if (dfs(1, -1, j)){
                //cout << "found hash: " << i << ' ' << j << " | " << curHash << '\n';
                ans[i] += h[curHash];

                //for(int k= 1; k <= n; k++) cout << G[k] << ' ';
                //cout << '\n';
            }
        }



    }

    for(int i = 0; i < m; i++) cout << ans[i] - 1 << ' ';
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[101010];
ll cnt[101010];
ll ans = 0;
void dfs(int v, int pv=  -1){

    vector<ll> res;
    for(auto f : adj[v]) if (f != pv){
        dfs(f, v);

        res.push_back(cnt[f]);
    }
    res.push_back(0);
    sort(all(res));
    reverse(all(res));

    ll tot = 0;
    for(auto f : res) tot += f;
    ans += 2 * (tot - (v == 1 ? 0 : res[0]));
    cnt[v] += tot;
}


void solve(){

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> cnt[i];
    cnt[1] = 0;

    for(int i =0 ; i < n-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    
    cout << ans << '\n';

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
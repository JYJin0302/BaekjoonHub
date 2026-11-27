#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[101010];
int from[101010];
void dfs(int v, int pv = -1){
    for(auto f : adj[v])if (f != pv){
        from[f] = v;
        dfs(f, v);
    }
}

void solve(){
    
    int n;
    cin >> n;
    
    int s, c, h;
    cin >> s>> c >> h;
    
    for(int i =0 ;i <  n-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> route;

    vector<ll> D(3);
    dfs(s);
    int cur = c;
    while(cur != s){
        route.push_back(cur);
        cur = from[cur];
    }
    route.push_back(s);
    reverse(all(route));
    D[0] = route.size();

    dfs(c);
    vector<int> route2;
    cur = h;
    while(cur != c){
        route2.push_back(cur);
        cur = from[cur];
    }
    route2.push_back(c);
    reverse(all(route2));
    D[2] = route2.size();
    for(auto f : route2){
        if (!route.empty() && route.back() == f){
            D[0]--, D[2]--, D[1]++;
            route.pop_back();
        }
        else break;
    }

    ll ans = 0;
    ans += D[0] * (D[0] - 1) / 2;
    ans += D[0] * (D[1] + D[2]);
    ans += D[1] * (D[1] - 1);
    ans += D[1] * D[2];
    ans += D[2] * (D[2] - 1) / 2;
    cout << ans << '\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
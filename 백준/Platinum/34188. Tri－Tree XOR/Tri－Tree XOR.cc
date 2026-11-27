#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
 
vector<int> adj[303030];
 
vector<pair<int, int>> ans;
bool dfs(int v, int pv = -1){
    int pre = -1;
    for(auto f : adj[v]) if (f != pv){
        bool res = dfs(f, v);
        if (res){
            if (pre == -1) pre = f;
            else{
                ans.push_back(mp(v, f));
                ans.push_back(mp(f, pre));
                pre = -1;
            }
        }
    }
    if (pre != -1){
        assert(pv != -1);
        ans.push_back(mp(pre, v));
        ans.push_back(mp(pv, pre));
        return 0;
    }
    return 1;
}
 
void solve() {
 
    int n;
    cin >> n;
 
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    if (n % 2 == 0){
        cout << "NO\n";
        return;
    }
 
    dfs(1);
 
    cout << "YES\n";
    for(auto[a,b] : ans) cout << a<< ' ' << b << '\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

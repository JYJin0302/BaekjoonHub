#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[202020];

int sz[202020];
void dfs(int v, int pv = -1){

    sz[v] = 1;
    vector<pair<int, int>> ch;
    for(auto f : adj[v]) if (f != pv){
        dfs(f, v);
        sz[v] += sz[f];
    }
}

void goS(int v ,int pv = -1){
    vector<pair<int, int>> ch;
    for(auto f :adj[v]) if (f != pv){
        ch.push_back(mp(sz[f], f));
    }
    sort(all(ch));
    reverse(all(ch));

    for(auto[a,b]: ch){
        goS(b, v);
    }

    cout << v << ' ';
}

void solve(){

    int n;
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    goS(1);
    cout << '\n';


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


vector<int> adj[101010];

void solve(){
    
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool ok = 0;
    pair<int, int> tar  =mp(-1, -1);
    for(int i =1; i <= n; i++){
        sort(all(adj[i]));
        if ((int)adj[i].size() == n-1) {}
        else {
            ok = 1;
            int ni = 1;
            for(auto f : adj[i]){
                if (ni == i) ni++;
                if (f == ni){
                    ni++;
                }
                else break;
            }
            if (ni == i) ni++;

            if (ni <= n){
                tar = mp(i, ni);
            }
        }
    }

    if (!ok){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    int u = tar.x, v = tar.y;
    if (u > v) swap(u, v);
    vector<int> ans1(n+1);
    int cur = 3;
    ans1[u] = 1;
    ans1[v] = 2;
    for(int i = 1; i <= n; i++){
        if(i == u || i == v) continue;
        ans1[i] = cur++;
    }


    for(int i =1; i <= n; i++) cout << ans1[i] << ' ';
    cout << '\n';
    ans1[v] = 1;

    for(int i =1; i <= n; i++) cout << ans1[i] << ' ';
    cout << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

vector<int> adj[303030];

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for(int i= 1 ; i <= n; i++){
        ans += max(0, (int)adj[i].size() - 2);
    }
    cout << ans;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();


}

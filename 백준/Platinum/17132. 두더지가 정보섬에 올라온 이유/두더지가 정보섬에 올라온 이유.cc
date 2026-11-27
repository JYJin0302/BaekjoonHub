#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int root[101010];
int sz[101010];
int find(int n){
    if(root[n] == n)return n;
    return root[n] = find(root[n]);
}


void solve(){
    
    int n;
    cin >> n;

    for(int i = 1; i<= n; i++){
        root[i] = i;
        sz[i] = 1;
    }
    vector<array<int, 3>> A;
    for(int i = 0; i < n-1; i++){
        int a, b, w;
        cin >> a>> b>> w;
        A.push_back({w, a, b});
    }
    sort(all(A));
    reverse(all(A));

    ll ans = 0;
    for(auto f : A){
        int u = find(f[1]);
        int v = find(f[2]);

        ll val = f[0];
        val = val * sz[u] * sz[v];
        sz[u] += sz[v];
        root[v] = u;
        ans += val;
    }
    cout << ans << '\n';
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

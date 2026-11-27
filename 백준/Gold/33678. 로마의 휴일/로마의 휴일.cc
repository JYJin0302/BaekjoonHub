#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

void solve(){

    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> A(n);
    for(auto& i : A) cin >> i;

    vector<ll> sA(n+1);
    for(int i = n-1; i >= 0; i--){
        sA[i] = A[i] + (i < n-1 ? sA[i+1] : 0);
    }   

    int ans = 0;

    ll pre = 0;
    int ix = 0;
    for(int i = 0; i < n;i++){
        ix = max(ix, i);

        while(ix <= n && pre + sA[ix] >= k) ix++;
        ans = max(ans, ix - i - 1);

        pre += x * A[i];
    }
    if (ans == 0) ans = -1;
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
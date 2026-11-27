#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
ll C[2020][2020];

ll nCr(int n, int r){
    if (C[n][r] != -1) return C[n][r];
    if (r > n) return C[n][r] = 0;
    if (r == 0 || n == r) return C[n][r] = 1;
    return C[n][r] = (nCr(n-1, r) + nCr(n-1, r-1)) % mod;
}

void solve(){
    
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    if (*min_element(all(A)) == 1){
        cout << 1 << '\n';
        return;
    }

    if (*max_element(all(A)) == n){
        cout << 1 << '\n';
        return;
    }

    ll ans = 1;
    int cur = n;
    for(auto f : A){
        ans = ans * nCr(cur, f) % mod;
        cur -= f;
    }
    cout << ans << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(C, -1, sizeof C);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
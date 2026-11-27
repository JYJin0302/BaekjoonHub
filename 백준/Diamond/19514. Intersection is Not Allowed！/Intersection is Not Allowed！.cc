#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
ll F[303030];

ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1) res = res* b % mod;
        b =b* b % mod;
        ex >>= 1;
    }
    return res;
}
ll nCr(int n, int r){
    ll res= F[n];
    res = res * fastPow(F[n-r], mod-2) % mod;
    res = res * fastPow(F[r], mod-2) % mod;
    return res;
}
ll det(int n, vector<vector<ll>> a) {
    ll ans = 1;
    for(int i =0;i < n; i++) {
        for(int j = i+1; j < n;j++) {
            while (a[j][i] != 0) { // gcd step
                ll t = a[i][i] / a[j][i];
                if (t) for(int k = i; k < n; k++) a[i][k] = (a[i][k]- a[j][k] * t) % mod;
                swap(a[i], a[j]);
                ans *=-1;
                }
            }
            ans = ans * a[i][i] % mod;
        if (!ans) return 0;
    }
    return (ans + mod) % mod;
}

void solve(){
    
    int n, k;
    cin >> n >> k;

    vector<int> A(k), B(k);
    for(auto& i : A) cin >> i;
    for(auto& i :B) cin >> i;

    vector<vector<ll>> mat(k, vector<ll>(k));

    for(int i =0 ;i < k; i++){
        for(int j =0 ;j < k; j++){
            // path from A[i] -> B[j]
            if (A[i]> B[j]) mat[i][j] = 0;
            else{
                mat[i][j] = nCr(n - 1 + B[j] - A[i], n-1);
            }
        }
    }

    ll ans = det(k, mat);
    cout << ans << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    F[0] = 1;
    for(int i = 1;i <= 300000; i++){
        F[i] = F[i-1]* i % mod;
    }

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }   
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;

ll comb[4001][4001];
ll ex[4001][4001];

ll fastP(ll b, ll e){
    ll res = 1;
    while(e){
        if (e % 2 == 1) res *= b;
        b = b*b % mod;
        res %= mod;
        e >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    vector<ll> A(n+1), f(n+1);
    for(auto& i : A) cin >> i;
    
    comb[0][0] = 1;
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if (j == 0) {
                comb[i][j]=1;
                ex[i][j] = 1;
            }
            else {
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
                ex[i][j] = ex[i][j-1] * i % mod;
            }
        }
    }
    
    f[0] = A[0];
    for (int i = 1; i <= n; i++){
        for (int j = n; j >= 0; j--){
            f[i] = (f[i] + (ex[i][j] * A[j])) % mod;
        }
    }
    
    cout << "GGG<" << A[0];
    for (int i = 1; i <= n; i++){
        ll res = 0;
        bool p = 1;
        for (int j = i; j >= 0; j--){
            res = (res + (2*p - 1)*comb[i][j]*f[j]) % mod;
            p ^= 1;
        }
        cout<< "," << res;
    }
    cout << ">";
}
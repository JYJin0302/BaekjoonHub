#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 998244353;
ll dp[5050]; // j 개의 빈칸이 남아있음  : ? x ? x ? x a b d c
ll ndp[5050];

ll C[5050][5050];

ll nCr(int n, int r){
    if (n == r || r == 0) return C[n][r] = 1;
    if (n < r) return C[n][r] = 0;
    if(C[n][r] != -1) return C[n][r];
    return C[n][r] = (nCr(n-1, r) + nCr(n-1, r-1)) % mod;
}

void solve(){
    
    int n;
    cin >> n;
    vector<int>A(n);
    for(auto& i : A) cin >> i;

    for(int i = 0; i <= n; i++) dp[i] = 0;
    dp[1] = 1;

    int ix = n-1;
    while(ix>= 0 && A[ix] == A[n-1]) ix--;
    int tlen = n - 1 - ix;
    if(tlen >= 2){
        cout << 0 << '\n';
        return;
    }

    while(ix >= 0){
        int nx = ix;
        while(nx>=0 && A[ix] == A[nx]) nx--;

        for(int j = 0;j <= n+1; j++) ndp[j] = 0;

        int len = ix - nx;

        int tot = n - ix - 1;
        for(int j = 1; j <= n; j++){
            if (dp[j] == 0) continue;
            int remEven = n - (tot + j);
            if (remEven){
                // try add one

                // fill len - 1
                if (j + 1 - (len - 1) >= 0){
                    ll res = dp[j] * nCr(j-1, len - 1) % mod;
                    (ndp[j + 1 - (len - 1)] += res) %= mod;
                }
            }

            if (len <= j){
                ll res = 0;
                if (remEven == 0) res = dp[j] * nCr(j, len)% mod;
                else res = dp[j] * nCr(j - 1, len) % mod;
                (ndp[j - len] += res) %= mod;
            }

        }
        swap(ndp, dp);

        // cout << "Go :" << len << '\n';
        // for(int i =0; i <= n; i++) cout << dp[i] << ' ';
        // cout << '\n';

        ix = nx;
    }

    cout << dp[0] << '\n';
    
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

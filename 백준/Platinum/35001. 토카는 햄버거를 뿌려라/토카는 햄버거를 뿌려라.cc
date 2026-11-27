#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

int dp[1 << 20];

bool used[20];
bool inQ[1 << 20];

ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1) res = res * b % mod;
        b = b *b % mod;
        ex >>= 1;
    }
    return res;
}

void solve(){

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    if (n == m){
        cout << 1 << '\n';
        return;
    }

    vector<int> v, tmp;
    v.push_back(0);

    int ans = 0;

    dp[0] = 1;
    for(int t = 0; t < m;t ++){
        tmp.clear();
        for(auto state : v){

            ll mul = dp[state];

            int tot = 0;
            for(int i = 0; i < n;i++){
                if (state & (1 << i)){}
                else tot += A[i] * A[i];
            }

            ans += mul * (A[0] * A[0])  % mod * fastPow(tot, mod-2) % mod;
            ans %= mod;

            for(int i = 1; i < n; i++){
                if (state & (1 << i)){}
                else {
                    int ns = state | (1 << i);
                    ll np = mul * (A[i] * A[i]) % mod * fastPow(tot, mod-2) % mod;

                    dp[ns] = (dp[ns] + np) % mod;
                    if (!inQ[ns]){
                        inQ[ns] = 1;
                        tmp.push_back(ns);
                    }
                }
            }

        }

        swap(tmp, v);
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
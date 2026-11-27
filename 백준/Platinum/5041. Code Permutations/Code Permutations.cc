#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = (1 << 31) - 1;

map<ll, ll> dp[101];

ll F[101];
ll comb[101][101];
ll nCr(int n, int r){
    if (comb[n][r] != -1) return comb[n][r];
    if (n == r || r == 0) return comb[n][r] = 1;
    return comb[n][r] = (nCr(n-1,r) + nCr(n-1, r-1)) % mod;
}

ll fastPow(ll b, ll ex){
    ll res =1;
    while(ex){
        if (ex & 1) res =res * b % mod;
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

void solve(){
    memset(comb, -1 ,sizeof comb);

    int n, k;
    cin >> n >> k;
    int tk = k;
    F[0] = 1;
    for(int i = 1; i <= n; i++){
        F[i] = (F[i-1] * i) % mod;
    }

    int len = 0;
    vector<pair<int, int>> P;
    for(int i = 2; i <= 100; i++){
        int cnt = 0;
        while(k % i == 0){
            cnt++;
            k/= i;
        }

        if (cnt){
            P.push_back(mp(i, cnt));
            len += cnt;
        }
    }
    
    if(k != 1 || len > n){
        cout << 0 << '\n';
        return;
    }

    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        if (tk % i != 0) continue;
        for(int j = n; j >= i; j--){
            ll mul = 1;

            for(int cnt = 1; cnt * i <= j; cnt++){
                mul = mul * F[i-1] % mod;
                mul = mul * nCr(n - (j - cnt * i), i) % mod;

                ll tmp = fastPow(F[cnt], mod-2) * mul % mod;

                for(auto f : dp[j-i*cnt]){
                    ll test = f.x / gcd(f.x, i) * i;
                    if (tk % test == 0){
                        (dp[j][test] += f.y * tmp % mod) %= mod;
                    }
                }
            }
        }

        // cout << "Satte: " << i << '\n';
        // for(int j = 0; j <= n; j++){
        //     cout << "DP " << j << ": ";
        //     for(auto f: dp[j]) cout << f.x << ' ' <<f.y << " || ";
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << dp[n][tk] << '\n';



    
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
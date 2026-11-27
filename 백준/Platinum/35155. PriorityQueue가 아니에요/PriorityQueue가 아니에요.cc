#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


const int mod = 998244353;
ll ans[1001010];
ll F[2002020];

ll fastPow(ll b, ll ex){
    ll res=  1;
    while(ex){
        if (ex & 1) res = res *b % mod;
        b = b* b % mod;
        ex >>= 1;
    }
    return res;
}

ll catalan(int n){
    ll res = F[n*2];
    res = res * fastPow(F[n], mod-2) % mod;
    res = res * fastPow(F[n+1], mod-2) % mod;
    return res;
}

void solve(){
    
    int t;
    cin >> t;

    F[0] = 1;
    for(int i = 1; i <= 2000000; i++){
        F[i] = F[i-1] * i % mod;
    }

    ans[1] = -1;
    ans[2] = ans[3] = ans[4] = 1;
    for(int i = 5; i <= 1000000; i++){
        if (i % 3 == 1){
            ans[i] = (ans[i-1] + ans[i-2] + mod - catalan(i/3)) % mod;
        }
        else{
            ans[i] = (ans[i-1] + ans[i-2]) % mod;
        }
    }

    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}


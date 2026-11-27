#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int mod2 = 998244353;

void solve(){
    
    string s;
    cin >> s;
    int n;
    cin >> n;

    int k = (int)s.size();

    vector<int> fail(k);
    for(int i = 1; i < k; i++){
        int j = fail[i-1];
        while(j && s[j] != s[i]) j = fail[j-1];
        if (s[j] == s[i]) j++;
        fail[i] = j;
    }

    int len = fail[k-1];

    int cyc = k;
    if (len * 2 >= k && k % (k - len) == 0) cyc = k - len;

    ll ans = 0;
    s = s + s;

    map<pair<int, int>, bool> cnt;

    for(int i = 1; i <= cyc; i++){
        cnt.clear();

        ll b = 1;
        ll b2 = 1;
        ll val = 0;
        ll val2 = 0;
        int tans = 0;
        for(int j = 0; j < cyc + i - 1 && j < n;j++){
            val = val * 26 + (s[j] - 'a');
            val %= mod;

            val2 = val2 * 26 + (s[j] - 'a');
            val2 %= mod2;
            if(j >= i){
                val += mod - (s[j-i] - 'a') * b % mod;
                val %= mod;

                val2 += mod2 - (s[j-i] - 'a') * b2 % mod2;
                val2 %= mod2;
            }
            else {
                b = b * 26 % mod;
                b2 = b2 * 26 % mod2;
            }

            if (j >= i-1 && !cnt[mp(val, val2)]) {
                tans++;
                cnt[mp(val, val2)] = 1;
            }
        }

        //cout << i << ' '<< tans << '\n';
        ans += tans;
    }
    //cout << ans << '\n';

    // 길이 cyc + 1 ~ n까지
    if(cyc + 1 <= n){
        int tlen = n - cyc;
        if(tlen >= cyc){
            ans += 1ll * tlen * cyc;
            for(int i = 0; i < cyc; i++) ans -= i;
        }
        else{
            for(int i = 1; i <= tlen; i++) ans += i;
        }
    }
    cout << ans << '\n';
    

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


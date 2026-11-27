#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod1 = 998244353;
const ll mod2 = 1e9+7;

#define mp make_pair

void solve(){

    ll n, k;
    cin >>n >>k;

    vector<ll> A(n);
    for(auto&i :A)cin >>i;

    if (n < k){
        cout << 0;
        return;
    }

    vector<ll> pow_n1(n+1), pow_n2(n+1);
    pow_n1[1] = 1;
    for(int i = 2; i <= n; i++){
        pow_n1[i] = pow_n1[i-1] *(n+1) % mod1;
    }
    pow_n2[1] = 1;
    for(int i = 2; i <= n; i++){
        pow_n2[i] = pow_n2[i-1] *(n+1) % mod2;
    }
    ll val1 = 0;
    for(int i = 1; i < k; i++){
        val1 += pow_n1[i];
        val1 %= mod1;
    }
    pow_n1[k] = (mod1 - val1) % mod1;
    val1 = 0;
    for(int i = 1; i < k; i++){
        val1 += pow_n2[i];
        val1 %= mod2;
    }
    pow_n2[k] = (mod2 - val1) % mod2;

    ll v1 = 0, v2 = 0;
    map<pair<ll, ll>, int> st;
    st[mp(0, 0)] = 1;

    int ans = 0;
    for(int i = 0; i < n; i++){
        v1 += pow_n1[A[i]] % mod1;
        v1 %= mod1;
        v2 += pow_n2[A[i]] % mod2;
        v2 %= mod2;

        if (st[mp(v1,v2)]){
            ans = max(ans, i+2-st[mp(v1,v2)]);
        }
        else{
            st[mp(v1,v2)] = i+2;
        }
    }
    cout << ans;


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

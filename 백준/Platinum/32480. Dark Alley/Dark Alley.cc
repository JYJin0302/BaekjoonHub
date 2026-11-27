#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


const int mod = 1e9 + 7;

ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1) res = res * b% mod;
        b =b *b % mod;
        ex >>= 1;
    }
    return res;
}

ll pwP[202020];

ll fwL[202020];
ll fwR[202020];

void update(int ix, ll val, ll fw[]){
    while(ix <= 200020){
        (fw[ix] += val) %= mod;
        ix += ix & -ix;
    }
}
ll getS(int ix, ll fw[]){
    ll res = 0;
    while(ix){
        res += fw[ix];
        res %= mod;
        ix -= ix & -ix ;
    }
    return res;
}

void solve(){
    
    int n, q;
    cin >> n >> q;

    string sp;
    cin >> sp;

    ll p1 = 0, p2 = 1;
    for(int i =2; i < (int)sp.size(); i++){
        int v = sp[i] - '0';
        p1 = p1 * 10 + v;
        p2 *= 10;
    }

    ll P = p1 * fastPow(p2, mod-2) % mod;
    P = (mod + 1 - P) % mod;
    pwP[0] = 1;
    for(int i = 1; i <= n; i++) pwP[i] = pwP[i-1] * P % mod;

    //cout << "P : " << P << '\n';
    
    vector<ll> S(n+1);

    while(q--){
        char c;
        cin >> c;
        if (c == '+'){
            ll a, b;
            cin >> a >> b;

            S[b] = (S[b] + a) % mod;
            ll val = a * fastPow(pwP[b], mod-2) % mod;
            update(b, val, fwL);

            val = a *  pwP[b] % mod;
            update(n+1-b, val, fwR);
        }
        else if (c == '-'){
            ll a, b;
            cin >> a>> b;

            S[b] = (S[b] + mod - a) % mod;
            ll val = a * fastPow(pwP[b], mod-2) % mod;
            val = (mod - val) % mod;
            update(b, val, fwL);

            val = a *  pwP[b] % mod;
            val = (mod - val) % mod;
            update(n+1-b, val, fwR);
        }
        else{
            int ix;
            cin >> ix;

            ll res = mod - S[ix];

            res += getS(ix, fwL) * pwP[ix] % mod;
            res %= mod;

            res += getS(n+ 1-ix, fwR) * fastPow(pwP[ix], mod-2) % mod;
            res %= mod;

            cout << res << '\n';
        }
    }




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

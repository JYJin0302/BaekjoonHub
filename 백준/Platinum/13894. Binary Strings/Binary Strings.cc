
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex &1) res = res*b % mod;
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

struct Mat{
    ll a, b, c, d;

    Mat(ll _a, ll _b, ll _c, ll _d) : a(_a), b(_b) , c(_c), d(_d) {}

    Mat inv(){
        ll C = ((a*d - b*c) % mod + mod) % mod;
        C = fastPow(C%mod , mod-2) % mod;
        return Mat((mod + C*d %mod) % mod, (mod - C*b%mod) % mod, (mod - C*c%mod) % mod, (mod + C*a % mod)% mod);
    }

    Mat operator+(Mat& o){
        return Mat((a+o.a)%mod, (b+o.b) % mod, (c+o.c) % mod, (d+o.d) % mod);
    }

    void pf(){
        cout << a << ' ' << b << '\n';
        cout << c << ' ' <<d <<'\n';
    }
};
// a b
// c d

Mat mult(Mat& m1, Mat& m2){
    return Mat((m1.a*m2.a + m1.b*m2.c)%mod, \
               (m1.a*m2.b + m1.b*m2.d)%mod, \
               (m1.c*m2.a + m1.d*m2.c)%mod, \
               (m1.c*m2.b + m1.d*m2.d)%mod);
}


Mat fastPow(Mat base, ll ex){
    Mat res(1, 0, 0, 1);
    while(ex){
        if (ex &1) res = mult(res, base);
        base = mult(base, base);
        ex >>= 1;
    }
    return res;
}


ll getVal(ll X, ll K){
    X -= X % K;
    if(X < K) return 0;
    X /= K;
    // Fib_(K, 2K, 3K , ... , XK)

    Mat base = fastPow(Mat(1, 1, 1, 0), K);

    Mat S = fastPow(base, X+1);
    S.a = (S.a - 1 + mod) % mod;
    S.d = (S.d - 1 + mod) % mod;

    base.a = (base.a - 1 + mod) % mod;
    base.d = (base.d - 1 + mod) % mod;
    base = base.inv();

    S = mult(base, S);
    S.a = (S.a - 1 + mod) % mod;
    S.d = (S.d - 1 + mod) % mod;


   // S.pf();

    return (S.a + S.b) % mod;
}

void solve(){

    ll L, R, K;
    cin >> L >> R >> K;

    ll ans = getVal(R, K) - getVal(L-1, K) + mod;
    ans %= mod;

    cout << ans << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 1;
    cin>>tc;
    for(int i = 1; i <= tc; i++){
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}


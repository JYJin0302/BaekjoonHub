#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b){
    if (a > b) swap(a, b);
    if (a == 0)  return b;
    return gcd(b% a, a);
}
void solve(){

    ll s0, X, M, D, K;
    cin >> s0 >> X >> M >> D >> K;
    
    X %= M;

    ll G = gcd(M, X);

    ll maxVal = s0 + (M - s0 - 1) / G * G;
    if (maxVal == 0) {
        cout << 0;
        return;
    }

    ll t = (K / maxVal);
    cout << (D - 1) / t << '\n';

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
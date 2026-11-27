#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;
void solve(){

    ll L, R;
    cin >> L >> R;

    vector<ll> cnt(1001010);
    cnt[1] = 1;
    cnt[2] = 1;
    for(int i = 3; i <= 1000000; i++){
        cnt[i] = cnt[i-2] * 26 % mod;
    }
    ll tot = 0;
    for(int i = L; i <= R; i++){
        (tot += cnt[i]) %= mod;
    }

    int res = 0;
    if (L <= 1 && 1 <= R) res ^= 1;
    if (L <= 2 && 2 <= R) res ^= 1;
    cout << (res ? 'H' : 'A') << '\n' << tot << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

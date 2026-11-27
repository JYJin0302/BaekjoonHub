#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    
    ll a, b;
    cin >> a>> b;

    if(a % 2 != b % 2){
        cout << -1 << '\n';
        return;
    }

    char c = 'A';
    if (b > a) {
        c = 'B';
        swap(a, b);
    }
    // one try
    ll dif = a - b;
    ll val = 0, ans = 0;
    for(int i = 29; i >= 0; i--){
        if (a & (1 << i)){
            ll ad = 1ll << (i+1);
            if (val + ad <= dif){
                val += ad;
                ans += 1 << i;
            }
        }
    }
    if (val == dif){
        cout << 1 << '\n' << c << ' '<< ans << '\n';
        return;
    }

    // two

    dif >>= 1;
    cout << 2 << '\n';
    cout << c << ' '<< dif << '\n';
    cout << c << ' '<< dif << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}

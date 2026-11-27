#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0 ,-1 };

ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1)res = res * b % mod;
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

void solve() {

    int n = 10;
    int pos = 0;
    while (n--) {
        int x;
        cin >> x;
        pos = (pos + x) % 4;
    }

    vector<char> res = { 'N', 'E', 'S', 'W' };
    cout << res[pos];

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
}
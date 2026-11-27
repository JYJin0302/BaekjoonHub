#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;

void solve() {

    ll n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (auto& i : A) cin >> i;
    A.push_back(0);

    queue<ll> q1, q2;
    for (int i = 0; i < k; i++) {
        q1.push(0);
        q2.push(0);
    }

    ll s1 = 0, s2 = 0; // 1 ~ k (except 0)
    ll c1 = 1, c2 = 0;
    for (int i = 0; i <= n; i++) {
        if (A[i] == 1) {
            q1.push(c1); s1 += c1;
            s1 -= q1.front(); q1.pop();
            s1 = (s1 % mod + mod) % mod;

            q2.push(c2); s2 += c2;
            s2 -= q2.front(); q2.pop();
            s2 = (s2 % mod + mod) % mod;
            c1 = 0, c2 = 0;
        }
        else {

            ll ts1 = (s1 - q1.front() + mod) % mod;
            
            ll nc1 = (c1 + ts1) % mod;
            ll nc2 = (c2 + q1.front()) % mod;
            s1 -= q1.front(); q1.pop();
            s1 += c1; q1.push(c1);
            s1 = (s1 % mod + mod) % mod;

            nc2 = (nc2 + s2) % mod;

            s2 -= q2.front(); q2.pop();
            s2 += c2; q2.push(c2);
            s2 = (s2 % mod + mod) % mod;


            c2 = nc2;
            c1 = nc1;
        }

    }

    cout << c2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<ll, ll>> L[1010];
ll dp[1010][1010];

ll getVal(ll x, vector<pair<ll, ll>>& v) {

    int ix = v.size() - 1;
    ll res = v[ix].x * x + v[ix].y;

    while (ix > 0) {
        ll v1 = v[ix - 1].x * x + v[ix - 1].y;
        if (v1 >= res) {
            res = v1;
            ix--;
        }
        else break;
    }


    return res;

}
ld intersect(ll x1, ll y1, ll x2, ll y2) {
    return 1.0 * (y2 - y1) / (x1 - x2);
}

void insert(ll a, ll b, vector<pair<ll, ll>>& v) {
    while (v.size() >= 2) {
        auto [a2, b2] = v.back();
        if (a2 == a) {
            if (b2 >= b) return;
            v.pop_back();
            continue;
        }

        v.pop_back();
        auto [a1, b1] = v.back();

        ld p1 = intersect(a1, b1, a2, b2);
        ld p2 = intersect(a2, b2, a, b);

        if (p1 <= p2) {
            v.push_back(mp(a2, b2));
            break;
        }
    }

    if (!v.empty() && v.back().x == a) {
        v.back().y = max(v.back().y, b);
        return;
    }
    v.push_back(mp(a, b));
}

void solve() {

    int n;
    cin >> n;

    vector<ll> A(n), B(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;
    A.push_back(0);
    B.push_back(0);
    n++;

    vector<ll> sA(n + 1), sB(n+1);
    for (int i = 1; i <= n; i++) {
        sA[i] = sA[i - 1] + A[i-1];
        sB[i] = sB[i - 1] + B[i-1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (i + j == 2) {
                // ok
            }
            else if (i == 1) {
                dp[i][j] -= sB[j - 1] * sB[j - 1];
            }
            else if (j == 1) {
                L[0].clear();
                dp[i][j] -= sA[i - 1] * sA[i - 1];
            }
            else {
                ll v1 = getVal(sA[i - 1], L[j - 1]) - sA[i-1] * sA[i-1];
                ll v2 = getVal(sB[j - 1], L[0]) - sB[j-1] * sB[j-1];

                dp[i][j] = max(v1, v2);
            }
            dp[i][j] += A[i - 1] * B[j - 1];

           // cout << "Go: " << i << ' ' << j << " | " << dp[i][j] << '\n';
            if (i > 1){
                //cout << "Col " << j << " => "; 
                insert(2 * sA[i-1], dp[i-1][j] - sA[i-1] * sA[i-1], L[j]);
                //cout << "Row " << i-1 << " => ";  
                insert(2 * sB[j], dp[i - 1][j] - sB[j] * sB[j], L[0]);
            }
        }
    }

    cout << dp[n][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) {
    return a.y * b.x < b.y * a.x;
}

ll ccw(const pair<ll, ll>& a,const pair<ll, ll>& b, const pair<ll, ll>& c) {
    ll res = a.x * b.y + b.x * c.y + c.x * a.y;
    res -= a.y * b.x + b.y * c.x + c.y * a.x;
    return res;
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> A(n), B(m);
    for (auto& i : A) cin >> i.first;
    for (auto& i : A) cin >> i.second;
    for (auto& i : B) cin >> i.first;
    for (auto& i : B) cin >> i.second;

    sort(all(A), cmp);
    sort(all(B), cmp);

    for (int i = 1; i < m; i++) {
        B[i].x += B[i - 1].x;
        B[i].y += B[i - 1].y;
    }
    for (int i = 1; i < n; i++) {
        A[i].x += A[i - 1].x;
        A[i].y += A[i - 1].y;
    }

    for (int i = 0; i < m; i++) {
        if (ccw(B[i], mp(0ll, 0ll), A[0]) < 0) {
            cout << "No\n";
            return;
        }
        for (int j = 1; j < n; j++) {
            if (ccw(B[i], A[j - 1], A[j]) < 0) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}
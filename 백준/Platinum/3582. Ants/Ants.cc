#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

pair<int, int> A[111], B[111];
int ans[111];

int ccw(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
    int res = a.x * b.y + b.x * c.y + c.x * a.y;
    res -= a.y * b.x + b.y * c.x + c.y * a.x;
    return res / abs(res);
}

bool cross(int i, int j) {
    int i2 = ans[i], j2 = ans[j];

    bool ck1 = ccw(A[i], B[i2], A[j]) * ccw(A[i], B[i2], B[j2]) < 0;
    bool ck2 = ccw(A[j], B[j2], A[i]) * ccw(A[j], B[j2], B[i2]) < 0;

    return ck1 && ck2;
}

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i].first >> B[i].second;
    }

    for (int i = 0; i < n; i++) ans[i] = i;
    while (1) {
        bool ok = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (cross(i, j)) {
                    ok = 0;
                    swap(ans[i], ans[j]);
                }
            }
        }
        if (ok) break;
    }
    
    for (int i = 0; i < n; i++) cout << ans[i] + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
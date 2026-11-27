#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

struct D {
    int c[4];
    int idx = 0;

    bool operator==(D& o) {
        for (int j = 0; j <= 3; j++) {
            if (c[j] != o.c[j]) return 0;
        }
        return 1;
    }
    int val() {
        int ret = 0;
        for (int i = 0; i <= 3; i++) ret += c[i] * i;
        return ret;
    }
    bool operator<(D& o) {
        if (val() != o.val()) {
            return val() > o.val();
        }
        for (int i = 3; i >= 1; i--) {
            if (c[i] != o.c[i]) return c[i] > o.c[i];
        }
        return 0;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<D> A(3);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            A[j].c[x]++;
        }
    }
    for (int i = 0; i < 3; i++) A[i].idx = i + 1;
    sort(all(A));

    if (A[0] == A[1]) cout << 0 << ' ';
    else cout << A[0].idx << ' ';
    cout << A[0].val();

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
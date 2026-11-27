#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;

    vector<bool> A(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        A[i] = (c == 'B');
    }

    vector<int> res(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        deque<bool> q;
        for (int j = 0; j < i; j++) q.push_back(A[j]);

        int cnt = 0;
        bool cur = 0;
        for (int j = i; j <= n; j++) {
            if (cur ^ q.front()) cur ^= 1, cnt++;
            q.pop_front();
            if (j < n) q.push_back(cur ^ A[j]);
        }

        bool ok = 1;
        while (!q.empty()) {
            if (cur ^ q.front()) ok = 0;
            q.pop_front();
        }

        if (ok) {
            res[i] = cnt;
        }
    }

   // for (int i = 1; i <= n; i++) cout << res[i] << ' ';

    int ansc = res[1], ansv = 1;
    for (int i = 2; i <= n; i++) {
        if (res[i] != -1 && res[i] < ansc) {
            ansc = res[i];
            ansv = i;
        }
    }

    cout << ansv << ' ' << ansc << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
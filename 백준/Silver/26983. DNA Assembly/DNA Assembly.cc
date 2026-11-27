#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool valid(string& s1, string& s2, int len) {
    if (len == 0) return 1;

    int l = s1.size() - 1, r = len - 1;
    for (int i = 0; i < len; i++) {
        if (s1[l] != s2[r]) return 0;
        l--, r--;
    }
    return 1;
}

void solve() {

    int n;
    cin >> n;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;

    int ans = 100;
    do {

        string cur = A[ord[0]];
        for (int i = 1; i < n; i++) {

            string nxt = A[ord[i]];

            int sz = min(cur.size(), nxt.size());

            for (int j = sz; j >= 0; j--) {
                if (valid(cur, nxt, j)) {
                    for (int k = j; k < nxt.size(); k++) cur += nxt[k];
                    break;
                }
            }
        }

        ans = min(ans, (int)cur.size());

    } while (next_permutation(all(ord)));
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;
    int tot = 0;
    for (auto f : A) tot += f;
    sort(all(A));
    reverse(all(A));

    if (tot % 4 != 0 || *max_element(all(A)) > tot / 4) {
        cout << "no\n";
        return;
    }
    tot /= 4;

    vector<int> sum(1 << n);
    vector<bool> ok(1 << n);
    ok[0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        if (!ok[i]) continue;
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                int nxt = i ^ (1 << j);
                sum[nxt] = sum[i] + A[j];
                if (ok[nxt] || sum[nxt] > 3 * tot) continue;


                if (sum[nxt] % tot == 0 || sum[i] % tot < sum[nxt] % tot) {
                    ok[nxt] = 1;
                    if (sum[nxt] == 3 * tot) {
                        cout << "yes\n";
                        return;
                    }
                }
            }
        }
    }

    cout << "no\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
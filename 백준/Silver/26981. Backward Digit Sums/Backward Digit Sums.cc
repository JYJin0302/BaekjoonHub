#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    int n, s; cin >> n >> s;
    vector<int> A(n);
    for (int i = 0; i < n; i++) A[i] = i + 1;

    do {
        vector<int> tmp = A;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                tmp[j] += tmp[j + 1];
            }
        }

        if (tmp[0] == s) {
            for (auto f : A) cout << f << ' ';
            cout << '\n';
            return;
        }

    } while (next_permutation(all(A)));

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}
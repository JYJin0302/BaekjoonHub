#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>

vector<int> rule[11];
bool tq[11];

void solve() {
    string s;
    cin >> s >> s >> s >> s;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        vector<int> A(k);
        for (auto& f : A) cin >> f;
        rule[i] = A;
        cin >> tq[i];
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        // assume i is false

        bool ok = 1;
        for (int j = 1; j <= n; j++) {
            if (j == i) {
                tq[j] ^= 1;
            }

            if (tq[j] == 0) {
                for (auto f : rule[j]) {
                    if (f == i) ok = 0;
                }
            }
            else {
                bool tok = 0;
                for (auto f : rule[j]) {
                    if (f == i) tok = 1;
                }
                if (!tok) ok = 0;
            }


            if (j == i) tq[j] ^= 1;
        }

        if (ok) ans.push_back(i);

    }

    if (ans.empty()) cout << "swi\n";
    else for (auto f : ans) cout << f << ' ';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
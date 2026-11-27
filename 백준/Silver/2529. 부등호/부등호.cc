#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int k;
    cin >> k;
    vector<char> A(k);
    for (auto& i : A)cin >> i;

    string s;
    for (int i = 0; i <= k; i++) s += char('0' + i);

    string ans1, ans2;
    do {
        bool ok = 1;
        for (int i = 0; i < k; i++) {
            if (s[i] < s[i + 1] && A[i] == '<') {}
            else if (s[i] > s[i + 1] && A[i] == '>') {}
            else {
                ok = 0;
                break;
            }
        }
        if (ok) {
            if (ans1.empty()) ans1 = s;
            else ans1 = min(ans1, s);
            if (ans2.empty()) ans2 = s;
            else ans2 = max(ans2, s);
        }

    } while (next_permutation(all(s)));

    for (int i = 0; i <= k; i++) {
        ans2[i] += 9 - k;
    }

    cout << ans2 << '\n' << ans1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
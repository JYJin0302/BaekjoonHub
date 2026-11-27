#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> getfail(const string& A) {
    int N = A.size();
    vector<int> fail(N);
    fail[0] = 0;
    for (int i = 1; i < N; i++) {
        int j = fail[i - 1];
        while (j > 0 && A[j] != A[i]) { j = fail[j - 1]; }
        if (A[j] == A[i]) { fail[i] = j + 1; }
    }
    return fail;
}

void solve() {

    string s;
    cin >> s;

    int n = s.size();
    vector<int> f = getfail(s);

    if (f[n - 1] == 0) {
        cout << -1 << '\n';
        return;
    }

    string t = s.substr(0, f[n - 1]);
    int idx = 0;
    for (int i = 1; i < n-1; i++) {
        while (idx && t[idx] != s[i]) idx = f[idx - 1];

        if (s[i] == t[idx]) {
            if (idx == t.size() - 1) {
                cout << t << '\n';
                return;
            }
            else idx++;
        }
    }

    int ans = f[n - 1];
    ans = f[ans-1];

    if (ans == 0) cout << -1;
    else cout << t.substr(0, ans);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


vector<int> getfail(string& A) {
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

    int n;
    cin >> n;

    int cnt = 1;
    while (n) {

        string s;
        cin >> s;

        cout << "Test case #" << cnt << "\n";

        vector<int> f = getfail(s);
        for (int i = 1; i < n; i++) {
            int len = i + 1 - f[i];
            if ((i + 1) % len == 0 && len != i + 1) {
                cout << i + 1 << ' ' << (i+1) / len << '\n';
            }
        }
        cout << '\n';
        cin >> n;
        cnt++;
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
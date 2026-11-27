#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {
    int n; cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int k;
    cin >> k;
    string s;
    cin >> s;
    vector<int> nxtMove(k, -1);
    vector<int> Acnt(k), Dcnt(k);
    for (int i = 0; i < k; i++) {
        if (s[i] == 'A') Acnt[i]++;
        else if (s[i] == 'D') Dcnt[i]++;

        if (i) {
            Acnt[i] += Acnt[i - 1];
            Dcnt[i] += Dcnt[i - 1];
        }
    }

    for (int i = k - 1; i >= 0; i--) {
        if (s[i] == 'J') {
            nxtMove[i] = i;
        }
        else if (i != k - 1) nxtMove[i] = nxtMove[i + 1];
    }

    if (nxtMove[0] == -1) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < k; i++) {
        if (nxtMove[i] == -1) nxtMove[i] = nxtMove[0];
    }

    int ix = 0;
    int cur = 0;
    while (ix < n - 1) {

        int ncur = nxtMove[cur];

        int d = 0, a = 0;
        if (ncur < cur) {
            // 한 바퀴 돌았다
            d += Dcnt[k - 1] - (cur ? Dcnt[cur - 1] : 0) + Dcnt[ncur];
            a += Acnt[k - 1] - (cur ? Acnt[cur - 1] : 0) + Acnt[ncur];
        }
        else {
            d += Dcnt[ncur] - (cur ? Dcnt[cur - 1] : 0);
            a += Acnt[ncur] - (cur ? Acnt[cur - 1] : 0);
        }

       // cout << ix << " | " << cur << ' ' << ncur << " => " << a << ' ' << d << '\n';
        if (A[ix + 1] > 0) {
            if (a < A[ix + 1]) {
                cout << "NO\n";
                return;
            }
        }
        else if (A[ix + 1] == -1) {
            if (d == 0) {
                cout << "NO\n";
                return;
            }
        }
        cur = (ncur + 1) % k;
        ix++;
    }
    cout << "YES\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
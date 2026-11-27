#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int ix = -1, tcnt = 0;
    for (int i = 30; i >= 0; i--) {
        int cnt = 0;

        for (auto j : A) cnt += ((j & (1 << i)) != 0);

        if (cnt & 1) {
            ix = i;
            tcnt = cnt;
            break;
        }
    }

    if (ix == -1) {
        cout << "Draw\n";
        return;
    }

    if (n % 2 == 0) {
        cout << "First\n";
        return;
    }

    if ((tcnt / 2) & 1) {
        cout << "Second\n";
        return;
    }

    for (auto& i : A) {
        if (i & (1 << ix)) i = 1;
        else i = 0;
    }

    /*
    for (auto i : A) cout << i << ' ';
    cout << '\n';
    */

    if (A[0] == 0 && A[n - 1] == 0) {
        cout << "Second\n";
        return;
    }

    if (A[0] == 1) {
        int l = 1, r = n - 1;

        bool ok = 1;
        while (l <= r) {
            int cntl = 0, cntr = 0;

            int li = l, ri = r;
            while (li <= r && A[li] == A[l]) cntl++, li++;
                
            while (ri >= li && A[ri] == A[r]) cntr++, ri--;

            if (A[l] == A[r]) {
                if ((cntl + cntr) & 1) {
                    ok = 0;
                    break;
                }
            }
            else {
                if ((cntl & 1) || (cntr & 1)) {
                    ok = 0;
                    break;
                }
            }
            l = li, r = ri;
        }

        if (ok) {
            cout << "First\n";
            return;
        }
    }

    if (A[n - 1] == 1) {
        int l = 0, r = n - 2;

        bool ok = 1;
        while (l <= r) {
            int cntl = 0, cntr = 0;

            int li = l, ri = r;
            while (li <= r && A[li] == A[l]) cntl++, li++;

            while (ri >= li && A[ri] == A[r]) cntr++, ri--;

            if (A[l] == A[r]) {
                if ((cntl + cntr) & 1) {
                    ok = 0;
                    break;
                }
            }
            else {
                if ((cntl & 1) || (cntr & 1)) {
                    ok = 0;
                    break;
                }
            }
            l = li, r = ri;
        }

        if (ok) {
            cout << "First\n";
            return;
        }
    }

    cout << "Second\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}
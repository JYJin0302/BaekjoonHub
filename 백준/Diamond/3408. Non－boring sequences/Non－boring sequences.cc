#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    map<int, int> idx;
    vector<int> L(n), R(n);

    for (int i = 0; i < n; i++) {
        L[i] = idx[A[i]] - 1;
        idx[A[i]] = i + 1;
    }

    idx.clear();

    for (int i = n - 1; i >= 0; i--) {
        if (idx[A[i]] == 0) R[i] = n;
        else R[i] = idx[A[i]];
        idx[A[i]] = i;
    }

    idx.clear();


    queue<pair<int, int>> q;
    q.push({ 0, n - 1 });
    bool ok = 0;
    while (!q.empty() && !ok) {
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        if (a >= b) continue;

        int fi = -1;

        int ta = a, tb = b;
        while (ta <= tb) {
            if (L[ta] < a && R[ta] > b) {
                fi = ta;
                break;
            }
            ta++;

            if (L[tb] < a && R[tb] > b) {
                fi = tb;
                break;
            }
            tb--;
        }

        if (fi == -1) ok = 1;
        else {
            q.push({ a, fi - 1 });
            q.push({ fi + 1, b });
        }
    }

    if (ok) cout << "boring\n";
    else cout << "non-boring\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
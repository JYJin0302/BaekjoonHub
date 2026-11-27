#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> A(n + 1);
    for (auto& i : A) {
        cin >> i;
    }

    int x;
    cin >> x;

    vector<int> tmp;
    for (int i = 0; i <= n; i++) {
        if (A[i] == 1) tmp.push_back(i);
    }

    if (tmp.size() > 2) {
        cout << "NO\n";
        return;
    }

    if (tmp.size() == 2) {
        if (tmp[0] + x == tmp[1]) {
            cout << "YES\n";
            cout << tmp[0] << ' ' << tmp[1];
        }
        else cout << "NO\n";
        return;
    }

    if (tmp.size() == 1) {
        if (tmp[0] + x <= n && A[tmp[0] + x] >= 1) {
            cout << "YES\n";
            cout << tmp[0] << ' ' << tmp[0] + x;
        }
        else if (tmp[0] - x >= 0 && A[tmp[0] - x] >= 3) {
            cout << "YES\n";
            cout << tmp[0] - x << ' ' << tmp[0];
        }
        else cout << "NO\n";
        return;
    }

    for (int i = 0; i + x <= n; i++) {
        if (A[i] >= 3 && A[i + x] >= 2) {
            cout << "YES\n";
            cout << i << ' ' << i + x;
            return;
        }
    }
    cout << "NO\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
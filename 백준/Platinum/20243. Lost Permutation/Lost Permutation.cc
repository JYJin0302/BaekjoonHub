#include<bits/stdc++.h>
using namespace std;


void solve() {

    int n;
    cin >> n;

    cout << "? ";
    for (int i = 1; i <= n; i++) {
        cout << i % n + 1 << ' ';
    }
    cout << endl;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    cout << "? 2 1 ";
    for (int i = 3; i <= n; i++) cout << i << ' ';
    cout << endl;

    vector<int> B(n);
    for (auto& i : B) cin >> i;

    vector<int> tmp;
    for (int i = 0; i < n; i++) if (B[i] != i + 1) tmp.push_back(i);

    int a = tmp[0], b = tmp[1];
    if (A[a] == b + 1) swap(a, b);

    vector<int> res = { b };
    for (int i = 0; i < n - 1; i++) {
        b = A[b] - 1;
        res.push_back(b);
    }
    cout << "! ";
    for (auto i : res) cout << i + 1 << ' ';
    cout << endl;
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

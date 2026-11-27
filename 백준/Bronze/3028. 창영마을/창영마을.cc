#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    vector<int> A(3);
    A[0] = 1;

    string s;
    cin >> s;

    for (auto f : s) {
        int v = f - 'A';
        int u = (v + 1) % 3;
        swap(A[u], A[v]);
    }

    for (int i = 0; i < 3; i++) {
        if (A[i] == 1) cout << i + 1 << '\n';
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
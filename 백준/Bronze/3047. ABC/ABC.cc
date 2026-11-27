#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    vector<int> A(3);
    for (auto& i : A) cin >> i;
    sort(all(A));

    string s;
    cin >> s;

    for (int i = 0; i < 3; i++) {
        int idx = s[i] - 'A';
        cout << A[idx] << ' ';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
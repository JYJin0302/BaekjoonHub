#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    vector<string> A(5);
    for (auto& i : A) cin >> i;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (A[j].size() > i) {
                cout << A[j][i];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
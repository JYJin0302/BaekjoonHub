#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    vector<int> A(10), B(10);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    int wA = 0, wB = 0;
    for (int i = 0; i < 10; i++) {
        if (A[i] > B[i]) wA++;
        else if (A[i] < B[i]) wB++;
    }

    if (wA > wB) cout << 'A';
    else if (wA < wB) cout << 'B';
    else cout << 'D';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
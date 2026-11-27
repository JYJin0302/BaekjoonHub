#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n), C(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;
    for (auto& i : C) cin >> i;

    vector<int> ord(n);
    for (int i = 0; i < n; i++) {
        ord[i] = i;
    }

    int ans = -1;
    do {

        int totK = 0;
        int totV = 0;

        for (int i = 1; i < n; i++) {

            totK = max(totK,  C[ord[i - 1]] * C[ord[i]]);
            totV += A[ord[i - 1]] * B[ord[i]];
        }

        if (totK <= k) {
            ans = max(ans, totV);
        }

    } while (next_permutation(ord.begin(), ord.end()));
    cout << ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solve() {

    int n;
    cin >> n;
    vector<int> A(10);
    for (int i = 0; i < 10; i++) A[i] = i;

    do {

        int v1 = 0, v2 = 0;
        for (int i = 0; i < 5; i++) v1 = v1 * 10 + A[i];
        for (int i = 5; i < 10; i++) v2 = v2 * 10 + A[i];
        if (v1 == v2 * 9) {
            n--;
            if (n == 0) {
                for (int i = 0; i < 10; i++) {
                    cout << A[i];
                    if (i == 4) cout << ' ';
                }
                break;
            }
        }
    } while (next_permutation(all(A)));


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
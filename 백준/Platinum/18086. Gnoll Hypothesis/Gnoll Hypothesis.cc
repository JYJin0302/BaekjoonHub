#include <bits/stdc++.h>
using namespace std;
using ld = long double;

ld comb(int n, int r) {

    if (r > n) return 0;
    ld res = 1;
    for (int i = 0; i < r; i++) {
        res *= n - i;
        res /= i+1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int n, k;
    cin >> n >> k;
    vector<ld> A(n);
    for(auto& i : A) cin >> i;

    if (k == 1) {

        for (int i = 0; i < n; i++) {
            cout << 100.0 / n << ' ';
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {

        ld res = 0;

        ld curr = A[i];
        ld p = 1;;

        int tx = i;
        for (int j = 0; j < n - 1; j++) {

            tx = (tx + n - 1) % n;
            res += comb(n - 2 - j, k - 2) * curr / comb(n, k);
            curr += A[tx];

        }

        cout << res << ' ';
    }


}

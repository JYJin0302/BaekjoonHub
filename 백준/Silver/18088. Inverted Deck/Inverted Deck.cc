#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int ix = 1;
    while (ix < n && A[ix] >= A[ix - 1]) ix++;

    if (ix == n) {
        cout << "1 1";
        return 0;
    }

    int nx = ix;
    while (nx < n && A[nx] <= A[nx - 1]) nx++;
    ix--;
    while (ix > 0 && A[ix] == A[ix - 1]) ix--;

    bool ok = 1;

    int l = ix, r = nx - 1;
    while (l < r) {
        swap(A[l], A[r]);
        l++, r--;
    }

    for (int i = 1; i < n; i++) if (A[i] < A[i - 1]) ok = 0;

    if (!ok) cout << "impossible";
    else cout << ix + 1 << ' ' << nx;
}

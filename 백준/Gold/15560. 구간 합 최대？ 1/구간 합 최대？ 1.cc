#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, q, u, v;
    cin >> n >> q >> u >> v;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A[i] = x * u + v;
    }

    while (q--) {
        int c, a, b;
        cin >> c >> a >> b;

        if (c == 0) {
            a--, b--;

            int maxx = A[a], curr = A[a];

            for (int i = a + 1; i <= b; i++) {
                curr = max(curr + A[i], A[i]);
                maxx = max(maxx, curr);
            }

            cout << maxx - v << '\n';
        }
        else {
            a--;
            A[a] = b * u + v;
        }
    }
}
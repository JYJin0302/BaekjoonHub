#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> A[i][j];

    sort(A.rbegin(), A.rend());

    vector<bool> far(m);

    bool ok = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 0) {
                far[j] = 1;
            }
            else if (far[j] == 1) {
                ok = 0;
            }
        }
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
}
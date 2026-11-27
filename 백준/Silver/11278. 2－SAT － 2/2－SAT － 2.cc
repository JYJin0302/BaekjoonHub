#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, n1, n2;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        a[i] = n1;
        b[i] = n2;
    }
    

    for (int i = 0; i < (1 << n ); i++) {
        bool ok = true;

        for (int j = 0; j < m; j++) {
            bool ta = (1 << (abs(a[j]) - 1)) & i;
            bool tb = (1 << (abs(b[j]) - 1)) & i;

            if (a[j] < 0) ta ^= 1;
            if (b[j] < 0) tb ^= 1;

            if (!(ta || tb)) {
                ok = false; break;
            }
        }

        if (ok) {
            cout << 1 << '\n';
            for (int k = 0; k <= n - 1; k++) {
                cout << (((1 << k) & i) > 0) << ' ';
            }
            return 0;
        }
    }
    cout << 0;


}
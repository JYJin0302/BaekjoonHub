#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {

    int n, m;
    cin >> n >> m;

    string s;
    bool b;

    vector<string> A(m);
    vector<bool> B(m);

    for (int i = 0; i < m; i++) {
        cin >> s >> b;
        A[i] = s;
        B[i] = b;
    }

    vector<tuple<int, bool, bool>> q;
    vector<bool> used(m);

    int cnt = m+3;
    while (cnt--) {
        bool found = 0;

        for (int i = 0; i < n; i++) {

            vector<int> tmp(4);
            for (int j = 0; j < m; j++) {
                if (used[j]) continue;
                int t1 = 2 * (A[j][i] - '0') + B[j];
                tmp[t1]++;
            }
            if (tmp[0] + tmp[1] + tmp[2] + tmp[3] == 0) continue;


            int ai = -1;
            if (tmp[1] != 0 && tmp[0] == 0) {
                found = 1;
                ai = 1;
                q.push_back({ i, 0, 1 });
            }
            else if (tmp[1] == 0 && tmp[0] != 0) {
                found = 1;
                ai = 0;
                q.push_back({ i, 0, 0 });
            }
            else if (tmp[2] == 0 && tmp[3] != 0) {
                found = 1;
                ai = 3;
                q.push_back({ i, 1, 1 });
            }
            else if (tmp[3] == 0 && tmp[2] != 0) {
                found = 1;
                ai = 2;
                q.push_back({ i, 1, 0 });
            }

            if (found) {

                for (int j = 0; j < m; j++) {
                    if (!used[j] && (2 * (A[j][i] -'0') + B[j] == ai)) {
                        used[j] = 1;
                    }
                }

                break;
            }

        }

        if (!found) break;
    }


    bool ok = 1;
    for (int i = 0; i < m; i++) if (!used[i]) {
        ok = 0;
    }

    if (ok) cout << "OK\n";
    else cout << "LIE\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[101][101];
vector<string> ans;

void solve() {

    ans.clear();
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    bool ok = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            int ti = n - 1 - i;
            int tj = m - 1 - j;

            bool tok = 0;
            if (A[i][j] == i * m + j) tok = 1;
            if (A[i][j] == ti * m + j) tok = 1;
            if (A[i][j] == i * m + tj) tok = 1;
            if (A[i][j] == ti * m + tj) tok = 1;

            if (!tok) ok = 0;
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    auto toS = [](char c, int n) {
        string res;
        res += c;
        res += to_string(n);
        return res;
    };

    int tl = (n - 1) / 2, tr = (m - 1) / 2;

    if (n & 1) {
        bool ok = 1;
        int i = tl;
        for (int j = 1; j < m; j++) {
            if (A[i][j - 1] + 1 != A[i][j]) ok = 0;
        }
        if (!ok) {
            for (int j = 0; j * 2 < m; j++) {
                swap(A[i][j], A[i][m - 1 - j]);
            }
            string tmp = "R";
            tmp += to_string(n / 2 + 1);
            ans.push_back(tmp);
        }
        ok = 1;
        for (int j = 1; j < m; j++) {
            if (A[i][j - 1] + 1 != A[i][j]) ok = 0;
        }

        if (!ok) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        tl--;
    }
    if (m & 1) {
        bool ok = 1;
        int i = tr;
        for (int j = 1; j < n; j++) {
            if (A[j - 1][i] + m != A[j][i]) ok = 0;
        }
        if (!ok) {
            for (int j = 0; j * 2 < n; j++) {
                swap(A[j][i], A[n - 1 - j][i]);
            }
            string tmp = "C";
            tmp += to_string(m / 2 + 1);
            ans.push_back(tmp);
        }
        ok = 1;
        for (int j = 1; j < n; j++) {
            if (A[j - 1][i] + m != A[j][i]) ok = 0;
        }

        if (!ok) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        tr--;
    }

    for (int i = tl; i >= 0; i--) {
        for (int j = tr; j >= 0; j--) {
            //if (i == tl && j == tr) continue;

            int ni = n - 1 - i;
            int nj = m - 1 - j;

            int n1 = i * m + j;
            int n2 = i * m + nj;
            int n3 = ni * m + j;
            int n4 = ni * m + nj;

            if (A[ni][nj] == n1) {
                ans.push_back(toS('C', nj + 1));
                ans.push_back(toS('R', i + 1));
                ans.push_back(toS('C', nj + 1));
                ans.push_back(toS('R', i + 1));

                A[ni][nj] = A[i][j];
                A[i][j] = A[i][nj];
                A[i][nj] = n1;
            }

            if (A[i][nj] == n1) {
                ans.push_back(toS('C', nj + 1));
                ans.push_back(toS('R', i + 1));
                ans.push_back(toS('C', nj + 1));
                ans.push_back(toS('R', i + 1));

                A[i][nj] = A[ni][nj];
                A[ni][nj] = A[i][j];
                A[i][j] = n1;
            }
            else if (A[ni][j] == n1) {
                ans.push_back(toS('R', ni + 1));
                ans.push_back(toS('C', j + 1));
                ans.push_back(toS('R', ni + 1));
                ans.push_back(toS('C', j + 1));

                A[ni][j] = A[ni][nj];
                A[ni][nj] = A[i][j];
                A[i][j] = n1;
            }

            if (A[ni][j] == n2) {
                ans.push_back(toS('C', nj + 1));
                ans.push_back(toS('R', ni + 1));
                ans.push_back(toS('C', nj + 1));
                ans.push_back(toS('R', ni + 1));

                A[ni][j] = A[ni][nj];
                A[ni][nj] = A[i][nj];
                A[i][nj] = n2;
            }
            else if (A[ni][nj] == n2) {
                ans.push_back(toS('R', ni + 1));
                ans.push_back(toS('C', nj + 1));
                ans.push_back(toS('R', ni + 1));
                ans.push_back(toS('C', nj + 1));

                A[ni][nj] = A[ni][j];
                A[ni][j] = A[i][nj];
                A[i][nj] = n2;
            }

            if (j == tr) {
                if (A[ni][j] > A[ni][nj]) {
                    ans.push_back(toS('R', ni + 1));
                    for (int j = 0; j * 2 < m; j++) {
                        swap(A[ni][j], A[ni][m - 1 - j]);
                    }
                }
            }
        }
    }

    vector<int> fin;
    for (int j = tr; j >= 0; j--) {
        if (A[n - 1][j] != (n - 1) * m + j) {
            // need operation 
            fin.push_back(j);
        }
    }

    if (!fin.empty()) {

        for (auto i : fin) {
            ans.push_back(toS('C', m - i));
            for (int j = tl; j >= 0; j--) swap(A[j][m - 1 - i], A[n - 1 - j][m - 1 - i]);
        }

        for (int i = tl; i >= 0; i--) {
            ans.push_back(toS('R', n - i));
            for (int j = tr; j >= 0; j--) swap(A[n - 1 - i][j], A[n - 1 - i][m - 1 - j]);
        }
        for (auto i : fin) {
            ans.push_back(toS('C', m - i));
            for (int j = tl; j >= 0; j--) swap(A[j][m - 1 - i], A[n - 1 - j][m - 1 - i]);
        }
        for (int i = tl; i >= 0; i--) {
            ans.push_back(toS('R', n - i));
            for (int j = tr; j >= 0; j--) swap(A[n - 1 - i][j], A[n - 1 - i][m - 1 - j]);
        }
        for (auto i : fin) {
            ans.push_back(toS('C', m - i));
            for (int j = tl; j >= 0; j--) swap(A[j][m - 1 - i], A[n - 1 - j][m - 1 - i]);
        }
    }
    ok = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != i * m + j) ok = 0;
            // cout << A[i][j] << ' ';
        }
        //cout << '\n';
    }
    // cout << "RES: ";


    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << "POSSIBLE " << ans.size() << ' ';
    for (auto i : ans) cout << i << ' ';
    cout << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

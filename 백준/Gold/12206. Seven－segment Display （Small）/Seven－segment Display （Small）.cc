#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair


bool C[10][7];

void solve() {

    int n;
    cin >> n;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    vector<int> res;
    vector<int> nst;
    for (int i = 0; i <= 9; i++) {

        bool ok = 1;
        vector<int> st(7, -1);

        for (int j = 0; j < n; j++) {
            int val = (i - j + 10) % 10;

            for (int f = 0; f < 7; f++) {
                if (C[val][f]) {
                    int ret = A[j][f] - '0';
                    if (st[f] == -1 || st[f] == ret) st[f] = ret;
                    else ok = 0;
                }
                else if (A[j][f] == '1') ok = 0;
            }
        }

        if (ok) {
            res.push_back(i);
            nst = st;
        }

    }


    if (res.size() != 1) {
        cout << "ERROR!\n";
        return;
    }

    int val = (res[0] - n + 10) % 10;
    for (int i = 0; i < 7; i++) {
        if (C[val][i] && nst[i] == -1) {
            cout << "ERROR!\n";
            return;
        }

    }
    for (int i = 0; i < 7; i++) {
        if (!C[val][i] || nst[i] == 0) cout << 0;
        else cout << 1;
    }
    cout << '\n';

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 6; i++) C[0][i] = 1;
    C[1][1] = C[1][2] = 1;

    for (int i = 0; i < 7; i++) C[2][i] = 1;
    C[2][2] = C[2][5] = 0;

    for (int i = 0; i < 7; i++) C[3][i] = 1;
    C[3][4] = C[3][5] = 0;

    C[4][1] = C[4][2] = C[4][5] = C[4][6] = 1;

    for (int i = 0; i < 7; i++) C[5][i] = 1;
    C[5][1] = C[5][4] = 0;

    for (int i = 0; i < 7; i++) C[6][i] = 1;
    C[6][1] = 0;

    C[7][0] = C[7][1] = C[7][2] = 1;

    for (int i = 0; i < 7; i++) C[8][i] = 1;

    for (int i = 0; i < 7; i++) C[9][i] = 1;
    C[9][4] = 0;

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int L[101][101], R[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, h;
    cin >> n >> m >> h;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            L[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            char c;
            cin >> c;
            R[i][j] = c - '0';
        }
    }

    vector<tuple<int, int, int>> ansG, ansL;
    for (int i = 0; i < n; i++) {

        int cnt0 = 0, cnt1 = 0;
        vector<int> pos1, pos2;
        for (int j = 0; j < m; j++) {
            cnt0 += L[i][j];
            if(L[i][j] == 1) pos1.push_back(j);
        }
        for (int j = 0; j < h; j++) {
            cnt1 += R[i][j];
            if (R[i][j] == 1) pos2.push_back(j);  
        }

        if ((cnt0 > 0) ^ (cnt1 > 0)) {
            cout << -1;
            return 0;
        }

        for (auto j : pos1) {
            for (auto k : pos2) {
                ansG.push_back({ i, j, k });
            }
        }

        int c0 = 0, c1 = 0;
        while (c0 < pos1.size() && c1 < pos2.size()) {

            ansL.push_back({ i, pos1[c0], pos2[c1] });
            int rm = pos1.size() - c0;
            int r2 = pos2.size() - c1;

            if (rm == r2) {
                c0++, c1++;
            }
            else if (rm > r2) c0++;
            else c1++;

        }

    }

    cout << ansG.size() << '\n';
    for (auto i : ansG) {
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << '\n';
    }
    swap(ansG, ansL);
    cout << ansG.size() << '\n';
    for (auto i : ansG) {
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << '\n';
    }


}

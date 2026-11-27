#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int colL[1010], colR[1010];
int rowL[1010], rowR[1010];

void solve() {

    int x1, y1, a;
    int x2, y2, b;
    cin >> x1 >> y1 >> a;
    cin >> x2 >> y2 >> b;

    int m, k;
    cin >> m >> k;

    vector<pair<int, int>> A, B;
    memset(colL, -1, sizeof(colL));
    memset(colR, -1, sizeof(colR));
    memset(rowL, -1, sizeof(rowL));
    memset(rowR, -1, sizeof(rowR));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        int ta = a - x1;
        int tb = b - y1;

        if (colL[ta] == -1) colL[ta] = tb;
        else colL[ta] = min(colL[ta], tb);
        if (rowL[tb] == -1) rowL[tb] = ta;
        else rowL[tb] = min(rowL[tb], ta);

        colR[ta] = max(colR[ta], tb);
        rowR[tb] = max(rowR[tb], ta);
    }

    for (int i = 0; i <= a; i++) {
        if (colL[i] != -1) A.push_back(mp(i, colL[i]));
        if (colR[i] != -1) A.push_back(mp(i, colR[i]));
        if (rowL[i] != -1) A.push_back(mp(rowL[i], i));
        if (rowR[i] != -1) A.push_back(mp(rowR[i], i));
    }
    sort(all(A));
    A.erase(unique(all(A)), A.end());

    memset(colL, -1, sizeof(colL));
    memset(colR, -1, sizeof(colR));
    memset(rowL, -1, sizeof(rowL));
    memset(rowR, -1, sizeof(rowR));

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        int ta = a - x2;
        int tb = b - y2;

        if (colL[ta] == -1) colL[ta] = tb;
        else colL[ta] = min(colL[ta], tb);
        if (rowL[tb] == -1) rowL[tb] = ta;
        else rowL[tb] = min(rowL[tb], ta);

        colR[ta] = max(colR[ta], tb);
        rowR[tb] = max(rowR[tb], ta);
    }

    for (int i = 0; i <= b; i++) {
        if (colL[i] != -1) B.push_back(mp(i, colL[i]));
        if (colR[i] != -1) B.push_back(mp(i, colR[i]));
        if (rowL[i] != -1) B.push_back(mp(rowL[i], i));
        if (rowR[i] != -1) B.push_back(mp(rowR[i], i));
    }
    sort(all(B));
    B.erase(unique(all(B)), B.end());

    ll ans = 1e16;
    int ti = -1, tj = -1;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {

            ll tx = A[i].first + x1 - B[j].first - x2;
            ll ty = A[i].second + y1 - B[j].second - y2;

            if (ans > tx * tx + ty * ty) {
                ans = tx * tx + ty * ty;
                ti = i, tj = j;
            }

        }
    }

    cout << ans << '\n';
    cout << A[ti].first +x1 << ' ' << A[ti].second +y1<< '\n' << B[tj].first+x2 << ' ' << B[tj].second+y2 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
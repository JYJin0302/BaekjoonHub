#include <bits/stdc++.h>
using namespace std;

int R[202020];
int getR(int x) {
    if (R[x] == x) return x;
    return R[x] = getR(R[x]);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 2*n+10; i++) R[i] = i;

    vector<bool> used(2*n + 1);
    vector<pair<char, int>> A;
    for (int i = 0; i < m; i++) {
        char c;
        string s;
        int x;
        cin >> c >> s >> x;
        A.push_back({ c, x });
        used[x] = 1;
        R[x] = x + 1;
    }


    if (!used[1]) {
        cout << "NO";
        return 0;
    }

    vector<int> addNum(m);

    for (int i = 1; i < m; i++) {
        if (A[i].first != A[i - 1].first) continue;
        if (addNum[i - 1] != 0) continue;
        int f = getR(A[i - 1].second);
        if (f == n*2+1) {
            cout << "NO";
            return 0;
        }
        addNum[i-1] = f;
        R[f] = f + 1;
    }
    if (A[m - 1].first == 'A') {
        int f = getR(A[m - 1].second);
        if (f == n*2+1) {
            cout << "NO";
            return 0;
        }
        addNum[m-1] = f;
        R[f] = f + 1;
    }

    int ls = getR(1);
    int ix = -1;

    if (ls != n*2+1) {
        int mval = ls;
        ix = 0;
        while (ix < m) {
            if (A[ix].second < mval && addNum[ix] < mval) break;
            ix++;
        }
        if (ix == m) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        cout << A[i].first << " BLOCK " << A[i].second << '\n';
        char curr = A[i].first;
        if (addNum[i] != 0) {
            curr = char('A' + 'B' - curr);
            cout << curr << " CHAIN " << addNum[i] << '\n';
        }
        if (i == ix) {
            while (ls <= n*2) {
                curr = char('A' + 'B' - curr);
                cout << curr << " CHAIN " << ls << '\n';
                R[ls] = ls + 1;
                ls = getR(ls);
            }
        }
    }

}
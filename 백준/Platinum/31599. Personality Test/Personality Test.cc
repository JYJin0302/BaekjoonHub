#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int cnt[5010][5010];

void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    int ansb = n;
    for (int i = 0; i < m; i++) {
        vector<vector<int>> idxList(26);
        for (int j = 0; j < n; j++) {
            if (A[j][i] != '.' && j < ansb) {
                idxList[A[j][i] - 'A'].push_back(j);
            }
        }

        for (int j = 0; j < 26; j++) {
            int sz = idxList[j].size();

            for (int a = 0; a < sz; a++) {
                for (int b = a + 1; b < sz; b++) {
                    int ta = idxList[j][a];
                    int tb = idxList[j][b];
                    cnt[ta][tb]++;
                    if (cnt[ta][tb] == k) {
                        ansb = min(ansb, tb);
                    }
                }
            }
        }
    }
    if (ansb == n) {
        cout << -1;
        return;
    }

    int ansa = 0;
    for (int i = 1; i < ansb; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (A[i][j] != '.' && A[i][j] == A[ansb][j]) cnt++;
        }
        if (cnt >= k) ansa = i;
    }
    cout << ansa + 1 << ' ' << ansb + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}
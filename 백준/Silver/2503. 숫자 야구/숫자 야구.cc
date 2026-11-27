#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n;
int num[111], S[111], B[111];

int ans = 0;
int choose[3];

bool check() {

    for (int i = 0; i < n; i++) {
        string s = to_string(num[i]);
        vector<int> v = { s[0] - '0', s[1] - '0', s[2] - '0' };

        int sCnt = 0, bCnt = 0;
        for (int j = 0; j < 3; j++) {
            if (v[j] == choose[j]) sCnt++;
            else {
                for (int k = 0; k < 3; k++){
                    if (v[k] == choose[j]) {
                        bCnt++;
                        break;
                    }
                }
            }
        }
        if (sCnt != S[i] || bCnt != B[i]) return 0;
    }
    return 1;

}

void goSolve(int cnt = 0) {
    if (cnt == 3) {
        if (check()) ans++;
        return;
    }
    for (int i = 1; i <= 9; i++) {
        bool ok = 1;
        for (int j = 0; j < cnt; j++) if (choose[j] == i) ok = 0;

        if (ok) {
            choose[cnt] = i;
            goSolve(cnt + 1);
        }
    }

}

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i] >> S[i] >> B[i];

    goSolve();
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
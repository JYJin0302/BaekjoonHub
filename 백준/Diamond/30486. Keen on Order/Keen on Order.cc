#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int n, k;
int nxt[303][303];

int dp[1 << 24];

vector<int> ans;
void solve() {

    cin >> n >> k;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    if (k * (k+1)/2 > n) {
        set<int> st;
        for (int i = 1; i <= k; i++) st.insert(i);
        vector<bool> used(k + 1);

        int ix = 0;
        for (int f = 0; f < k; f++) {
            vector<bool> chk(k + 1);

            int target = st.size();
            int cnt = 0;

            while (ix < n) {
                if (!chk[A[ix]] && !used[A[ix]]) cnt++;
                chk[A[ix]] = 1;

                if (cnt == target) {
                    st.erase(A[ix]);
                    used[A[ix]] = 1;
                    cout << A[ix++] << ' ';
                    break;
                }
                ix++;
            }
            if (ix == n) break;
        }
        for (auto f : st) cout << f << ' ';

        return;
    }

    vector<int> pos(k + 1, n+1);

    for (int i = n; i >= 0; i--) {
        for (int j = 1; j <= k; j++) nxt[i][j] = pos[j];
        if (i) pos[A[i-1]] = i;
    }

    for (int i = 1; i <= k; i++) {
        dp[1 << (i - 1)] = nxt[0][i];
    }

    int brk = (1 << k) - 1;
    for (int j = 1; j < (1 << k); j++) {
        if (dp[j] == 0) {
            int res = 0;
            for (int i = 0; i < k; i++) {
                if (j & (1 << i)) {
                    int nmask = j ^ (1 << i);
                    int tres = dp[nmask];
                    if (tres == n + 1) res = n + 1;
                    else res = max(res, nxt[tres][i + 1]);
                }
                if (res == n + 1) break;
            }
            dp[j] = res;
            if (res == n + 1) {
                brk = j;
                break;
            }
        }
    }
    int res = dp[brk];
    if (res != n+1) {
        cout << "*";
    }
    else {
        int tmp = brk;
        for (int i = 0; i < k; i++) {
            if (tmp & (1 << i)) {}
            else ans.push_back(i + 1);
        }
        while (tmp) {
            pair<int, int> res = { -1, 0 };
            for (int i = 0; i < k; i++) {
                if (tmp & (1 << i)) {
                    int tt = dp[tmp ^ (1 << i)];
                    if (tt != n + 1) tt = nxt[tt][i + 1];
                    res = max(res, mp(tt, i));
                }
                if (res.first == n + 1) break;
            }

            ans.push_back(res.second + 1);
            tmp ^= (1 << res.second);
        }
        for (auto f = ans.rbegin(); f != ans.rend(); f++) cout << *f << ' ';
        return;
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
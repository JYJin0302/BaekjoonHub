#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int A[505];
vector<int> able[505];

int dp[505][505];
int getDp(int l, int r) {

    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 0;
    if (l + 1 == r) return dp[l][r] = 1;

    int sz = r - l + 1;
    vector<int> res(sz);
    for (int j = l; j < r; j++) {
        res[j - l] = getDp(l, j) + getDp(j + 1, r);
    }

    vector<int> cost(sz), cost2(sz);
    vector<int> cnt(505);

    int curr = A[l];
    for (int j = l + 1; j <= r; j++) {
        if (A[j] < curr) {
            cost[0]++;
            cnt[A[j]]++;
        }
    }
    for (int j = l + 1; j < r; j++) {
        cost[j - l] = cost[j - l - 1];
        if (A[j] < curr) {
            while (curr > A[j]) {
                cost[j - l] -= cnt[curr--];
            }
            cost[j - l]--;
            cnt[curr] = 0;
        }
    }


    // reverse
    cnt = vector<int>(505, 0);
    curr = A[r];
    for (int j = l; j < r; j++) {
        if (A[j] < curr) {
            cost2[r - l - 1]++;
            cnt[A[j]]++;
        }
    }

    for (int i = r - 1; i > l; i--) {
        cost2[i - l - 1] = cost2[i - l];
        if (A[i] < curr) {
            while (curr > A[i]) {
                cost2[i - l - 1] -= cnt[curr--];
            }
            cost2[i - l - 1]--;
            cnt[curr] = 0;
        }
    }

    int ans = 1e7;
    for (int i = 0; i < sz - 1; i++) {
        ans = min(ans, res[i] + sz - max(cost[i], cost2[i]));
    }

    // cout << "REs: " << l << ' ' << r << " -> " << ans << '\n';
    return dp[l][r] = ans;
}


void solve() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> A[i];

    for (int j = n; j >= 1; j--) {
        vector<int> cnt(505);
        int curr = 1;
        for (int i = 0; i < j; i++) {
            cnt[A[j - i]]++;
            if (cnt[A[j - i]] == 2) break;
            while (cnt[curr]) curr++;

            if (curr == i + 2) {
                // ok
                able[j].push_back(j - i);
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    vector<int> ans(n + 10, 1e7);
    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto f : able[i]) if (ans[f - 1] != 1e7) {
            ans[i] = min(ans[i], ans[f - 1] + getDp(f, i));
        }
        //cout << ans[i] << ' ';
    }

    if (ans[n] == 1e7) cout << "impossible\n";
    else cout << ans[n];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
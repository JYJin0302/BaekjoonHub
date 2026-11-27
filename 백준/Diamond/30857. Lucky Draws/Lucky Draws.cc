#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int cnt2[20002][20002];
int cnt[20002];
int sz;

vector<int> num;
int getIdx(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

vector<int> dp, pv;

int C(int l, int r) {
    int res = cnt2[l][sz - 1] - cnt2[l][r - 1];
    return res;
}

void getAns(int l, int r, int ansl, int ansr) {
    if (l > r) return;

    int mid = (l + r) >> 1;

    pair<int, int> ans = { -1e9, -1 };
    for (int i = ansl; i <= min(mid, ansr); i++) {
        int newVal = pv[i] + cnt[mid] - C(i, mid);
        ans = max(ans, mp(newVal, i));
    }

    dp[mid] = ans.first;
    getAns(l, mid - 1, ansl, ans.second);
    getAns(mid + 1, r, ans.second, ansr);
}

void solve() {

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        num.push_back(l);
        num.push_back(r);
        A[i] = mp(l, r);
    }
    num.push_back(-1e9);

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());


    for (auto& i : A) {
        i.first = getIdx(i.first);
        i.second = getIdx(i.second);

        cnt2[i.first][i.second]++;
        cnt[i.first]++;
        cnt[i.second + 1]--;
    }

    sz = num.size();
    for (register int i = 1; i < sz; i++) {
        for (register int j = 1; j < sz; j++) {
            cnt2[i][j] += cnt2[i - 1][j] + cnt2[i][j - 1] - cnt2[i - 1][j - 1];
        }
        cnt[i] += cnt[i - 1];
    }

    dp = vector<int>(sz);
    pv = vector<int>(sz);
    for (int i = 0; i < k; i++) {
        getAns(1, sz - 1, 0, sz - 1);
        //for (int f = 1; f < sz; f++) dp[f] = max(dp[f], dp[f - 1]);
        swap(dp, pv);
    }

    cout << *max_element(pv.begin(), pv.end());

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

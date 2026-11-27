#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Data {
    string s;
    int val, pmax;

    bool operator<(Data& d) {
        return s < d.s;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> A(n);
    for(auto& i : A) cin >> i;

    vector<Data> dp;

    for (int i = 1; i < (1 << A[0].size()); i++) {
        string res;
        int cnt = 0;
        for (int j = 0; j < A[0].size(); j++) {
            if (i & (1 << j)) {
                res += A[0][j];
                cnt++;
            }
        }
        dp.push_back({ res, cnt, cnt });
    }

    sort(dp.begin(), dp.end());
    for (int i = 1; i < dp.size(); i++) dp[i].pmax = max(dp[i].pmax, dp[i - 1].pmax);

    for (int k = 1; k < n; k++) {

        vector<Data> tmp;
        for (int i = 1; i < (1 << A[k].size()); i++) {
            string res;
            int cnt = 0;
            for (int j = 0; j < A[k].size(); j++) {
                if (i & (1 << j)) {
                    res += A[k][j];
                    cnt++;
                }
            }
            tmp.push_back({ res, cnt, cnt });
        }
        sort(tmp.begin(), tmp.end());

        int ansx = 0;

        for (int i = 0; i < tmp.size(); i++) {
            while (ansx < dp.size() && dp[ansx].s < tmp[i].s) ansx++;

            if (ansx == 0) {
                tmp[i].val = -1e7;
                tmp[i].pmax = -1e7;
            }
            else {
                tmp[i].val += dp[ansx - 1].pmax;
                tmp[i].pmax = tmp[i].val;
            }
        }

        for (int i = 1; i < tmp.size(); i++) tmp[i].pmax = max(tmp[i].pmax, tmp[i - 1].pmax);
        swap(dp, tmp);
        tmp.clear();
    }

    int ans = dp.back().pmax;
    if (ans < 0) ans = -1;
    cout << ans;

}
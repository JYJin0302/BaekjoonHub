#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair



void solve() {

    int L, K, C;
    cin >> L >> K >> C;

    vector<int> A(K);
    for (auto& i : A) cin >> i;

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    vector<int> len;
    int curr = 0;
    for (auto i : A) {
        len.push_back(i - curr);
        curr = i;
    }
    len.push_back(L - curr);

    int n = len.size();

    int l = *max_element(len.begin(), len.end()), r = L;
    pair<int, int> ans = { 1e9, 1e9 };

    reverse(len.begin(), len.end());
    while (l <= r) {
        int md = (l + r) >> 1;

        int curr = 0, cnt = 0;
        for (auto f : len) {
            curr += f;
            if (curr > md) {
                curr = f;
                cnt++;
            }
        }

        if (cnt < C) {
            curr = len.back();
        }

        if (cnt <= C) {
            ans = min(ans, mp(md, curr));
            r = md - 1;
        }
        else l = md + 1;
    }
    cout << ans.first << ' ' << ans.second;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}

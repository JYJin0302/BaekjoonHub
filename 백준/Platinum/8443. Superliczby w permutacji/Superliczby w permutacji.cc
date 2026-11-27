#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<int, int>> rec[101010];

void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> res = { 0 };
    for (int i = 0; i < n; i++) {
        int f = A[i];
        int iter = lower_bound(all(res), f) - res.begin();
        if (iter == res.size()) {
            res.push_back(f);
        }
        else {
            res[iter] = f;
        }
        rec[iter].push_back(mp(f, i));
    }


    int sz = res.size();
    // for (int i = 0; i < sz; i++) reverse(all(rec[i]));

    queue<pair<int, int>> q, tmp;
    for (auto f : rec[sz - 1]) q.push(f);

    vector<int> ans;

    int cur = sz - 1;
    while (cur) {

        int ix = 0;
        int tsz = rec[cur - 1].size();

        //cout << "Cur: " << cur << '\n';
        while (!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            //cout << "(" << a << ' ' << b << ") ";
            ans.push_back(a);
            while (ix < tsz && rec[cur - 1][ix].x >= a) ix++;
            while (ix < tsz && (rec[cur - 1][ix].x < a && rec[cur - 1][ix].y < b)) {
                tmp.push(rec[cur - 1][ix]);
                ix++;
            }
        }
        //cout << '\n';

        swap(tmp, q);
        cur--;
    }

    sort(all(ans));
    cout << ans.size() << '\n';
    for (auto f : ans) cout << f << ' ';
    cout << '\n';



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
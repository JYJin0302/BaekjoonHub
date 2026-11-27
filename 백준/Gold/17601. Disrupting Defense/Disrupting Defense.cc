#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int cnt[1010];
bool used[1010];

void solve() {

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(mp(x, i));
        cnt[x]++;
    }

    vector<pair<int, int>> ans;
    int nd = n;
    while (nd) {

        vector<pair<int, int>> lst;
        for (int i = 0; i < n; i++) {
            if (!used[i]) lst.push_back(A[i]);
        }

        int sz = lst.size();
        pair<int, int> ret = mp(-1, -1);
        for (int j = 0; j < sz; j++) {
            if (lst[j].x != lst[(j+1)%sz].x) ret = max(ret, mp(cnt[lst[j].x] + cnt[lst[(j+1)% sz].x], j));
        }

        if (ret.x == -1) {
            cout << -1;
            return;
        }
        int a = lst[ret.y].y;
        int b = lst[(ret.y + 1) % sz].y;
        used[a] = 1;
        used[b] = 1;
        cnt[A[a].x]--;
        cnt[A[b].x]--;
        ans.push_back(mp(a, b));
        nd -= 2;
    }

    for (auto& [a, b] : ans) {
        cout << a + 1 << ' ' << b + 1 << '\n';
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
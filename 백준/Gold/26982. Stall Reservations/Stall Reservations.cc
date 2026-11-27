#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    int n;
    cin >> n;

    
    vector<pair<int, int>> A;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        A.push_back(mp(a, -i));
        A.push_back(mp(b, i));
    }
    sort(all(A));

    vector<int> ans(n + 1);
    int cur = 0;
    queue<int> lst;

    for (auto& i : A) {
        auto [a, b] = i;
        if (b < 0) {
            b *= -1;
            if (lst.empty()) {
                cur++;
                ans[b] = cur;
            }
            else {
                int c = lst.front(); lst.pop();
                ans[b] = c;
            }
        }
        else {
            lst.push(ans[b]);
        }
    }

    cout << cur << '\n';
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair


void solve() {

    int n;
    cin >> n;

    vector<int> cnt(1050);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 0) cnt[x]++;
        else {
            x *= -1;
            int cur = 1024;
            while (cur >= 1) {
                while (x >= cur && cnt[cur] >= 1) {
                    x -= cur;
                    cnt[cur]--;
                    cout << cur << ' ';
                }
                cur >>= 1;
            }
            cout << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
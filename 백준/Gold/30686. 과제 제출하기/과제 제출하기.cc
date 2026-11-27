#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

vector<int> nd[8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            x--;
            nd[i].push_back(x);
        }
    }

    vector<int> ord(m);
    for (int i = 0; i < m; i++) ord[i] = i;

    int ans = 1e8;
    do {

        int res = 0;
        vector<int> lst(n, -1);

        for (int i = 0; i < m; i++) {
            for (auto f : nd[ord[i]]) {
                if (lst[f] == -1 || lst[f] + d[f] <= i) {
                    res++;
                    lst[f] = i;
                }
            }
        }

        ans = min(ans, res);
    } while (next_permutation(ord.begin(), ord.end()));
    cout << ans;
}

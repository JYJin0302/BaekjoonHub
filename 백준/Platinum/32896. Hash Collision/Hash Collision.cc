#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;

    int bn = 450;

    int s;
    cout << "? " << n << ' ' << 1 << endl;
    cin >> s;

    int ts = s;

    vector<int> nxt(n + 1);
    vector<int> res(n + 1, -1);
    res[s] = 0;
    nxt[0] = s;

    int len = -1;
    for (int i = 1; i <= bn; i++) {
        cout << "? " << 1 << ' ' << s << endl;
        cin >> nxt[i];

        if (res[nxt[i]] != -1) {
            // found
            len = i - res[nxt[i]];
            break;
        }
        res[nxt[i]] = i;
        s = nxt[i];
    }

    int cur = s;
    int cnt = bn;
    while (len == -1){
        cout << "? " << bn << ' ' << cur << endl;
        cnt += bn;
        int x;
        cin >> x;

        if (res[x] != -1) {
            len = abs(cnt - res[x]);
        }
        else {
            res[x] = cnt;
            cur = x;
        }
    }

    assert(len <= n);

    cout << "? " << len - ts % len << ' ' << ts << endl;
    int r;
    cin >> r;

    cout << "! " << ts << ' ' << r << endl;

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
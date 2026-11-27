#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int cnt[2][101010];
int root[101010];
int col[101010];
vector<int> st[101010];
bool impo[101010];
int sw[101010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

set<pair<int, int>> R, B;

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        col[i] = x;
        cnt[x][i]++;
        root[i] = i;
        st[i].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        R.insert(mp(cnt[0][i], i));
        B.insert(mp(cnt[1][i], i));
    }

    while (q--) {

       /* cout << "CUR : \n";
        for (int i = 1; i <= n; i++) {
            cout << i << ' ' << sw[i] << " | ";
            for (auto f : st[i]) cout << f << ' ';
            cout << '\n';
        }

        for (int i = 1; i <= n; i++) cout << col[i] << ' ';
        cout << '\n';
        */

        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;

            int ta = find(a);
            int tb = find(b);
            if (ta > tb) {
                swap(ta, tb);
                swap(a, b);
            }
            int cA = col[a] ^ sw[ta];
            int cB = col[b] ^ sw[tb];

            if (ta == tb) {
                if (cA == cB && !impo[ta]) {
                    R.erase(R.find(mp(cnt[0][ta], ta)));
                    B.erase(B.find(mp(cnt[1][ta], ta)));
                    impo[ta] = 1;
                }
            }
            else {
                // union

                root[tb] = ta;
                if (!impo[ta]) {
                    R.erase(R.find(mp(cnt[0][ta], ta)));
                    B.erase(B.find(mp(cnt[1][ta], ta)));
                }
                if (!impo[tb]) {
                    R.erase(R.find(mp(cnt[0][tb], tb)));
                    B.erase(B.find(mp(cnt[1][tb], tb)));
                }
                if (impo[ta] || impo[tb]) {
                    impo[ta] = 1;
                    continue;
                }


                if (cA == cB) {
                    if (cnt[0][ta] + cnt[1][ta] < cnt[0][tb] + cnt[1][tb]) {
                        sw[ta] ^= 1;
                        swap(cnt[0][ta], cnt[1][ta]);
                    }
                    else {
                        sw[tb] ^= 1;
                        swap(cnt[0][tb], cnt[1][tb]);
                    }
                }

                cnt[0][ta] += cnt[0][tb];
                cnt[1][ta] += cnt[1][tb];

                if (st[ta].size() < st[tb].size()) {
                    for (auto f : st[ta]) {
                        col[f] ^= sw[ta] ^ sw[tb];
                        st[tb].push_back(f);
                    }
                    sw[ta] = sw[tb];
                    swap(st[ta], st[tb]);
                    st[tb].clear();
                }
                else {
                    for (auto f : st[tb]) {
                        col[f] ^= sw[ta] ^ sw[tb];
                        st[ta].push_back(f);
                    }
                    st[tb].clear();
                }

                R.insert(mp(cnt[0][ta], ta));
                B.insert(mp(cnt[1][ta], ta));
            }
        }
        else if (t == 2) {
            int x;
            cin >> x;

            int tx = find(x);
            sw[tx] ^= 1;
            if (!impo[tx]) {
                R.erase(R.find(mp(cnt[0][tx], tx)));
                B.erase(B.find(mp(cnt[1][tx], tx)));
                swap(cnt[0][tx], cnt[1][tx]);
                R.insert(mp(cnt[0][tx], tx));
                B.insert(mp(cnt[1][tx], tx));
            }
        }
        else {
            int x;
            cin >> x;

            if (x == 0) {
                int ans = 0;
                if (!R.empty()) ans = (*R.rbegin()).y;
                cout << ans << '\n';
            }
            else {
                int ans = 0;
                if (!B.empty()) ans = (*B.rbegin()).y;
                cout << ans << '\n';
            }
        }
    }
    


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
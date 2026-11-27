#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()


int stSz = 1;
vector<int> st[5050];
int cur[1010];

bool cmp(int a, int b) {

    vector<int>& va = st[a];
    vector<int>& vb = st[b];

    int sa = va.size(), sb = vb.size();
    int sz = min(sa, sb);
    for (int i = 0; i < sz; i++) {
        if (va[sa - 1 - i] != vb[sb - 1 - i]) {
            return cmp(va[sa - 1 - i], vb[sb - 1 - i]);
        }
    }
    return sa < sb;
}

void solve() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '?') {
            int ca = cur[a], cb = cur[b];
            if (ca == cb) cout << "=\n";
            else {
                if (cmp(ca, cb)) cout << "<\n";
                else cout << ">\n";
            }
        }
        else {
            vector<int> newS = st[cur[a]];
            int pos = 0;
            for (pos = 0; pos < newS.size(); pos++) {
                if (cmp(newS[pos], cur[b])) {}
                else break;
            }
            newS.insert(newS.begin() + pos, cur[b]);

            int nx = stSz;
            for (int i = 0; i < nx; i++) {
                if (newS == st[i]) {
                    nx = i;
                    break;
                }
            }

            cur[a] = nx;
            if (nx == stSz) {
                st[nx] = newS;
                /*cout << "ADD: " << nx << " | ";
                for (auto f : newS) cout << f << ' ';
                cout << '\n';*/
                stSz++;
            }
        }

        /*for (int f = 1; f <= n; f++) cout << cur[f] << ' ';
        cout << '\n';*/
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
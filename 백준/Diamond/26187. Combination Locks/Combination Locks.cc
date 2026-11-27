
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mp make_pair

int n, m;
bool vs[2020];
bool invalid[2020];

int R[2020];
int L[2020];
bool vis[2020];

bool go(int v) {

    if (vis[v]) return 0;
    vis[v] = 1;

    for (int i = 0; i < n; i++) {
        int nv = v ^ (1 << i);
        if (invalid[nv] || !vs[nv]) continue;

        if (R[nv] == -1 || go(R[nv])) {
            R[nv] = v;
            L[v] = nv;
            return 1;
        }
    }
    return 0;
}

void solve() {

    memset(vs, 0, sizeof(vs));
    memset(invalid, 0, sizeof(invalid));
    memset(R, -1, sizeof(R));
    memset(L, -1, sizeof(L));
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;

    int s = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) s += (1 << i);
    }

    while (m--) {
        string ss;
        cin >> ss;

        int val = 0;
        for (int i = 0; i < n; i++) {
            if (ss[i] == '.') val += (1 << i);
        }
        invalid[val] = 1;
    }

    vector<int> list1, list2;

    vs[s] = 1;
    queue<pair<int, int>> q;
    q.push(mp(s, 0));
    while (!q.empty()) {
        int t, curr;
        tie(curr, t) = q.front(); q.pop();

        for (int i = 0; i < n; i++) {
            int nv = curr ^ (1 << i);
            if (!invalid[nv] && !vs[nv]) {
                vs[nv] = 1;
                if (t == 0) list2.push_back(nv);
                else list1.push_back(nv);
                q.push(mp(nv, 1 - t));
            }
        }
    }

    bool ok = 0;
    for (int i = 0; i < list1.size(); i++) {
        memset(vis, 0, sizeof(vis));
        go(list1[i]);
    }

    memset(vis, 0, sizeof(vis));
    if(go(s)) cout << "Alice\n";
    else cout << "Bob\n";

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
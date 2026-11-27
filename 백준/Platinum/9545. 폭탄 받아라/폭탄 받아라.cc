#include <bits/stdc++.h>
using namespace std;

int from[26];
bool adj[26][26];
bool vs[26];
int ansfound = -1;
void dfs(int v) {
    vs[v] = 1;
    for (int i = 0; i < 26; i++) {
        if (adj[v][i]) {
            from[i] = v;
            if (vs[i]) {
                ansfound = i;
                return;
            }
            dfs(i);
            if (ansfound != -1) return;
        }
    }
    vs[v] = 0;
}
void solve() {

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            adj[i][j] = 1;
        }
    }
    int n;
    cin >> n;
    while (n--) {
        char a, b;
        cin >> a >> b;
        adj[a - 'a'][b - 'a'] = 0;
    }

    vector<int> topo(26), dp(26, -1);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (adj[i][j]) topo[j]++;
        }
        from[i] = i;
        vs[i] = 0;
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (topo[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty()) {

        int a = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) if (adj[a][i]) {
            topo[i]--;
            dp[i] = max(dp[i], dp[a] + 1);
            if (dp[i] == dp[a] + 1) from[i] = a;
            if (topo[i] == 0) q.push(i);
        }
    }

    int ix = 0;
    while (ix < 26 && topo[ix] == 0) ix++;

    if (ix < 26) {
        // cycle found
        ansfound = -1;
        vector<int> lst;

        for (int i = 0; i < 26; i++) {
            dfs(i);
            if (ansfound != -1) break;
        }
        assert(ansfound != -1);
        ix = ansfound;
        lst.push_back(ix);
        while (from[ix] != ansfound) {
            lst.push_back(from[ix]);
            ix = from[ix];
        }
        reverse(lst.begin(), lst.end());

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                cout << char('a' + lst[(i + j) % lst.size()]);
            }
            cout << '\n';
        }
        lst.clear();
        return;
    }

    int mval = 0;
    for (int i = 0; i < 26; i++) {
        if (dp[i] > mval) {
            mval = dp[i];
            ix = i;
        }
    }
    vector<int> lst = { ix };
    while (from[ix] != ix) {
        ix = from[ix];
        lst.push_back(ix);
    }
    reverse(lst.begin(), lst.end());

    if (lst.size() % 2 == 0) lst.pop_back();

    int sz = lst.size();
    for (int i = 0; i <= sz / 2; i++) {
        for (int j = 0; j <= sz / 2; j++) {
            cout << char('a' + lst[i + j]);
        }
        cout << '\n';
    }
    lst.clear();

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mp make_pair

vector<int> adj[111];
int sz[111];
int currsz[111];
int curr[111];
int p[111];

void dfs(int v, int pv = -1) {
    p[v] = pv;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        sz[v] += sz[f];
    }

    if (adj[v].size() > 1) sz[v]++;
}

void upd(int v, int pv = -1) {
    currsz[v] = 0;

    int tc = 0;
    for (auto f : adj[v]) if (f != pv) {
        upd(f, v);
        currsz[v] += currsz[f];
    }
    if (curr[v]) currsz[v]++;
}

stack<int> st;

bool findRoute(int s, int e, int pv = -1) {

    if (s == e) return 1;

    for (auto i : adj[s])if (i != pv) {
        st.push(i);
        if (findRoute(i, e, s)) return 1;
        st.pop();
    }
    return 0;
}

vector<int> target;

void getTarget(int v) {
    for (auto f : adj[v]) if (f != p[v]) {
        getTarget(f);
    }

    if (adj[v].size() == 1) target.push_back(v);
}

void solve() {

    int b, d;
    cin >> b >> d;

    for (int i = 0; i < b - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 0; i <= b - 1; i++) {
        if (adj[i].size() != 1) {
            cnt++;
        }
    }

    if (cnt + 1 <= d) {
        // Defend
        cout << "DEFEND" << endl;

        vector<int> A;
        for (int i = 0; i < b; i++) {
            if (adj[i].size() > 1) A.push_back(i);
        }

        for (int i = 0; i < b && A.size() < d; i++) {
            if (adj[i].size() == 1) A.push_back(i);
        }

        vector<bool> cur(b);
        for (auto i : A) cur[i] = 1;

        int tr = A.back();

        for (auto i : A)cout << i << ' ';
        cout << endl;

        while (1) {

            int x;
            if (cin >> x) {

            }
            else {
                assert(0);
                return;
            }

            if (x == -1) return;

            if (cur[x]) {
                cout << 0 << endl;
                continue;
            }

            // go tr to x
            assert(st.empty());
            st.push(tr);
            findRoute(tr, x);

            int pv = x;
            vector<pair<int, int>> ans;
            while (!st.empty()) {
                int tx = st.top();
                st.pop();
                if (tx != x) {
                    ans.push_back(mp(tx, pv));
                }
                pv = tx;
            }

            cur[x] = 1;
            cur[tr] = 0;
            tr = x;
            cout << ans.size() << ' ';
            for (auto i : ans)cout << i.first << ' ' << i.second << ' ';
            cout << endl;
        }
    }
    else {

        cout << "ATTACK" << endl;

        for (int i = 0; i < d; i++) {
            int x;
            cin >> x;
            curr[x] = 1;
        }

        int pv = -1;
        int tx = 0;
        int tmpCnt = 0;
        while (tmpCnt < 365) {
            tmpCnt++;
            for (int i = 0; i < b; i++) {
                if (adj[i].size() == 1) {
                    int nx = adj[i][0];

                    if (!curr[nx] && !curr[i]) {
                        cout << i << endl;
                        return;
                    }
                }
            }

            if (pv == -1) {
                tx = 0;
                while (tx < b && (adj[tx].size() == 1 || curr[tx])) tx++;
            }
            if (tx == b) {
                for (int i = 0; i < b; i++) if (adj[i].size() == 1) {
                    cout << i << endl;
                    break;
                }
            }
            else {
                if (pv == -1) {
                    dfs(tx);
                    pv = tx;
                }

                upd(pv);
                for (auto f : adj[tx]) if (f != p[tx]) {
                    if (curr[tx] && sz[f] > currsz[f]) {
                        tx = f;
                        break;
                    }
                    if (curr[tx] == 0 && sz[f] >= currsz[f]) {
                        tx = f;
                        break;
                    }
                }

                target.clear();
                getTarget(tx);

                bool ok = 0;
                for (auto i : target) if (!curr[i]) {
                    cout << i << endl;
                    ok = 1;
                    break;
                }
                assert(ok);
            }

            int k;
            cin >> k;

            while (k--) {
                int u, v;
                cin >> u >> v;

                curr[u]--;
                curr[v]++;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

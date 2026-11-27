#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct P {
    ll x, y;
};

ll dist(P& p1, P& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

vector<int> adj[1010];
int L[1010], R[1010];

vector<bool> vs;

bool dfs(int v) {
    if (vs[v]) return 0;
    vs[v] = 1;

    for (auto a : adj[v]) {
        if (R[a] == -1 || dfs(R[a])) {
            L[v] = a;
            R[a] = v;
            return 1;
        }
    }
    return 0;
}


void solve(int t) {

    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        L[i] = R[i] = -1;
    }

    vector<P> A(n), B(n + 1);
    for (auto& i : A) cin >> i.x >> i.y;
    for (auto& i : B) cin >> i.x >> i.y;

    for (int i = 0; i < n; i++) {
        vector<pair<ll, ll>> tmp;
        for (int j = 1; j <= n; j++) {
            tmp.push_back({ dist(A[i], B[j]), j });
        }
        sort(tmp.begin(), tmp.end());

        ll tar = dist(A[i], B[0]);
        while (!tmp.empty()) {
            if (tmp.back().first > tar) tmp.pop_back();
            else break;
        }

        for (auto j : tmp) adj[i].push_back(j.second);
    }
    /*cout << "ADJLISt\n";
    for (int i = 0; i < n; i++) {
        cout << "i: " << i << ' ';
        for (auto j : adj[i]) cout << j << ' ';
        cout << '\n';
    }*/

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        vs = vector<bool>(n);
        if (dfs(i)) cnt++;
    }

    cout << "Case #" << t << ": ";
    if (cnt == n) {

        vector<pair<int, int>> ans;
        queue<int> q;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            ll tar = dist(A[i], B[L[i]]);
            for (auto j : adj[i]) {
                if (dist(A[i], B[j]) < tar) cnt[i]++;
                else break;
            }

            if (cnt[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            ans.push_back({ a, L[a] });

            for (int i = 0; i < n; i++) {
                if (dist(A[i], B[L[a]]) < dist(A[i], B[L[i]])) {
                    cnt[i]--;
                    if (cnt[i] == 0) q.push(i);
                }
            }
        }

        if (ans.size() == n) {
            cout << "POSSIBLE\n";
            for (auto i : ans) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
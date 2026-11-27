#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct T {
    int ai, bi, ci;
    int d, e;
};

map<string, int> tmp;
vector<T> rep[10001];
vector<int> adj[10001];
int topo[10001];

int dp_ps[10001], dp_cst[10001];

vector<string> deg;

int cnt = 0;
int set_tmp(string s) {
    if (tmp[s]) return tmp[s];
    cnt++;
    deg.push_back(s);
    return tmp[s] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<T> A(m);

    for (int i = 0; i < m; i++) {
        string a, b, c;
        int d, e;
        cin >> a >> b >> c >> d >> e;
        int ai = set_tmp(a), bi = set_tmp(b), ci = set_tmp(c);
        A[i] = { ai, bi, ci, d, e };
    }

    for (auto i : A) {
        adj[i.bi].push_back(i.ai);
        adj[i.ci].push_back(i.ai);
        topo[i.ai] += 2;

        rep[i.ai].push_back(i);
    }

    queue<int> q;
    for (int i = 1; i <= cnt; i++) {
        if (topo[i] == 0) q.push(i);
    }

    while (!q.empty()) {

        int ix = q.front();
        q.pop();

        int ps = 0, cost = 1e9;

        for (auto i : rep[ix]) {

            int tps = dp_ps[i.bi] + dp_ps[i.ci] + i.e;
            int tcst = dp_cst[i.bi] + dp_cst[i.ci] + i.d;

            if (cost > tcst || (cost == tcst && ps < tps)) {
                cost = tcst;
                ps = tps;
            }
        }
        if (cost == 1e9) cost = 0;

        dp_ps[ix] = ps;
        dp_cst[ix] = cost;

        for (auto i : adj[ix]) {
            topo[i]--;
            if (topo[i] == 0) q.push(i);
        }
    }

    vector<int> knap(n + 1);
    for (int i = 0; i < tmp.size(); i++) {

        int a = dp_ps[i], b = dp_cst[i];

        if (a == 0 && b == 0) continue;

        for (int j = n; j >= b; j--) {
            knap[j] = max(knap[j], knap[j - b] + a);
        }
    }
    
    int ans_ps = 0, ans_cst = 0;
    for (int i = 0; i <= n; i++) {
        if (knap[i] > ans_ps) {
            ans_ps = knap[i];
            ans_cst = i;
        }
    }

    cout << ans_ps << '\n' << ans_cst;
}
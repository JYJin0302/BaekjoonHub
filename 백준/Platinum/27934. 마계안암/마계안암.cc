#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> adj[100001];

bool visited[100001];
ll dist[100001];
ll dp[100001];
int topo[100001];

bool inf[100001];
const ll mod = 998244353;

void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dist[i] = 1e16;
        inf[i] = 1;
    }
    dp[1] = 1;
    dist[1] = 0;

    vector<tuple<ll, ll, ll>> edg, nedg;

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;

        edg.push_back({ a, b, c });
        adj[a].push_back({ b, c });
        //adj[b].push_back({ a, c });
    }




    // set min dist
    priority_queue<pair<ll, int>> pq;
    pq.push({ 0, 1 });
    while (!pq.empty()) {

        ll a, b;
        tie(a, b) = pq.top();
        pq.pop();

        a *= -1;
        if (visited[b]) continue;
        visited[b] = 1;
        dist[b] = a;

        for (auto i : adj[b]) {
            ll x, y;
            tie(x, y) = i;

            ll ndist = dist[b] + y;

            if (dist[x] == 1e16) {
                pq.push({ -ndist, x });
            }
        }
    }

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (auto i : edg) {
        ll a, b, c;
        tie(a, b, c) = i;

        if (dist[b] == dist[a] + c) {
            nedg.push_back(i);
            topo[b]++;
            adj[a].push_back({ b ,c });
        }
    }

    // 필요없는 간선 제거 완료

    vector<int> ord(n + 1);
    queue<int> q;
    if (topo[1] == 0) q.push(1);
    int o = 0;
    while (!q.empty()) {

        int a = q.front();
        q.pop();
        inf[a] = 0;
        ord[a] = ++o;

        for (auto i : adj[a]) {
            ll x, y;

            tie(x, y) = i;

            topo[x]--;
            if (topo[x] == 0) q.push(x);
        }
    }

    vector<bool> vs(n + 1);
    vs[1] = 1;
    q.push(1);
    while (!q.empty()) {

        int a = q.front();
        q.pop();

        for (auto i : adj[a]) {
            if (!vs[i.first]) {
                vs[i.first] = 1;
                q.push(i.first);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vs[i]) inf[i] = 0;

        if (inf[i] && vs[i]) q.push(i);
    }
    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (auto i : adj[a]) {
            if (!inf[i.first]) {
                inf[i.first] = 1;
                q.push(i.first);
            }
        }
    }


    memset(visited, 0, sizeof(visited));

    priority_queue<pair<int, pair<int, int>>> pq2;
    pq2.push({ 0, {-ord[1], 1} });

    while (!pq2.empty()) {

        ll a, b, c;
        tie(b, c) = pq2.top().second;
        a = pq2.top().first;
        pq2.pop();

        if (visited[c]) continue;
        visited[c] = 1;
        a *= -1;
        for (auto i : adj[c]) {

            ll x, y;
            tie(x, y) = i;

            if (inf[x]) continue;
            else {
                dp[x] += dp[c];
                dp[x] %= mod;
                if (!visited[x]) pq2.push({ -dist[x], make_pair(-ord[x], x) });
            }
        }
    }

    /*
    for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << ord[i] << ' ';
    */

    for (int i = 1; i <= n; i++) {
        if (inf[i]) cout << "-1\n";
        else cout << dp[i] << '\n';
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
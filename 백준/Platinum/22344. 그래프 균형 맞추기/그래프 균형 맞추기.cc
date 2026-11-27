#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> adj[100001];

pair<ll, ll> val[100001];
// ax + b
bool visited[100001];
bool valid = 1;

vector<ll> ansList;

void dfs(int v) {

    ll x, y;
    tie(x, y) = val[v];

    for (auto i : adj[v]) {
        if (!visited[i.first]) {
            visited[i.first] = 1;
            val[i.first] = { -x, i.second-y};
            dfs(i.first);
        }
        else {
            ll a, b;
            tie(a, b) = val[i.first];

            if (a != x) {
                valid &= (b+y == i.second);
            }
            else {
                // try answer : b+y/2
                valid &= ((i.second-b-y) % (a+x) == 0);
                if (ansList.empty()) ansList.push_back((i.second - b - y) / (a + x));
                else valid &= (ansList.back() == (i.second - b - y) / (a + x));
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }

    val[1] = { 1, 0 };
    visited[1] = 1;
    dfs(1);

    if (!valid) cout << "No";
    else {
        cout << "Yes\n";

        ll ans;
        if (!ansList.empty()) {
            ans = ansList[0];
        }
        else {
            vector<ll> tmp;
            for (int i = 1; i <= n; i++) tmp.push_back(-val[i].second * val[i].first);

            sort(tmp.begin(), tmp.end());

            ans = tmp[n / 2];
        }

        for (int i = 1; i <= n; i++) {
            cout << val[i].first * ans + val[i].second << ' ';
         }
    }
}
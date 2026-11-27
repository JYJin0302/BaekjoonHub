#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

bool isP[10001010];

vector<pair<ll, ll>> adj[402020];

void solve() {
    
    for(int i =2 ; i <= 10000000; i++){
        if (isP[i]) continue;
        for(int j = i*2; j <= 10000000; j += i){
            isP[j] = 1;
        }
    }
    
    int n, m;
    cin >> n >> m;

    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (isP[A[a]+A[b]]) continue;

        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));

    }

    vector<ll> dist(n + 1, -1);
    priority_queue<pair<ll, ll>> pq;
    pq.push(mp(0, 1));
    while (!pq.empty()) {

        ll a, b ;
        tie(a, b) = pq.top();
        pq.pop();

        if (dist[b] != -1) continue;
        dist[b] = -a;

        for (auto f : adj[b]) {
            if (dist[f.first] == -1) {
                pq.push(mp(a - f.second, f.first));
            }
        }

    }

    if (dist[n] == -1) cout << "Now where are you?";
    else cout << dist[n];


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

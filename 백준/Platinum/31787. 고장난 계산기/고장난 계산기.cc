#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dist[2020];

int getAns(ll x) {
    if (x <= 100) return dist[x + 20];

    if (x % 4) return getAns(x * 4) + 1;
    ll tv = x / 4;
    if (tv % 4 == 0) return getAns(x / 4) + 1;
    if (tv % 4 == 1) return getAns(x - 4) + 1;
    if (tv % 4 == 3) return getAns(x + 4) + 1;
    tv /= 4;
    if (tv % 4 < 2) return getAns(x - 4) + 1;
    return getAns(x + 4) + 1;
}
void solve() {

    ll x;
    cin >> x;

    cout << getAns(x) << '\n';
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int b = 20;
    int mx = 1000;
    memset(dist, -1, sizeof(dist));

    dist[b] = 0;
    queue<int> q;
    q.push(b);
    while (!q.empty()) {

        int a = q.front(); q.pop();

        int val = a - b;
        if (a - 4 && dist[a - 4] == -1) {
            dist[a - 4] = dist[a] + 1;
            q.push(a - 4);
        }
        if (a + 4 < mx && dist[a + 4] == -1) {
            dist[a + 4] = dist[a] + 1;
            q.push(a + 4);
        }

        if (val * 4 + b >= 0 && val * 4 + b < mx && dist[val * 4 + b] == -1) {
            dist[val * 4 + b] = dist[a] + 1;
            q.push(val * 4 + b);
        }

        if (val % 4 == 0) {
            if (dist[val / 4 + b] == -1) {
                dist[val / 4 + b] = dist[a] + 1;
                q.push(val / 4 + b);
            }
        }
    }


    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second



void solve() {

    cout << fixed << setprecision(10);

    vector<pair<int, int>> pos(3);

    vector<int> V(3);
    for (int i = 0; i < 3; i++) {
        cin >> pos[i].x >> pos[i].y >> V[i];
    }

    vector<ld> dist(4);
    
    for (int i = 1; i < 4; i++) {
        dist[i % 3] = sqrtl((pos[i % 3].x - pos[i - 1].x) * (pos[i % 3].x - pos[i - 1].x) \
            + (pos[i % 3].y - pos[i - 1].y) * (pos[i % 3].y - pos[i - 1].y));
    }

    vector<int> w(3);
    for (auto& i : w) {
        cin >> i;
    }

    vector<int> car;
    for (int i = 0; i < 3; i++) if (V[i]) car.push_back(i);

    ld tot = 0;
    for (auto f : dist) tot += f;
    int c1 = car[0];
    int c2 = car[1];
    if (V[car[0]] == V[car[1]]) {


        vector<ld> ans(3, -1);
        ans[c1] = ans[c2] = tot / V[c1];
        for (int i = 0; i < 3; i++) {
            if (ans[i] < 0) cout << '-' << '\n';
            else cout << ans[i] << '\n';      
        }
        return;
    }

    if (V[c1] < V[c2]) swap(c1, c2);

    ld dif = 0;
    for (int i = 0; i < 3; i++) {
        int nc = (c1 + i + 1) % 3;
        dif += dist[nc];
        if (nc == c2) break;
    }

    ld T = 1.0 * dif / (V[c1] - V[c2]);

    vector<ld> ans(3, -1);
    ans[c2] = tot / V[c2];

    ld T2 = 0;
    bool ok = 1;
    for(int i =0; i < 3; i++){
        int pos = (c1 + i + 1) % 3;
        T2 += dist[pos] / V[c1];
        if (T2 >= T) {
            // collision;
            int pp = (pos + 2) % 3;
            if (w[pp] == 1) {
                ok = 0;
                ld collDist = T2 * V[c1] - T * V[c1];
                ans[c1] = collDist / V[c2] + (tot - collDist) / V[c1];
                break;
            }
            else break;
        }
    }

    if (ok) ans[c1] = tot / V[c1];
    

    for (int i = 0; i < 3; i++) {
        if (ans[i] < -0.5) cout << '-' << '\n';
        else cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while(t--) solve();
}
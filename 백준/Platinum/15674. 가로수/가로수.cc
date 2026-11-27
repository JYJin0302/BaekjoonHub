#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll costTot[2][202020];
ll cost[2][202020];

ll ans = 0;
int root[202020];
int sz[202020];
int diff[202020];
int find(int n, int& p) {
    if (root[n] == n) return n;
    p ^= diff[n];
    return find(root[n], p);
}

void merge(int t, int a, int b) {

    int pa = 0, pb = 0;
    int ga = find(a, pa);
    int gb = find(b, pb);
    if (ga == gb) return;

    if (sz[ga] < sz[gb]) {
        swap(ga, gb);
        swap(pa, pb);
    }
    t ^= pa;
    t ^= pb;

    ans -= min(costTot[0][ga], costTot[1][ga]);
    ans -= min(costTot[0][gb], costTot[1][gb]);
    sz[ga] += sz[gb];
    root[gb] = ga;
    diff[gb] = t;
    costTot[0][ga] += costTot[0^t][gb];
    costTot[1][ga] += costTot[1^t][gb];
    ans += min(costTot[0][ga], costTot[1][ga]);
}

void update(int t, int a, int b) {
    int pa = 0;
    int ga = find(a, pa);
    ans -= min(costTot[0][ga], costTot[1][ga]);
    int dif = b - cost[t][a];
    costTot[t ^ pa][ga] += dif;
    cost[t][a] += dif;
    ans += min(costTot[0][ga], costTot[1][ga]);
}

void solve() {

    int n, d;
    cin >> n >> d;

    for (int i = 1; i <= n; i++) {
        cin >> cost[0][i] >> cost[1][i];
        ans += min(cost[0][i], cost[1][i]);
        costTot[0][i] = cost[0][i];
        costTot[1][i] = cost[1][i];
    }

    for (int i = 1; i <= n; i++) {
        root[i] = i;
        sz[i] = 1;
    }
        

    while (d--) {
        int t, a, b;
        cin >> t >> a >> b;
        merge(t, a, b);
    }

    cout << ans << '\n';
    int q;
    cin >> q;
    while (q--) {

        int t, a, b;
        cin >> t >> a >> b;
        if (t <= 1) {
            merge(t, a, b);
        }
        else {
            update(t - 2, a, b);
        }
        cout << ans << '\n';
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair


int deg[101010];

void solve() {

    int n, p;
    cin >> n >> p;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) cnt++;

    if (p % cnt >= 2) {
        cout << (p / cnt + 1) * 2;
    }
    else if (p % cnt == 1) {
        cout << p / cnt * 2 + 1;
    }
    else cout << p / cnt * 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
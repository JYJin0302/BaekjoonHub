#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

void solve() {

    int n, m;
    cin >> n >> m;

    ll vA = 0, vB = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        vA += x + 1;
    }

    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        vB += x + 1;
    }

    if (vA > vB) {
        cout << "ALICE\n";
    }
    else if (vA < vB) {
        cout << "BOB\n";
    }
    else {
        cout << "TIED\n";
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
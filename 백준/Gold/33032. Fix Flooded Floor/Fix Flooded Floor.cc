#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

#define None {cout << "None\n"; return;}

void solve() {

    int n;
    cin >> n;
    vector<string> G(2);
    cin >> G[0] >> G[1];
    G[0] += '#';
    G[1] += '#';

    bool mult = 0;
    for (int i = 0; i < n; i++) {
        if (G[0][i] == '#' && G[1][i] == '#') continue;
        if (G[0][i] == '#' && G[1][i] == '.') {
            if (G[1][i + 1] == '#') None;
            G[1][i] = G[1][i + 1] = '#';
        }
        else if (G[0][i] == '.' && G[1][i] == '#') {
            if (G[0][i + 1] == '#') None;
            G[0][i] = G[0][i + 1] = '#';
        }
        else {
            if (G[0][i + 1] == '.' && G[1][i + 1] == '.') {
                mult = 1;
            }
            G[0][i] = G[1][i] = '#';
        }
    }

    if (mult) cout << "Multiple\n";
    else cout << "Unique\n";



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
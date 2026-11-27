#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    string s;
    cin >> s;

    vector<int> pos(3);
    for (int j = 0; j < 10; j++) {
        if (s[j] == '@') pos[0] = j;
        if (s[j] == '#') pos[1] = j;
        if (s[j] == '!') pos[2] = j;
    }

    if (pos[0] < pos[1] && pos[1] < pos[2]) cout << pos[2] - pos[0] - 1 << '\n';
    else if (pos[0] > pos[1] && pos[1] > pos[2]) cout << pos[0] - pos[2] - 1 << '\n';
    else cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
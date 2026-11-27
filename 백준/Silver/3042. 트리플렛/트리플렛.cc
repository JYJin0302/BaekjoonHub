#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool chk(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    return res == 0;
}

void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (isalpha(c))pos.push_back(mp(i, j));
        }
    }

    int tn = pos.size();

    int cnt = 0;
    for (int i = 0; i < tn; i++) {
        for (int j = i+1; j < tn; j++) {
            for (int k = j+1; k < tn; k++) {
                if (chk(pos[i], pos[j], pos[k])) cnt++;
            }
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
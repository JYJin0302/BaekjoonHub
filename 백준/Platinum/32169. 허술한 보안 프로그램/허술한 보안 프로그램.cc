#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second



void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> edg;
    vector<bool> used(n + 1);
    for (int i = n - 1; i >= 1; i--) {
        if (used[i])continue;

        int nxt = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (used[j]) continue;
            if ((i & j) == 0) {
                nxt = j;
                break;
            }
        }

        edg.push_back(mp(i, nxt));
        used[nxt] = 1;
    }

    if (!used[0]) {
        edg.push_back(mp(0, 0));
    }

    vector<int> outp(n);
    vector<int> res(n), ans(n);

    for (auto& [a, b] : edg) {
        outp[a] = b;
        outp[b] = a;
    }

    cout << "? ";
    for (auto f : outp) cout << f << ' ';
    cout << endl;


    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 12; j++) {
            bool t1 = res[i] & (1 << j);
            bool t2 = outp[i] & (1 << j);
            if (!t2 && t1) ans[i] |= 1 << j;
        }
    }

    for (auto& [a, b] : edg) {
        outp[a] = a;
        outp[b] = b;
    }

    cout << "? ";
    for (auto f : outp) cout << f << ' ';
    cout << endl;


    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 14; j++) {
            bool t1 = res[i] & (1 << j);
            bool t2 = outp[i] & (1 << j);
            if (!t2 && t1) ans[i] |= 1 << j;
        }
    }

    cout << "! ";
    for (auto f : ans) cout << f << ' ';
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while(t--) solve();
}
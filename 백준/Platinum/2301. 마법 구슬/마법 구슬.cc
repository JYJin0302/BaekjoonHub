#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> solve(int n, int s) {
    if (n == 2) {
        if (s == 1) return { 1, 2 };
        return { 2, 1 };
    }

    vector<int> v1, v2;
    if (s <= n / 4 || s > n - n / 4) {
        // 00xx xx00
        int ts = s;
        if (s > n - n / 4) ts -= n / 2;
        v1 = solve(n / 2, ts);
        for (auto& f : v1) if (f > n / 4) f += n / 2;

        int last = v1.back();
        ts = last;
        if (last <= n / 4) ts += n / 2;
        else ts -= n / 2;
        ts -= n / 4;
        v2 = solve(n / 2, ts);
        for (auto& i : v2) {
            i += n / 4;
            v1.push_back(i);
        }
        return v1;
    }
    else {
        // xx00 00xx
        int ts = s - n / 4;
        v1 = solve(n / 2, ts);
        for (auto& i : v1) i += n / 4;

        int last = v1.back();
        ts = last;
        if (last <= n / 2) ts += n / 2;
        else ts -= n / 2;

        if (ts > n - n / 4) ts -= n / 2;
        v2 = solve(n / 2, ts);
        for (auto& f : v2) {
            if (f > n / 4) f += n / 2;
            v1.push_back(f);
        }
        return v1;
    }
}

void solve() {

    int n, s;
    cin >> n >> s;

    vector<int> ans = solve(n, s);
    for (auto f : ans) cout << f << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
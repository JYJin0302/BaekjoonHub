#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> getG(int n) {
    if (n == 1) {
        return { 0, 1 };
    }

    vector<int> v1 = getG(n - 1);
    int sn = v1.size();
    for (int i = sn - 1; i >= 0; i--) {
        v1.push_back(v1[i] + (1 << n - 1));
    }
    return v1;
}

int n, m;
string pf(int x) {
    string res;
    for (int i = 0; i < n; i++) {
        if (x & (1 << i)) res += '1';
        else res += '0';
    }
    return res;
}

void solve() {

    cin >> n >> m;

    vector<pair<int, int>> rule(m);
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        int v1 = 0, v2 = 0;
        for (int j = 0; j < n; j++) {
            if (s1[j] == '1') v1 += 1 << j;
            if (s2[j] == '1') v2 += 1 << j;
        }
        rule[i] = mp(v1, v2);
    }

    vector<int> res = getG(n);
    int sn = res.size();

    if (m == 1) {
        for (int i = 1; i < sn; i++) {
            int val1 = res[i - 1] ^ rule[0].x;
            int val2 = res[i] ^ rule[0].y;

            if (val1 == val2) {
                for (auto& f : res) {
                    cout << pf(f ^ val1) << ' ';
                }
                cout << '\n';
                return;
            }
        }
        assert(0);
    }

    int d1 = rule[0].x ^ rule[0].y;
    int d2 = rule[1].x ^ rule[1].y;

    for (auto& i : res) {
        int v = i & d1;
        int v2 = i & 1;

        i -= v + v2;
        if (v) i += 1;
        if (v2) i += d1;
    }

    if (d1 != d2) {
        for (int i = 1; i < sn; i++) {
            int val1 = res[i - 1] ^ rule[1].x;
            int val2 = res[i] ^ rule[1].y;

            if (val1 == val2) {
                for (auto& f : res) {
                    cout << pf(f ^ val1) << ' ';
                }
                cout << '\n';
                return;
            }
        }
        assert(0);
    }

    for (auto& f : res) {
        cout << pf(f) << ' ';
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll getAns(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);

    string res;
    while (s1.size() < s2.size()) s1 = '1' + s1;
    while (s2.size() < s1.size()) s2 = '1' + s2;

    int n = s1.size();
    for (int i = 0; i < n; i++) {
        int v = (s1[i] - '0') * (s2[i] - '0');
        for (auto f : to_string(v)) res += f;
    }
    return stoll(res);
}

void solve() {

    int a, b;
    cin >> a >> b;

    ll ans1 = 1ll * a * b;
    ll ans2 = getAns(a, b);
    cout << (ans1 == ans2) << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
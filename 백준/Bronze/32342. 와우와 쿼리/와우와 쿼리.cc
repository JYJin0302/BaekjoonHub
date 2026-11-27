#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    string s;
    cin >> s;

    int n = s.size();
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (s.substr(i - 2, 3) == "WOW") cnt++;
    }
    cout << cnt << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {

        int n, s, d;
        cin >> n >> s >> d;

        int ans = 0;
        for (int f = 0; f < n; f++) {
            int a, b;
            cin >> a >> b;
            if (a <= s * d) ans += b;
        }

        cout << "Data Set " << i << ":\n";
        cout << ans << '\n' << '\n';
    }
}
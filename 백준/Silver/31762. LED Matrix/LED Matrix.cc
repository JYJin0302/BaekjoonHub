#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    bool ans = 1;
    for(int i = 0 ; i < n; i++){
        
        string a, b;
        cin >> a >> b;

        bool ok = 1;
        for (auto f : a) if (f == '-') ok = 0;
        for (auto f : b) {
            if (f == '*' && !ok) {
                ans = 0;
            }
        }

    }

    if (ans) cout << "Y";
    else cout << "N";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
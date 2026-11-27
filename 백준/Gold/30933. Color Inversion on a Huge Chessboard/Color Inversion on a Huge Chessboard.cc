#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()



void solve() {

    ll n, q;
    cin >> n >> q;

    vector<int> row(n + 1), col(n + 1);

    ll rcnt = n, ccnt = n;

    while (q--) {

        string s;
        cin >> s;

        int x;
        cin >> x;

        if (s[0] == 'R') {
            int diff = 0;
            if (x > 1) {
                if (row[x] == row[x - 1]) diff--;
                else diff++;
            }
            if (x < n) {
                if (row[x] == row[x + 1]) diff--;
                else diff++;
            }
            rcnt += diff;
            row[x] ^= 1;
        }
        else {
            int diff = 0;
            if (x > 1) {
                if (col[x] == col[x - 1]) diff--;
                else diff++;
            }
            if (x < n) {
                if (col[x] == col[x + 1]) diff--;
                else diff++;
            }
            ccnt += diff;
            col[x] ^= 1;
        }

        cout << rcnt * ccnt << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}
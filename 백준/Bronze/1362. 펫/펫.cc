#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
    int cnt = 0;
    while (1) {

        int o, w;
        cin >> o >> w;
        if (o == 0 && w == 0) return;
        cnt++;
        cout << cnt << ' ';

        char c;
        int x;
        cin >> c >> x;

        bool rip = 0;
        while (c != '#') {

            if (c == 'F') {
                w += x;
            }
            else {
                w -= x;
                if (w <= 0) rip = 1;
            }
            cin >> c >> x;
        }
        if (rip) cout << "RIP\n";
        else if (w > o / 2 && w < o * 2) cout << ":-)\n";
        else cout << ":-(\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //cin >> t;
    solve();

}
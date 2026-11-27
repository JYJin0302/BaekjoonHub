#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    string s;
    cin >> s;

    int x1, y1, x2, y2;
    x1 = y1 = 0;
    x2 = y2 = pow(2, s.size()) - 1;

    //cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    for (int i = 0; i < s.size(); i++) {
        int mx = (x1 + x2) >> 1;
        int my = (y1 + y2) >> 1;

        int v = s[i] - '0';

        if (v == 0) tie(x2, y2) = mp(mx, my);
        else if (v == 1) tie(x2, y1) = mp(mx, my + 1);
        else if (v == 2) tie(x1, y2) = mp(mx + 1, my);
        else if (v == 3) tie(x1, y1) = mp(mx + 1, my + 1);
        //cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';

    }

    cout << s.size() << ' ' << y1 << ' ' << x1;

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}
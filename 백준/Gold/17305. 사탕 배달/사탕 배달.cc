#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()
#define mp make_pair

void solve() {

    int n, w;
    cin >> n >> w;

    vector<int> w3 = { 0 }, w5 = { 0 };
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 3) w3.push_back(b);
        else w5.push_back(b);
    }

    sort(1 +all(w3));
    reverse(1 +all(w3));
    sort(1 +all(w5));
    reverse(1 +all(w5));



    int cx = w3.size() - 1;
    ll t3 = 0, t5 = 0;
    ll ans = 0;

    while (cx > 0 && cx * 3 > w) cx--;

    for (int j = 1; j <= cx; j++) t3 += w3[j];

    ans = t3;
    for (int i = 1; i < w5.size() && 5 *i <= w; i++) {
        int c1 = 5 * i;
        t5 += w5[i];
        while (3 * cx + c1 > w) {
            t3 -= w3[cx];
            cx--;
        }

        //cout << cx << ' ' << i << " | " << t3 << ' ' << t5 << '\n';;
        ans = max(ans, t3 + t5);
    }
    cout << ans << '\n';
    


}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dir(int data, int pos) {
    return (data & (1 << pos)) > 0;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;

    vector<int> pos(n);
    for (auto& i : pos) cin >> i;
    sort(pos.begin(), pos.end());

    int t;
    cin >> t;

    int tot = 0, ttot = 0;
    for (int i = 0; i < (1 << n); i++) {
        // dir 0 :: right, 1 :: left
        int cnt = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < x; y++) {
                if (pos[x] - pos[y] <= 2*t && dir(i, x) && !dir(i, y)) cnt++;
            }
        }

        tot += cnt;
        ttot++;
    }

    long double ans = tot;
    ans /= ttot;
    cout << ans;

}
#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int res = 0;
    if (a == b) {
        for (auto f : A) {
            f %= (a + 1);
            res ^= f;
        }
        if (res) cout << "Hanako";
        else cout << "Jiro";
    }
    else if (a > b) {
        int cnt = 0;
        for (auto f : A) {
            if (f > b) {
                cnt++;
            }
            else {
                res ^= f;
            }
        }

        if (res != 0 || cnt > 0) cout << "Hanako";
        else cout << "Jiro";
    }
    else {
        int cnt = 0;
        int tmp = 0;
        for (auto f : A) {
            if (f > a) {
                cnt++;
                tmp = f;
            }
            else {
                res ^= f;
            }
        }

        //cout << res << ' ' << cnt << ' ' << tmp << '\n';
        if (res != 0 && cnt == 0) cout << "Hanako"; // ok
        else if (res != 0 && cnt == 1 && tmp - a <= res && tmp > res && res <= a) cout << "Hanako"; // more restriction needed?
        else cout << "Jiro";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}

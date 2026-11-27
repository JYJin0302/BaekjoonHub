#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ll a, b;
    cin >> a >> b;

    ll bb = 2;
    int cnt = 1;
    while (cnt <= 60) {
        if ((bb - 1) % b == 0) break;
        cnt++;
        bb *= 2;
    }

    if (cnt == 61) {
        cout << -1;
        return 0;
    }

    bb--;

    a *= bb / b;
    b = bb;

    string ans(cnt, '-');
    for (int i = cnt - 1; i >= 0; i--) {
        if (a % 2 == 1) ans[i] = '*';
        a /= 2;
    }

    cout << ans;
}
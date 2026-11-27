#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll grid[1000001];


int main() {
    ll minn, maxx;
    cin >> minn >> maxx;
    for (ll i = 2; i * i <= maxx; i++) {
        ll temp = (minn  / (i * i)) * i * i;
        while (temp < minn) temp += i * i;
        while (temp <= maxx) {
            if (temp % (i * i) == 0) grid[temp - minn] = 1;
            temp += i * i;
        }
    }

    int cnt = 0;
    for (ll i = 0; i <= maxx - minn; i++) {
        if (grid[i]) continue;
        cnt++;
    }

    cout << cnt;

}
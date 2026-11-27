#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, l, c;
    cin >> n >> l >> c;

    int v1 = 1 + (c - l) / (l + 1);
    if (v1 % 13 == 0) v1--;

    if (n % v1 == 0 || (n % v1) % 13 != 0) cout << n / v1 + (n % v1 != 0);
    else {
        if (n / v1 == 0) cout << 2;
        else if ((v1 - 1) % 13 == 0 && (n % v1) == v1 - 1) cout << n / v1 + 2;
        else cout << n / v1 + 1;
    }

}
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    if (n == 1) cout << 1;
    else if (n == 2) {
        cout << min(1 + (m - 1) / 2, 4);
    }
    else {
        if (m <= 4) cout << m;
        else if (m <= 6) cout << 4;
        else cout << m - 2;
    }
}
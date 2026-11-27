#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.flush();

    int x = 1, y;
    cout << x << endl;
    while (x != 99) {

        cin >> y;

        if (y % 3 != 0) x = y + 3 - (y % 3);
        else x = 2 * y - x;
        cout << x << endl;
    }
}
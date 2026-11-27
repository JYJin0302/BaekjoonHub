#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        a %= 10;
        int ta = a;
        b--;
        b %= 4;
        for (int i = 0; i < b; i++) {
            a = a * ta % 10;
        }

        if (a == 0) a = 10;
        cout << a << '\n';
    }
}
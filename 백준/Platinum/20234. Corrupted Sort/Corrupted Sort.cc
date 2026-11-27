#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    while(1) {
        for (int i = 1; i < n; i++) {
            cout << i << ' ' << i + 1 << endl;
            cin >> s;

            if (s[0] == 'W') return 0;
        }
        for (int i = n-1; i > 0; i--) {
            cout << i << ' ' << i + 1 << endl;
            cin >> s;

            if (s[0] == 'W') return 0;
        }

        for (int i = 0; i < 2; i++) {
            cout << 1 << ' ' << n << endl;
            cin >> s;

            if (s[0] == 'W') return 0;
        }
    }
}

#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int s;
    cin >> s;

    for (int i = 0; i * i <= s; i++) {
        for (int j = i; j * j <= s; j++) {

            if (i * i + j * j == s) {
                cout << 0 << ' ' << 0 << '\n';
                cout << i << ' ' << j << '\n';
                cout << i - j << ' ' << i + j << '\n';
                cout << -j << ' ' << i;
                return 0;
            }

        }
    }

    cout << "Impossible";
}

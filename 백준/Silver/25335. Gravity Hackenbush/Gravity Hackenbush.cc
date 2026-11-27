#include <bits/stdc++.h>
using namespace std;

map<char, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
    }
    
    while (m--) {
        int a, b;
        char c;
        cin >> a >> b >> c;

        cnt[c]++;
    }

    if (cnt['G'] % 2 == 1) cnt['R']++;

    if (cnt['R'] <= cnt['B']) cout << "jhnan917";
    else cout << "jhnah917";

}
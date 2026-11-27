#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> p1(1000001, 1), p2(1000001, 1);
    p1[0] = 0, p1[1] = 0;

    for (int i = 2; i * i <= 1000000; i++) {
        if (p1[i] == 0) continue;
        for (int j = i * 2; j <= 1000000; j += i) {
            p1[j] = 0;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        p2[i] = p1[i];
        if (p2[i] == 1 && i % 4 != 1) p2[i] = 0;
    }
    p2[2] = 1;

    for (int i = 1; i <= 1000000; i++) {
        p1[i] += p1[i - 1];
        p2[i] += p2[i - 1];
    }

    int l, u;
    cin >> l >> u;
    while (!(l == -1 && u == -1)) {

        cout << l << ' ' << u << ' ';
        if (l <= 0) l = 1;
        if (u <= 0) u = 1;
        cout << p1[u] - p1[l - 1] << ' ' << p2[u] - p2[l - 1] << '\n';


        cin >> l >> u;
    }
}
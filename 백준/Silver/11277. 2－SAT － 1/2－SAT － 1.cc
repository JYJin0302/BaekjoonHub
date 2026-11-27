#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> inp;
bool ansfound = 0;

void solve(int x) {

    for (auto i : inp) {
        int a, b;
        tie(a, b) = i;

        bool na = (a < 0);
        bool nb = (b < 0);

        bool ta = (1 << abs(a)) & x;
        bool tb = (1 << abs(b)) & x;

        if ((na ^ ta) || (nb ^ tb)) continue;
        else return;
    }

    ansfound = 1;
}

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        inp.push_back({ a, b });
    }

    for (int x = 0; x < (1 << n); x++) {
        solve(x << 1);
    }

    cout << ansfound;
}
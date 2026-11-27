#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> inp(n), A;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        inp[i] = { a, b };

        A.push_back({ a, 0 });
        A.push_back({ b, 1 });
    }

    sort(A.begin(), A.end());

    int c = 0, ans = 0, ansi = -1;
    for (auto i : A) {

        if (i.second == 0) c++;
        else c--;

        if (c > ans) {
            ans = c;
            ansi = i.first;
        }
    }

    cout << ans << '\n';

    for (int i = 0; i < n; i++) {
        if (inp[i].first <= ansi && inp[i].second >= ansi) cout << i + 1 << ' ';
    }
    cout << '\n';
}
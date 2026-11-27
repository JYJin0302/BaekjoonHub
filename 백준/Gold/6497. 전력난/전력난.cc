#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int n) {
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}

int main() {

    int n, m;
    cin >> n >> m;
    while (!(n == 0 && m == 0)) {

        root = vector<int>(n);
        for (int i = 0; i < n; i++) root[i] = i;

        int tot = 0;
        vector<tuple<int, int, int>> A;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            tot += c;
            A.push_back({ c, a, b });
        }

        sort(A.begin(), A.end());

        int ans = 0;
        for (auto i : A) {
            int a, b, c;
            tie(a, b, c) = i;

            if (find(b) != find(c)) {
                root[root[b]] = root[c];
                ans += a;
            }
        }

        cout << tot - ans << '\n';
        cin >> n >> m;

    }
}
#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int n) {
    if (n == root[n]) return n;

    return root[n] = find(root[n]);
}

int main() {

    int n, x, y;
    double a, b, c, d;
    cin >> n;

    vector<pair<double, double>> star;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        star.push_back({ a, b });
    }

    vector<tuple<double, int, int>> edge;
    for (int i = 0; i < n; i++) {
        tie(a, b) = star[i];
        for (int j = i + 1; j < n; j++) {
            tie(c, d) = star[j];
            edge.push_back({ sqrt((a - c) * (a - c) + (d - b) * (d - b)), i, j });
        }
    }

    sort(edge.begin(), edge.end());

    root = vector<int>(n);
    for (int i = 1; i < n; i++) {
        root[i] = i;
    }
    double ans = 0;
    for (auto i : edge) {
        tie(a, x, y) = i;
        if (find(x) == find(y)) continue;
        ans += a;
        root[find(x)] = find(y);
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;
}
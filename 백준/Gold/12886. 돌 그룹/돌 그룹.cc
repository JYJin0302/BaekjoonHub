#include <bits/stdc++.h>
using namespace std;

bool v[501][501];

pair<int, int> select(int n1, int n2, int n3) {
    if (n1 > n2) swap(n1, n2);
    if (n2 > n3) swap(n2, n3);
    if (n1 > n2) swap(n1, n2);
    return { n1, n2 };
}

int main() {

    int a, b, c;
    cin >> a >> b >> c;

    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    int tot = a + b + c;
    if (tot % 3 != 0) {
        cout << 0;
        return 0;
    }

    v[a][b] = 1;
    queue<pair<int, int>> q;
    q.push({ a, b });
    while (!q.empty()) {

        int x, y;
        tie(x, y) = q.front();
        q.pop();

        int z = tot - x - y;

        int a, b;
        tie(a, b) = select(x * 2, y - x, z);
        if (!v[a][b]) {
            v[a][b] = 1;
            q.push({ a, b });
        }

        tie(a, b) = select(x, y * 2, z - y);
        if (!v[a][b]) {
            v[a][b] = 1;
            q.push({ a, b });
        }

        tie(a, b) = select(x * 2, y, z - x);
        if (!v[a][b]) {
            v[a][b] = 1;
            q.push({ a, b });
        }
    }

    int t = tot / 3;
    cout << v[t][t];


}
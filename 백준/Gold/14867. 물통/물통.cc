#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> cnt;

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    cnt[{0, 0}] = 1;
    while (!q.empty()) {

        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if (cnt[{a, y}] == 0) {
            cnt[{a, y}] = cnt[{x, y}] + 1;
            q.push({ a, y });
        }
        if (cnt[{0, y}] == 0) {
            cnt[{0, y}] = cnt[{x, y}] + 1;
            q.push({ 0, y });
        }
        if (cnt[{x, b}] == 0) {
            cnt[{x, b}] = cnt[{x, y}] + 1;
            q.push({ x, b });
        }
        if (cnt[{x, 0}] == 0) {
            cnt[{x, 0}] = cnt[{x, y}] + 1;
            q.push({x, 0 });
        }

        // x -> y
        int ny = min(b, y + x);
        int nx = x + y - ny;
        if (cnt[{nx, ny}] == 0) {
            cnt[{nx, ny}] = cnt[{x, y}] + 1;
            q.push({ nx, ny });
        }

        nx = min(a, x + y);
        ny = x + y - nx;
        if (cnt[{nx, ny}] == 0) {
            cnt[{nx, ny}] = cnt[{x, y}] + 1;
            q.push({ nx, ny });
        }
    }

    cout << cnt[{c, d}] - 1;

}
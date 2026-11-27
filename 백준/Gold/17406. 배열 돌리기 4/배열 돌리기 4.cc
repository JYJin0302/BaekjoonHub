#include <bits/stdc++.h>
using namespace std;


int n, m, k;
int grid[50][50];
int tt[50][50];

vector<tuple<int, int, int>> A;
vector<int> order;

void spin(int x) {

    int a, b, c;
    tie(a, b, c) = A[x];
    a--, b--;

    for (int d = 1; d <= c; d++) {

        int base = tt[a + d][b];
        int ta = a + d, tb = b;
        while (tb <= b + d - 1) {
            tt[ta][tb] = tt[ta][tb + 1];
            tb++;
        }

        while (ta >= a - d + 1) {
            tt[ta][tb] = tt[ta - 1][tb];
            ta--;
        }

        while (tb >= b - d + 1) {
            tt[ta][tb] = tt[ta][tb - 1];
            tb--;
        }

        while (ta <= a + d - 1) {
            tt[ta][tb] = tt[ta + 1][tb];
            ta++;
        }

        while (tb <= b - 2) {
            tt[ta][tb] = tt[ta][tb + 1];
            tb++;
        }

        tt[ta][tb] = base;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        A.push_back({ a, b, c });
    }

    order = vector<int>(k);
    for(int i = 0; i < k; i++) order[i] = i;

    int ans = 1000000;
    do {

        // set temp grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tt[i][j] = grid[i][j];
            }
        }

        for (int i : order) spin(i);

        int tmin = 1000000;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < m; j++) {
                temp += tt[i][j];
            }
            tmin = min(tmin, temp);
        }
        ans = min(ans, tmin);

    } while (next_permutation(order.begin(), order.end()));

    cout << ans;
}
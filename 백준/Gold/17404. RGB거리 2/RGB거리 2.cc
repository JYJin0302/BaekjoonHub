#include <bits/stdc++.h>
using namespace std;
#define INF 10000000

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n, a, b, c, x, y, z;

    cin >> n;

    vector<vector<int>> cost;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cost.push_back({ a, b, c });
    }

    vector<int> ans = { cost[0][0], INF, INF };
    for (int i = 1; i < n; i++) {
        int a, b, c;

        a = min(ans[1], ans[2]) + cost[i][0];
        b = min(ans[0], ans[2]) + cost[i][1];
        c = min(ans[0], ans[1]) + cost[i][2];

        ans = { a, b, c};
    }
    int ans1 = min(ans[1], ans[2]);

    ans = { INF, cost[0][1], INF };
    for (int i = 1; i < n; i++) {
        int a, b, c;

        a = min(ans[1], ans[2]) + cost[i][0];
        b = min(ans[0], ans[2]) + cost[i][1];
        c = min(ans[0], ans[1]) + cost[i][2];

        ans = { a, b, c };
    }
    int ans2 = min(ans[0], ans[2]);

    ans = { INF, INF, cost[0][2]};
    for (int i = 1; i < n; i++) {
        int a, b, c;

        a = min(ans[1], ans[2]) + cost[i][0];
        b = min(ans[0], ans[2]) + cost[i][1];
        c = min(ans[0], ans[1]) + cost[i][2];

        ans = { a, b, c };
    }
    int ans3 = min(ans[0], ans[1]);

    cout << min({ ans1, ans2, ans3 });
}
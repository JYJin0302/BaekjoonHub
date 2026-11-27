#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, a, b, c;
    cin >> n >> d;
    vector<vector<int>> base;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (b - a <= c || b > d) continue;
        base.push_back({ a, b, b - a - c });
    }
    sort(base.begin(), base.end());

    int size = base.size();
    if (size == 0) { cout << d; return 0; }
    vector<int> dp(size);
    dp[0] = base[0][2];
    for (int i = 1; i < size; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (base[j][1] <= base[i][0])
                temp = max(temp, dp[j]);
        }
        dp[i] = temp + base[i][2];
    }

    cout << d - *max_element(dp.begin(), dp.end());
}
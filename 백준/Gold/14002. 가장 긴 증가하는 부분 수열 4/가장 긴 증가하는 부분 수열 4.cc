#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a;
    cin >> n;
    vector<int>A(n);
    for (auto& i : A)cin >> i;

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) temp = max(temp, dp[j]);
        }
        dp[i] = temp + 1;
    }

    stack<int> ans;
    int ind1 = max_element(dp.begin(), dp.end()) - dp.begin();
    int cnt = dp[ind1] - 1;
    ans.push(ind1);
    for (int i = ind1-1; i >= 0; i--) {
        if (A[i] < A[ind1] && dp[i] == cnt) {
            ans.push(i);
            cnt--;
            ind1 = i;
        }
    }
    cout << ans.size() << '\n';
    while (!ans.empty()) {
        a = ans.top();
        ans.pop();
        cout << A[a] << ' ';
    }
}
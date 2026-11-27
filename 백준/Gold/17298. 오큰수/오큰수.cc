#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>A(n);
    for (auto& i : A) cin >> i;

    vector<int> ans(n);

    stack<pair<int ,int>> st;
    for (int i = 0; i < n; i++) {
        if (st.empty() || st.top().first >= A[i]) st.push({ A[i], i });
        else {
            while (!st.empty() && st.top().first < A[i]) {
                ans[st.top().second] = A[i];
                st.pop();
            }
            st.push({ A[i], i });
        }
    }
    for (int i : ans) {
        if (i == 0) cout << -1 << ' ';
        else cout << i << ' ';
    }
}
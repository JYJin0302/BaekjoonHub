#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n;
    vector<pair<int, int >> base;
    vector<int> A(n), B(n);

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        base.push_back({a, b});
    }

    sort(base.begin(), base.end());

    for (int i = 0; i < n; i++) {
        A[i] = base[i].first;
        B[i] = base[i].second;
    }

    vector<int> lis;
    vector<int> save(n); // ind

    for (int i = 0; i < n; i++) {
        int it = lower_bound(lis.begin(), lis.end(), B[i]) - lis.begin();
        if (it == lis.size()) lis.push_back(B[i]);
        else lis[it] = B[i];
        save[i] = it;
    }

    vector<bool> used(n);
    int cnt = lis.size() - 1;
    int curr = 1000000;
    for (int i = n - 1; i >= 0; i--) {
        if (save[i] == cnt && B[i] < curr) {
            used[i] = 1;
            cnt--;
            curr = B[i];
        }
    }

    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (!used[i]) res.push_back(A[i]);
    }
    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (int i : res) cout << i << '\n';

}
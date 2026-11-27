#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n;

    vector<int> A(n);
    for(auto & i : A) cin >> i;

    vector<int> lis;
    vector<int> save(n); // ind

    for (int i = 0; i < n; i++) {
        int it = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
        if (it == lis.size()) lis.push_back(A[i]);
        else lis[it] = A[i];
        save[i] = it;
    }

    vector<int> ans;
    int cnt = lis.size() - 1;
    int curr = 1000000001;
    for (int i = n - 1; i >= 0; i--) {
        if (save[i] == cnt && A[i] < curr) {
            ans.push_back(A[i]);
            cnt--;
            curr = A[i];
        }
    }

    cout << ans.size() << '\n';
    for (auto i = ans.rbegin(); i != ans.rend(); i++) {
        cout << *i << ' ';
    }
}
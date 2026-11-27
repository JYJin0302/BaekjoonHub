#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> ans;
    vector<int> ::iterator it;
    for (int i : A) {
        it = lower_bound(ans.begin(), ans.end(), i);
        if (it == ans.end()) ans.push_back(i);
        else ans[it - ans.begin()] = i;
    }
    cout << ans.size();
}
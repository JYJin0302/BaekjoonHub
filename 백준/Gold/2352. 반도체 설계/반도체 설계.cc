#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

int main() {
    cin >> n;
    vector<int> base(n);
    for (auto& i : base) cin >> i;

    ans.push_back(base[0]);
    for (int i : base) {
        if (ans.back() < i) ans.push_back(i);
        else {
            auto it = lower_bound(ans.begin(), ans.end(), i);
            *it = i;
        }
    }

    cout << ans.size();
}
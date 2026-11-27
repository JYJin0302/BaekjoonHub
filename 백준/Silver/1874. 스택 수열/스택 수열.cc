#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> inp(n);
    for (auto& i : inp) cin >> i;

    stack<int> b;
    vector<char> ans;
    bool ok = true;
    int used = 0;
    for (int k : inp) {
        if (!b.empty() && b.top() > k) { ok = false; break; }
        for (int i = used + 1; i <= k; i++) { b.push(i); ans.push_back('+'); }
        b.pop();
        ans.push_back('-');
        used = max(used,k);
    }

    if (ok) {
        for (char i : ans) cout << i << '\n';
    }
    else cout << "NO";

}
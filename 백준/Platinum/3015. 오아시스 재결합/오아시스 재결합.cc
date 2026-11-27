#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    stack<int> s;
    map<int, int> cnt;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        while (!s.empty() && s.top() <= a) {
            ans += cnt[s.top()];
            if (s.top() != a) cnt[s.top()] = 0;
            s.pop();
        }

        cnt[a]++;
        if (!s.empty()) ans++;
        s.push(a);
    }
    cout << ans;
}
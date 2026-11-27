#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a1, a2;
ll grid[10] = { 0, 1, 3, 6, 10, 15, 21, 28, 36, 45 };

ll solve(string s) {
    
    ll ans = 0;
    ll len = s.size();
    if (len == 1) return grid[s[0] - '0'];

    for (ll i = 0; i < len; i++) {
        ll t1, t2;
        ll b = s[i] - '0';
        if (i == 0) {
            t2 = stoll(s.substr(i + 1, len));
            ans += pow(10, len - i - 1) * grid[max(0ll, b - 1)];
            ans += (t2 + 1) * b;
        }
        else if (i == len - 1) {
            t1 = stoll(s.substr(0, i));
            ans += t1 * grid[9] + grid[b];
        }
        else {
            t1 = stoll(s.substr(0, i));
            t2 = stoll(s.substr(i + 1, len));
            ans += t1 * grid[9] * pow(10, len - i - 1) + grid[max(0ll, b-1)] * pow(10, len - 1 - i) + b * (t2+1);
        }
    }
    return ans;
}



int main() {
    string l, u;
    cin >> l >> u;

    a1 = solve(u);
    a2 = solve(to_string(max(0ll, stoll(l) - 1)));

    cout << a1 - a2;
}
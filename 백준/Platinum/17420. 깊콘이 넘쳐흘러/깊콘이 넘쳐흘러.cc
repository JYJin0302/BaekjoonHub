#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b, c, d;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;
    vector<int> B(n);
    for (auto& i : B) cin >> i;

    vector<pair<int, int>> base(n);
    for (int i = 0; i < n; i++) {
        base[i] = { B[i], A[i] };
    }

    sort(base.begin(), base.end());

    ll ans = 0;

    // level, day
    pair<ll, ll> curr = { 0, 0 };
    pair<ll, ll> pre = { 0, 0 };

    for (int i = 0; i < n; i++) {
        tie(b, a) = base[i];   
        

        ll temp = max((b - a + 29) / 30, 0ll);
        a += temp * 30;
        ans += temp;


        ll k = (curr.second == b ? pre.first : curr.first);
        if (a < k){
            temp = max((k - a + 29) / 30, 0ll);
            a += temp * 30;
            ans += temp;
        }        
        
        if (b != curr.second) {
            tie(c, d) = curr;
            pre = { c, d };
        }

        curr.first = max(curr.first, a);
        curr.second = b;

    }
    cout << ans;

}
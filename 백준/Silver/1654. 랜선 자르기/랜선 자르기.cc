#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll k, n, ans = 0;
vector<ll> A;
void search(ll l, ll r) {
    if (l > r) return;
    ll mid = (l + r) / 2;

    ll temp = 0;
    for (ll i : A) temp += i / mid;

    
    if (temp >= n) {
        ans = max(ans, mid);
        if (l == r) return;
        search(mid+1, r);
    }
    else {
        if (l == r) return;
        search(l, mid - 1);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;
    A = vector<ll>(k);
    for (auto& i : A) cin >> i;

    ll r = *max_element(A.begin(), A.end());

    search(1, r);
    cout << ans;

}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0 ,-1 };

ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1)res = res * b % mod;
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

void solve() {

    ll n, k;
    cin >> n >> k;
    k++;
    vector<ll> A(n), B(n);
    for (auto& i : A) {
        cin >> i;
    }
    for (auto& i : B) cin >> i;
    for (int i = 0; i < n; i++) {
        A[i] = (k + B[i] - A[i]) % k;
    }

    ll ans = A[0];

    priority_queue<ll> pq;
    
    for (int i = 1; i < n; i++) {

        if (A[i - 1] >= A[i]) {
            //cout << "pqadd : " << A[i] + k - A[i - 1] << '\n';
            pq.push(-(A[i] + k - A[i - 1]));
        }
        else {
           // cout << "pqadd: " << A[i] - A[i - 1] << '\n';
            pq.push(-(A[i] - A[i-1]));
        }

        if (A[i - 1] < A[i]) {
           //cout << "idx : " << i << " add: " << pq.top() << '\n';
            ans += -pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int nxt[505050];
int lst[505050];
void solve() {

    int n;
    cin >> n;

    vector<string> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];

        nxt[i] = -1;
        lst[i] = i;
    }

    ll start = (ll)n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        int ta = lst[a];
        nxt[ta] = b;
        lst[a] = lst[b];
        start -= b;
    }

    for (int i = 0; i < n; i++) {
        cout << A[start];
        start = nxt[start];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
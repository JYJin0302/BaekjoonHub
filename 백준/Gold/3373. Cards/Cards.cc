#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int L[202020], R[202020];
void solve() {

    int n;
    cin >> n;

    int ans = 0;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);
        ans += a;
        A.push_back(b + a);
    }
    sort(A.rbegin(), A.rend());

    for (int i = 0; i < n / 2; i++) ans -= A[i];
    cout << ans << '\n';


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
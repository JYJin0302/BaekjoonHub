#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) A[i] = i + 1;
    for (int j = 0; j < n; j++) {
        int x;
        cin >> x;

        int ti = j;
        while (x--) {
            swap(A[ti], A[ti - 1]);
            ti--;
        }
    }
    for (auto f : A) cout << f << ' ';
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
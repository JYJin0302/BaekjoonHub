#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int ix = 0;
    while (ix < n) {

        int nx = ix + 1;
        while (nx < n && A[nx] > A[nx - 1]) nx++;

        ix = nx - 1;
        cout << ix + 1 << '\n';
        nx = ix + 1;
        while (nx < n && A[nx] < A[nx - 1]) nx++;
        ix = nx;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
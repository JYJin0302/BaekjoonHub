#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair



void solve() {

    int n; cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> pos(10, -2);
    pos[0] = -1;

    vector<int> sA(n);
    sA[0] = A[0];
    for (int i = 1; i < n; i++) sA[i] = sA[i - 1] + A[i];

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        int v = sA[i] % 10;

        if (pos[v] == -2) pos[v] = i;
        else {
            ans[pos[v]+1] = i - pos[v];
        }
        pos[v] = i;
    }

    for (auto i : ans) cout << i << ' ';


}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

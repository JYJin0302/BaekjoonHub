#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;
int A[2525];
int L[5050], R[5050];
int P[5050];
int ix = 0, ord = 1;

string res;
void dfs(int v, int dep = 0) {

    if (ix < n && dep == A[ix]) {
        ix++;
        res += '(';
        res += ')';
        return;
    }
    if (ix == n || dep > A[ix]) {
        cout << "NIE\n";
        exit(0);
    }

    L[v] = ++ord;
    res += '(';
    dfs(ord, dep + 1);
    R[v] = ++ord;
    dfs(ord, dep + 1);
    res += ')';
}

void solve() {

    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    dfs(1);

    if (ix != n) {
        cout << "NIE\n";
        return;
    }


    for (int i = 1; i <= ord; i++) {
        if (L[i]) {
            P[L[i]] = i;
            P[R[i]] = i;
        }
    }

    for (int i = 1; i <= ord; i++) cout << P[i] << ' ';
    cout << '\n';
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
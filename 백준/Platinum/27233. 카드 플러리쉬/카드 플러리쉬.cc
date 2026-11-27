#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

int n;

vector<pair<int, pair<int, int>>> ans;

vector<int> A;
void goShuffle(int a, int b) {

    if (b == n - 1) {
        ans.push_back(mp(2, mp(n - a - 1, b)));
    }
    else {
        ans.push_back(mp(3, mp(n - b - 1, n - a - 1)));
    }
    // 0 - a, a+1 - b, b+1 ~ n-1
    vector<int> res;

    for (int i = b + 1; i < n; i++) {
        res.push_back(A[i]);
    }
    for (int i = a + 1; i <= b; i++) res.push_back(A[i]);
    for (int i = 0; i <= a; i++) res.push_back(A[i]);


    A = res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    A = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> A[i];


    while (1) {

        int ix = 0;
        while (ix + 1 < n && A[ix + 1] == (A[ix] % n) + 1) ix++;

        if (ix == n - 1) break;

        int nx = (A[0] + n - 2) % n + 1;

        int tx = 0;
        while (tx < n && A[tx] != nx) tx++;
        //while (tx > 0 && A[tx - 1] == A[tx] - 1) tx--;


        goShuffle(ix, tx);

        /* for (auto f : A)cout << f << ' ';
         cout << '\n';*/
    }
    if (A[0] != 1) {
        for (int i = 1; i < n; i++) {
            if (A[i] == 1) {
                goShuffle(i - 1, n - 1);
                break;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto f : ans) {

        int t = f.first;
        int a, b;
        tie(a, b) = f.second;

        if (t == 2) cout << t << ' ' << a << '\n';
        else cout << t << ' ' << a << ' ' << b << '\n';

    }

}
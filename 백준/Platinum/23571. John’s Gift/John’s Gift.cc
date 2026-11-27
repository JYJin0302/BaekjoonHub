#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

ll dpL[1000010][2];
ll dpR[1000010][2];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> A(n), B(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B)cin >> i;

    sort(all(A));
    sort(all(B));

    /*for (auto i : A) cout << i << ' ';
    cout << '\n';
    for (auto i : B) cout << i << ' ';
    cout << '\n';*/
    dpL[1][0] = abs(A[0] - B[0]);
    dpL[1][1] = abs(A[0] - B[1]);

    for (int i = 2; i <= n; i++) {
        dpL[i][0] = max(dpL[i - 1][0], abs(A[i - 1] - B[i - 1]));
        //dpL[i][1] min(max(dpL[i-1][1] , abs(A[i-1] - B[i])), max(dpL[i-1][0], abs(A[i-1]-[B[i]]))
        if (i < n) dpL[i][1] = min(max(dpL[i - 1][1], abs(A[i - 1] - B[i])), max(dpL[i - 1][0], abs(A[i - 1] - B[i])));
        else dpL[i][1] = 1e18;
    }

    /*cout << "DPL: \n";
    for (int i = 1; i <= n; i++) {
        cout << dpL[i][0] << ' ';
    }
    cout << '\n';
    for (int i = 1; i < n; i++) {
        cout << dpL[i][1] << ' ';
    }
    cout << "X \n";*/

    dpR[n][0] = abs(A[n - 1] - B[n - 1]);
    dpR[n][1] = abs(A[n - 1] - B[n - 2]);
    for (int i = n - 1; i >= 1; i--) {
        dpR[i][0] = max(dpR[i + 1][0], abs(A[i - 1] - B[i - 1]));
        if (i > 1) dpR[i][1] = min(max(dpR[i + 1][1], abs(A[i - 1] - B[i - 2])), max(dpR[i + 1][0], abs(A[i - 1] - B[i - 2])));
        else dpR[i][1] = 1e18;
    }
    /*cout << "DPR: \n";
    for (int i = 1; i <= n; i++) {
        cout << dpR[i][0] << ' ';
    }
    cout << '\n';
    cout << "X ";
    for (int i = 2; i <= n; i++) {
        cout << dpR[i][1] << ' ';
    }
    cout << "\n";*/

    int ansi = -1;
    ll ansval = 1e18;

    for (int i = 1; i <= n; i++) {
        ll tval = 0;
        tval = min(max(dpL[i-1][0], dpR[i+1][1]), max(dpL[i-1][1], dpR[i+1][0]));

        if (tval < ansval) {
            ansval = tval;
            ansi = i;
        }
    }
    cout << A[ansi - 1];
}
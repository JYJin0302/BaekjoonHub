#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int cnt[6];
// 1, 2, 1+1, 2+1, 1+1+1
string res[6] = { "", "1", "2", "(1+1)", "(2+1)", "(1+1+1)" };

void solve() {

    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 3) A.push_back(x);
        else cnt[x]++;
    }
    sort(all(A));

    while (cnt[1] >= 2) {
        if (cnt[2] + cnt[3] >= 2) {
            if (cnt[2]) {
                cnt[2]--; cnt[4]++;
            }
            else {
                cnt[3]--;
                cnt[5]++;
            }
            cnt[1]--;
        }
        else {
            cnt[3]++;
            cnt[1] -= 2;
        }
    }

    bool pv = 0;
    if (cnt[1]) {
        if (cnt[2]) {
            cnt[1]--;
            cnt[2]--;
            cnt[4]++;
        }
        else if (cnt[3]) {
            cnt[1]--;
            cnt[3]--;
            cnt[5]++;
        }
        else if (cnt[4]) {
            cnt[1]--;
            pv = 1;
            cout << "(2+1+1)";
            cnt[4]--;
        }
        else if (cnt[5]) {
            cnt[1]--;
            pv = 1;
            cout << "(1+1+1+1)";
            cnt[5]--;
        }
        else if (!A.empty()) {
            cnt[1]--;
            pv = 1;
            cout << "(" << A[0] << "+1)";
            A.erase(A.begin());
        }
    }

    for (int i = 1; i <= 5; i++) {
        while (cnt[i]--) {
            if (pv) cout << '*';
            cout << res[i];
            pv = 1;
        }
    }
    for (auto f : A) {
        if (pv) cout << '*';
        cout << f;
        pv = 1;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
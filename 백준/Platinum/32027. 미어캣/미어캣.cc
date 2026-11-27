#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;
    vector<int> L, R;
    vector<int> Lpos, Rpos;

    vector<bool> dir(n);
    for (int i = 0; i < n; i++) {
        int x;
        char c;
        cin >> x >> c;

        if (c == 'L') {
            L.push_back(x);
            Lpos.push_back(i);
            dir[i] = 0;
        }
        else {
            R.push_back(x);
            Rpos.push_back(i);
            dir[i] = 1;
        }
    }

    sort(all(L));
    sort(all(R));
    sort(all(Lpos));
    sort(all(Rpos));

    int ans = 0;
    int sz = L.size();
    int sz2 = R.size();

    for (int i = 0; i <= sz; i++) {

        vector<int> A(n, -1);

        int pos = 0;
        for (int j = 0; j < i; j++) {
            A[Lpos[j]] = L[sz - i + j];
            pos = Lpos[j] + 1;
        }
        for (int j = i; j < sz; j++) {
            A[Lpos[j]] = L[sz - 1 - j];
        }

        int ix = sz2 - 1;
        for (int j = pos; j < n; j++) {
            if (A[j] == -1) {
                A[j] = R[ix--];
            }
        }
        for (int j = pos; j >= 0; j--) {
            if (A[j] == -1) A[j] = R[ix--];
        }


        int cnt = 0;
        int pv = -1;
        for (int i = 0; i < n; i++) {
            if (!dir[i] && A[i] > pv) {
                cnt++;
            }
            pv = max(pv, A[i]);
        }

        pv = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (dir[i] && A[i] > pv) {
                cnt++;
            }
            pv = max(pv, A[i]);
        }

        ans = max(ans, cnt);
    }

    for (auto& f : Lpos) f = n - 1 - f;
    for (auto& f : Rpos) f = n - 1 - f;
    swap(Lpos, Rpos);
    for (auto f : Lpos) dir[f] = 0;
    for (auto f : Rpos) dir[f] = 1;
    sort(all(Lpos));
    sort(all(Rpos));
    swap(L, R);

    sz = L.size();
    sz2 = R.size();

    for (int i = 0; i <= sz; i++) {

        vector<int> A(n, -1);

        int pos = 0;
        for (int j = 0; j < i; j++) {
            A[Lpos[j]] = L[sz - i + j];
            pos = Lpos[j] + 1;
        }
        for (int j = i; j < sz; j++) {
            A[Lpos[j]] = L[sz - 1 - j];
        }

        int ix = sz2 - 1;
        for (int j = pos; j < n; j++) {
            if (A[j] == -1) {
                A[j] = R[ix--];
            }
        }
        for (int j = pos; j >= 0; j--) {
            if (A[j] == -1) A[j] = R[ix--];
        }

        int cnt = 0;
        int pv = -1;
        for (int i = 0; i < n; i++) {
            if (!dir[i] && A[i] > pv) {
                cnt++;
            }
            pv = max(pv, A[i]);
        }

        pv = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (dir[i] && A[i] > pv) {
                cnt++;
            }
            pv = max(pv, A[i]);
        }

        ans = max(ans, cnt);
    }



    cout << ans << '\n';

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n;
    cin >> n;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    vector<pair<pair<int, int>, int>> pos, neg;

    int tot = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {

        int val = 0, mv = 0;
        for (auto f : A[i]) {
            if (f == '(') val++;
            else val--;
            mv = min(mv, val); 
        }

        tot += val;

        if (val >= 0) {
            pos.push_back(mp(mp(mv, val), i));

           // cout << "ADd: " << mv << ' ' << val << ' ' << i << '\n';
        }
        else {
            reverse(A[i].begin(), A[i].end());
            val = 0, mv = 0;
            for (auto f : A[i]) {
                if (f == ')') val++;
                else val--;
                mv = min(mv, val);
            }

            neg.push_back(mp(mp(mv, val), i));
            //cout << "add: " << mv << ' ' << val << ' ' << i << '\n';
            reverse(A[i].begin(), A[i].end());
        }
    }

    if (tot != 0) {
        cout << "impossible\n";
        return;
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    for (auto& f : pos) ans.push_back(f.second);
    for (auto& f : neg) ans.push_back(f.second);

    int val = 0;
    for (auto f : ans) {
        for (auto c : A[f]) {
            if (c == '(') val++;
            else val--;
            if (val < 0) {
                cout << "impossible\n";
                return;
            }
        }

    }

    for (auto f : ans) cout << f + 1 << '\n';

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}
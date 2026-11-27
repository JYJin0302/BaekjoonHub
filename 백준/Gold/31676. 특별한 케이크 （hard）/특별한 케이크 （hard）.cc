#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int T[101010];
vector<int> d[101010];

void solve() {

    string s;
    cin >> s >> s >> s >> s;

    int n;
    cin >> n;

    vector<int> pos(n + 1), neg(n + 1);

    int pcnt = 0;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        vector<int> A(k);
        for (auto& f : A) cin >> f;
        d[i] = A;
        cin >> T[i];

        if (T[i] == 1) {
            for (auto f : A) pos[f]++;
            pcnt++;
        }
        else {
            for (auto f : A) neg[f]++;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        bool isin = 0;
        for (auto f : d[i]) if (f == i) isin = 1;

        if (isin ^ T[i]) {
            for (auto f : d[i]) {
                if (T[i] == 1) {
                    pos[f]--;
                    neg[f]++;
                }
                else {
                    neg[f]--;
                    pos[f]++;
                }
            }
            
            if (T[i] == 1) pcnt--;
            else pcnt++;


            if (pos[i] == pcnt && neg[i] == 0) {
                ans.push_back(i);
            }
        

            if (T[i] == 1) pcnt++;
            else pcnt--;

            for (auto f : d[i]) {
                if (T[i] == 0) {
                    pos[f]--;
                    neg[f]++;
                }
                else {
                    neg[f]--;
                    pos[f]++;
                }
            }
        }

    }

    if (ans.empty()) cout << "swi\n";
    else for (auto f : ans) cout << f << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
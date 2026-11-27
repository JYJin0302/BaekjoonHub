#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> ix[4];

void solve() {

    string a, b, c;
    cin >> a >> b >> c;

    int n = a.size();
    string ans(n, '_');
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && a[i] == c[i]) {
            ans[i] = a[i];
        }
        else if (a[i] == b[i]) {
            ix[2].push_back(i);
        }
        else if (a[i] == c[i]) {
            ix[1].push_back(i);
        }
        else if (b[i] == c[i]) {
            ix[0].push_back(i);
        }
        else {
            ix[3].push_back(i);
        }
    }

    int cA = ix[0].size();
    int cB = ix[1].size();
    int cC = ix[2].size();
    int d = ix[3].size();

    for (int i = 0; i < d; i++) {
        int pos = ix[3][i];
        if (cA >= cB && cA >= cC) {
            ans[pos] = a[pos];
            cB++, cC++;
        }
        else if (cB >= cA && cB >= cC) {
            ans[pos] = b[pos];
            cA++, cC++;
        }
        else {
            ans[pos] = c[pos];
            cB++, cA++;
        }
    }

    while (!ix[0].empty() && cA > cB + 1 && cA > cC + 1) {
        cA--;
        cB++;
        cC++;
        int pos = ix[0].back();
        ans[pos] = a[pos];
        ix[0].pop_back();
    }

    while (!ix[1].empty() && cB > cA + 1 && cB > cC + 1) {
        cA++;
        cB--;
        cC++;
        int pos = ix[1].back();
        ans[pos] = b[pos];
        ix[1].pop_back();
    }

    while (!ix[2].empty() && cC > cA + 1 && cC > cB + 1) {
        cA++;
        cB++;
        cC--;
        int pos = ix[2].back();
        ans[pos] = c[pos];
        ix[2].pop_back();
    }

    for (auto f : ix[0]) ans[f] = b[f];
    for (auto f : ix[1]) ans[f] = c[f];
    for (auto f : ix[2]) ans[f] = a[f];

    cout << max({ cA, cB, cC }) << '\n';
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
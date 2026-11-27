#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> idxLst[26];
int idx[26];

bitset<1 << 26> ans;

void solve() {

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < 26; i++) {
        idx[i] = 0;
        idxLst[i].clear();
    }
    ans.reset();
    
    for (int i = 0; i < n; i++) {
        idxLst[s[i] - 'A'].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> res;
        for (int j = 0; j < 26; j++) {
            while (idx[j] < idxLst[j].size() && idxLst[j][idx[j]] < i) idx[j]++;

            if (idx[j] < idxLst[j].size()) {
                res.push_back(mp(idxLst[j][idx[j]], j));
            }
        }
        sort(all(res));

        int val = 0;
        for (auto [a, b] : res) {
            val += 1 << b;
            ans[val] = 1;
        }
    }

    cout << ans.count() << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
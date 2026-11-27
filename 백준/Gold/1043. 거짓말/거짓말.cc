#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, a;
    cin >> n >> m;

    vector<bool> truth(n + 1);
    cin >> k;
    while (k--) {
        cin >> a;
        truth[a] = 1;
    }

    vector<vector<int>> party;

    for (int i = 0; i < m; i++) {
        cin >> k;
        vector<int> temp(k);
        for (auto& i : temp) cin >> i;
        party.push_back(temp);
    }
    bool changed = 1;
    while (changed) {

        changed = 0;
        for (auto i : party) {
            bool tell_lie = 1;
            for (int k : i) {
                if (truth[k]) tell_lie = 0;
            }
            if (!tell_lie) {
                for (int k : i) {
                    if (!truth[k]) {
                        changed = 1;
                        truth[k] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (auto i : party) {
        bool tell_lie = 1;
        for (int k : i) {
            if (truth[k]) tell_lie = 0;
        }
        if (tell_lie) ans++;
    }
    
    cout << ans;
}
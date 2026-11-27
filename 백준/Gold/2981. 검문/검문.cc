#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> base(n);
    for (auto& i : base) cin >> i;

    sort(base.begin(), base.end());

    int mindiff = 1e9;
    for (int i = 1; i < n; i++) {
        mindiff = min(mindiff, base[i] - base[i - 1]);
    }

    vector<int> pos;
    for (int i = 2; i * i <= mindiff; i++) {
        if (i == mindiff / i) {
            pos.push_back(i);
        }
        else if (mindiff % i == 0) {
            pos.push_back(i);
            pos.push_back(mindiff / i);
        }
        
    }
    pos.push_back(mindiff);

    sort(pos.begin(), pos.end());

    vector<int> ans;
    bool ok;
    for (auto i : pos) {
        ok = true;
        int a = base[0] % i;
        for (int j = 1; j < n; j++) {
            if (base[j] % i != a) { ok = false; break; }

        }
        if (ok) cout << i << ' ';
    }

}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

bool able[55][55];

int s2i(string s) {
    if (s[0] == '0') return -1;
    int v = s[0] - 'A';
    if (s[1] == '-') v += 26;
    return v;
}

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        vector<int> p;
        for (int j = 0; j < 4; j++) {
            string tmp = s.substr(j * 2, j * 2 + 2);
            p.push_back(s2i(tmp));
        }

        for (int j = 0; j < 4; j++) {
            if (p[j] == -1) continue;
            for (int k = 0; k < 4; k++) {
                if (p[k] == -1 || k == j) continue;
                int nx = (p[k] + 26) % 52;

                able[p[j]][nx] = 1;
            }
        }

    }

    for (int i = 0; i < 52; i++) {
        for (int i2 = 0; i2 < 52; i2++) {
            for (int i3 = 0; i3 < 52; i3++) {
                able[i2][i3] |= able[i2][i] && able[i][i3];
            }
        }
    }

    for (int i = 0; i < 52; i++) {
        if (able[i][i]) {
            cout << "unbounded";
            return;
        }
    }
    cout << "bounded";

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}

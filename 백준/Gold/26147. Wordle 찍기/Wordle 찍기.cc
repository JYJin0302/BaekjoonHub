#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool valid = 1;
    vector<string> A(n);
    for (auto& i : A) {
        cin >> i;

        int g = 0, y = 0;
        for (char c : i) {
            g += (c == 'G');
            y += (c == 'Y');
        }

        if (g == 4 && y == 1) valid = 0;
    }

    if (!valid) cout << "IMPOSSIBLE";
    else {
        string ans = "ABCDE";
        cout << ans << '\n';
        for (auto i : A) {

            string res(5, 'Z');
            vector<int> idx;
            for (int j = 0; j < 5; j++) {
                if (i[j] == 'G') res[j] = ans[j];
                else idx.push_back(j);
            }
            for (int j = 0; j < idx.size(); j++) {
                int a = idx[j], b = idx[(j + 1) % idx.size()];
                if (i[a] == 'Y') res[a] = ans[b];
            }

            cout << res << '\n';

        }
    }
}
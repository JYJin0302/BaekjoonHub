#include <bits/stdc++.h>
using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    if (a.size() == b.size()) {

        int cnt = 0;
        for (int i = 0; i < a.size(); i++) cnt += (a[i] != b[i]);

        cout << cnt;

    }
    else {
        int ans = 55;
        for (int i = 0; i <= b.size() - a.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < a.size(); j++) {
                cnt += (a[j] != b[i+j]);
            }
            ans = min(ans, cnt);
        }
        cout << ans;
    }
}
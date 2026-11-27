#include <bits/stdc++.h>
using namespace std;


int n, k;
vector<int> base;
bool ok;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> k;

    base = vector<int>(n);
    for (auto& i : base) cin >> i;
    ok = true;

    int cnt = 0;
    vector<int> maxn(100);
    for (int i : base) {
        for (int k = 0; k < 100; k++) {
            if (maxn[k] == 0) {
                maxn[k] = i;
                cnt++;
                break;
            }
            else if (i > maxn[k]) {
                maxn[k] = i;
                break;
            }
        }
        if (cnt > k) {
            ok = false; break;
        }
    }

    if (ok) cout << "YES";
    else cout << "NO";
}
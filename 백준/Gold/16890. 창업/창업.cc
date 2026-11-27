#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int n = a.size();

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    string res(n, '?');
    int al = 0, ar = (n+1) / 2 - 1;
    int bl = 0, br = n / 2 - 1;
    int sl = 0, sr = n - 1;
    bool t = 1, ph = 0;
    while (sl <= sr) {
        if (b[bl] <= a[al]) ph = 1;
        if (t) {
            if (ph) {
                res[sr] = a[ar];
                sr--, ar--;
            }
            else {
                res[sl] = a[al];
                sl++, al++;
            }
        }
        else {
            if (ph) {
                res[sr] = b[br];
                sr--, br--;
            }
            else {
                res[sl] = b[bl];
                sl++, bl++;

            }
        }
        t ^= 1;
    }
    cout << res;

}
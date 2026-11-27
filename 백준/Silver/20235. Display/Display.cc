#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w, h, s;
    cin >> n >> w >> h >> s;

    vector<char> A(n);
    int manx = 0, mdx = -1;

    for (int i = 0; i < n; i++) {
        cin >> A[i];

        int mcnt = 0;
        for (int j = 0; j < h; j++) {
            string s;
            cin >> s;

            s += '.';

            int tcnt = 0;
            for (int k = 1; k <= w; k++) {
                if (s[k] == '.' && s[k - 1] == '#') tcnt++;
            }
            mcnt = max(mcnt, tcnt * 2);
        }

        if (mcnt > manx) {
            manx = mcnt;
            mdx = i;
        }

    }

    int d = (s + manx - 1) / manx;
    for (int i = 0; i < d; i++) cout << A[mdx];

}

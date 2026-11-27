#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        A[i] = (s2[i] - s1[i] + 26) % 26;
        if (A[i] == 0) A[i] = 26;
    }

    vector<int> dv;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            dv.push_back(i);
            if (n / i != i) dv.push_back(n / i);
        }
    }

    sort(dv.begin(), dv.end());

    int ans = -1;
    for (auto i : dv) {

        bool valid = 1;
        for (int ix = i; ix < n; ix++) {
            if (A[ix] != A[ix - i]) valid = 0;
        }

        if (valid) {
            ans = i;
            break;
        }
    }

    for (int i = 0; i < ans; i++) {
        cout << char('A' + A[i]-1);
    }

}
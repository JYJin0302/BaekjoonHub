#include<bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;

    long double p;
    cin >> p;

    vector<int> A(n), B(n);
    for (auto& i : A) cin >> i;

    for (int i = 1; i < n; i++) {
        B[i] = A[i] - A[i - 1];
    }
    vector<int> sB(n);
    for (int i = 1; i < n; i++) {
        sB[i] = B[i] * B[i];
        sB[i] += sB[i - 1];
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {

            // check A[i,j]

            long double a = (ld)(A[j] - A[i]) / (j - i);
            if (A[j] == A[i]) a = 0;
            long double b = (ld)sB[j] - (ld)sB[i] + a*a*(j-i);
            b -= 2 * a * (A[j] - A[i]);
            b /= j - i;

            b = sqrtl(b);

            //cout << a << ' ' << b << ' ' << i << ' ' << j << '\n';

            if (a == 0) continue;
            if (b == 0) {
                if (a > 0) ans1++;
                else ans2++;
            }
            else {
                if (a / b >= p) ans1++;
                else if (a / b <= -p) ans2++;

            }

        }
    }
    cout << ans1 << ' ' << ans2;

}

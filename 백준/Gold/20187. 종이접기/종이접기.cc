#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int grid[300][300];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    vector<char> A(2*k);
    for (auto& i : A) cin >> i;

    int l = 0, r = pow(2, k)-1,d = 0, u = pow(2, k)-1;

    for (auto i : A) {
        switch (i) {
        case 'U':
            d = (d + u) / 2 + 1;
            break;
        case 'D':
            u = (u + d) / 2;
            break;
        case 'R':
            l = (l + r) / 2 + 1;
            break;
        case 'L':
            r = (l + r) / 2;
            break;
            break;
        }
    }

    int h;
    cin >> h;

    grid[l][d] = h;
    reverse(A.begin(), A.end());

    for (auto i : A) {
        switch (i) {
        case 'U':

            for (int a = l; a <= r; a++) {
                for (int b = d; b <= u; b++) {
                    int nb = 2 * d - b - 1;
                    grid[a][nb] = grid[a][b] ^ 2;
                }
            }
            d -= (u - d + 1);

            break;
        case 'D':
            for (int a = l; a <= r; a++) {
                for (int b = d; b <= u; b++) {
                    int nb = 2 * u - b + 1;
                    grid[a][nb] = grid[a][b] ^ 2;
                }
            }
            u += (u - d + 1);
            break;
        case 'R':
            for (int a = l; a <= r; a++) {
                for (int b = d; b <= u; b++) {
                    int na = 2 * l - 1 - a;
                    grid[na][b] = grid[a][b] ^ 1;
                }
            }
            l -= (r - l + 1);
            break;
        case 'L':
            for (int a = l; a <= r; a++) {
                for (int b = d; b <= u; b++) {
                    int na = 2 * r + 1 - a;
                    grid[na][b] = grid[a][b] ^ 1;
                }
            }
            r += (r - l + 1);
            break;
            break;
        }
    }

   for (int j = u; j >= d; j--)  {
         for (int i = l; i <= r; i++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

}
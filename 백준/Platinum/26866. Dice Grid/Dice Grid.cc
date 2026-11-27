#include<bits/stdc++.h>
using ll = long long;
using namespace std;

struct Cube {

    int f, b, u, d, l, r;
    Cube() {
        f = b = u = d = l = r = -1;
    }

    Cube moveD() {
        Cube tmp;
        tmp.l = l;
        tmp.r = r;
        tmp.f = u;
        tmp.b = d;
        tmp.d = f;
        tmp.u = b;
        return tmp;
    }
    Cube moveU() {
        Cube tmp;
        tmp.l = l;
        tmp.r = r;
        tmp.f = d;
        tmp.b = u;
        tmp.d = b;
        tmp.u = f;
        return tmp;
    }

    Cube moveR() {
        Cube tmp;
        tmp.l = d;
        tmp.r = u;
        tmp.f = f;
        tmp.b = b;
        tmp.d = r;
        tmp.u = l;
        return tmp;
    }
    Cube moveL() {
        Cube tmp;
        tmp.l = u;
        tmp.r = d;
        tmp.f = f;
        tmp.b = b;
        tmp.d = l;
        tmp.u = r;
        return tmp;
    }

    void pf() {
        for (auto i : { d, l, b, f, r, u }) {
            cout << max(0, i) << ' ';
        }
        cout << '\n';
    }
};
int n;
int grid[51][51];
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

Cube ans;
bool solve(int ix, int iy, Cube curr) {

    if (ix == n - 1 && iy == n - 1) {
        ans = curr;
        return 1;
    }

    if (ix < n - 1) {
        // move down
        Cube tmp = curr.moveD();
        if (tmp.d == -1 || grid[ix + 1][iy] == tmp.d) {
            tmp.d = grid[ix + 1][iy];
            if (solve(ix + 1, iy, tmp)) {
                ans = ans.moveU();
                return 1;
            }
        }
    }

    if (iy < n - 1) {
        // move right
        Cube tmp = curr.moveR();
        if (tmp.d == -1 || grid[ix][iy+1] == tmp.d) {
            tmp.d = grid[ix][iy+1];
            if (solve(ix, iy+1, tmp)) {
                ans = ans.moveL();
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {

        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> grid[i][j];
        }

        ans = Cube();
        Cube tmp;
        tmp.d = grid[0][0];
        if (solve(0, 0, tmp)) {
            cout << "Yes\n";
            ans.pf();
        }
        else cout << "No\n";
    }
}

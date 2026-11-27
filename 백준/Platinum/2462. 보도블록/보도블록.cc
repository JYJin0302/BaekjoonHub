#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
// U R D L
vector<pair<pair<int, int>, int>> ans;
void getAns(int px, int py, int cx, int cy, int nx, int ny) {
    if ((cx + cy) & 1) {
        // | |
        if (py == cy - 1 || ny == cy + 1) {
            ans.push_back(mp(mp(cx, cy), 0));
            ans.push_back(mp(mp(cx, cy), 1));
        }
        else {
            ans.push_back(mp(mp(cx, cy), 1));
            ans.push_back(mp(mp(cx, cy), 0));
        }
        return;
    }
    // --
    // --
    if (px == cx - 1 || nx == cx + 1) {
        ans.push_back(mp(mp(cx, cy), 0));
        ans.push_back(mp(mp(cx, cy), 1));
    }
    else {
        ans.push_back(mp(mp(cx, cy), 1));
        ans.push_back(mp(mp(cx, cy), 0));
    }
}


void solve() {

    int n, m;
    cin >> n >> m;

    cout << n * m * 2 << '\n';
    ans.push_back(mp(mp(0, 0), 1));
    ans.push_back(mp(mp(0, 0), 0));
    if (n * m & 1) {
        int mx = n / 2, my = m/2;
        int px = 0, py = 0;
        int cx = 0, cy = 1;

        while (1) {
            if (cx + cy == 0) break;
            int nx = cx, ny = cy;

            if (cx == 0) {
                if (cy == m - 1) nx++;
                else ny++;
            }
            else if (cy >= 2) {
                if (cy & 1) {
                    if (cx == 1) ny--;
                    else nx--;
                }
                else {
                    if (cx == n - 1) ny--;
                    else nx++;
                }
            }
            else if (cx == 1) {
                nx--;
            }
            else {
                if ((nx + ny) % 2 == 0) nx--;
                else if (ny == 0) ny++;
                else ny--;
            }

            getAns(px, py, cx, cy, nx, ny);
            px = cx, py = cy;
            cx = nx, cy = ny;
        }

        for (auto f : ans) {
            cout << f.x.x + 1 << ' ' << f.x.y + 1 << ' ' << f.y << "\n";
            if (f.x.x == 0 && f.x.y == 1  && f.y == 0) {
                cout << 2  << ' ' << 2 << ' ' << 0 << '\n';
            }
            else if (f.x.x == 2 && f.x.y == 1 && f.y == 1) {
                cout << 2 << ' ' << 2 << ' ' << 1 << '\n';
            }
        }
        return;
    }

    if (n % 2 == 0) {
        int px = 0, py = 0;
        int cx = 0, cy = 1;
        while (1) {
            int nx = -1, ny = -1;
            if (cx + cy == 0) break;
            if (cy == 0) {
                nx = cx - 1;
                ny = cy;
            }
            else if (cx == n - 1) {
                nx = cx;
                ny = cy - 1;
            }
            else if (cx & 1) {
                if (cy == 1) nx = cx + 1, ny = cy;
                else nx = cx, ny = cy - 1;
            }
            else {
                if (cy == m - 1) nx = cx + 1, ny = cy;
                else nx = cx, ny = cy + 1;
            }
            getAns(px, py, cx, cy, nx, ny);
            px = cx, py = cy;
            cx = nx, cy = ny;
        }

        for (auto f : ans) {
            cout << f.x.x+1 << ' ' << f.x.y+1 << ' ' << f.y << "\n";
        }
        return;
    }

    int px = 0, py = 0;
    int cx = 0, cy = 1;
    while (1) {
        int nx = -1, ny = -1;
        if (cx + cy == 0) break;

        if (cx == 0) {
            if (cy == m - 1) nx = cx + 1, ny = cy;
            else nx = cx, ny = cy + 1;
        }
        else if (cy == 0) {
            nx = cx - 1, ny = cy;
        }
        else if (cy & 1) {
            if (cx == n-1) nx = cx, ny = cy-1;
            else nx = cx + 1, ny = cy;
        }
        else {
            if (cx == 1) nx = cx, ny = cy - 1;
            else nx = cx - 1, ny = cy;
        }
        getAns(px, py, cx, cy, nx, ny);
        px = cx, py = cy;
        cx = nx, cy = ny;
    }

    for (auto f : ans) {
        cout << f.x.x + 1 << ' ' << f.x.y + 1 << ' ' << f.y << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
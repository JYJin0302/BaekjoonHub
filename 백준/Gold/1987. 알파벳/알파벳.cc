#include <bits/stdc++.h>
using namespace std;

vector<string> base;
vector<bool> check;
int step[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int ans, r, c, nx, ny;

bool ingrid(int x, int y) {
    return (x >= 0 && x < r) && (y >= 0 && y < c);
}
void dfs(int x, int y, int cnt) {
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++) {
        nx = x + step[i][0];
        ny = y + step[i][1];
        
        if (ingrid(nx, ny) && !check[base[nx][ny] - 'A']) {
            int ind = base[nx][ny] - 'A';
            check[ind] = 1;
            dfs(nx, ny, cnt + 1);
            check[ind] = 0;
        }
    }
}


int main() {

    cin >> r >> c;
    base = vector<string>(r);
    check = vector<bool>(26);
    for (int i = 0; i < r; i++) {
        cin >> base[i];
    }
    check[(int)(base[0][0] - 'A')] = 1;
    ans = 1;
    dfs(0, 0, 1);

    cout << ans;
}
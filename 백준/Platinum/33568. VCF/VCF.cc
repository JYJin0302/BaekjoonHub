#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

char Grid[15][15];
char player, opponent;
int dx[] = { 0, 1, 1, 1 };
int dy[] = { 1, 0, 1, -1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < 15 && y >= 0 && y < 15;
}

vector<pair<int, int>> winningMove = {};
int validMove() {

    int mx = 0;
    bool opponent4 = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            for (int dir = 0; dir < 4; dir++) {
                if (!inGrid(i + dx[dir] * 4, j + dy[dir] * 4)) continue;
                int cnt = 0;
                vector<pair<int, int>> tmp;
                int ti = i, tj = j;
                for (int f = 0; f < 5; f++) {
                    char cur = Grid[ti][tj];
                    if (cur == player) cnt++;
                    else if (cur == 'X') tmp.push_back(mp(ti, tj));
                    else cnt -= 10;
                    ti += dx[dir];
                    tj += dy[dir];
                }

                char c1 = '.', c2 = '.';
                if (inGrid(i - dx[dir], j - dy[dir])) c1 = Grid[i - dx[dir]][j - dy[dir]];
                if (inGrid(i + 5 * dx[dir], j + dy[dir] * 5)) c2 = Grid[i + dx[dir] * 5][j + dy[dir] * 5];

                if (c1 != player && c2 != player) {
                    mx = max(mx, cnt);
                    if (cnt == 4) winningMove.push_back(tmp[0]);
                    if (cnt == 5) return 2;
                }
                if (c1 != opponent && c2 != opponent && cnt == -40) opponent4 = 1;
            }
        }
    }

    return !opponent4 && mx == 4;
}


vector<pair<int, int>> moveList[3];

bool ansFound = 0;
int ansDep = 0;
void goSimul(int x, int y, int dep = 0) {
    if (Grid[x][y] != 'X') return;
    winningMove.clear();
    // player moved
    
    Grid[x][y] = player;
    moveList[dep].push_back(mp(x, y));

    int res = validMove();
    if (res == 2) {
        Grid[x][y] = 'X';
        ansFound = 1;
        ansDep = dep;
        return;
    }
    if (res == 0 || dep == 2) {
        moveList[dep].pop_back();
        Grid[x][y] = 'X';
        return;
    }
    sort(all(winningMove));
    winningMove.erase(unique(all(winningMove)), winningMove.end());
    if (winningMove.size() >= 2) {
        Grid[x][y] = 'X';
        moveList[dep + 1].push_back(winningMove[0]);
        moveList[dep + 1].push_back(winningMove[1]);
        ansFound = 1;
        ansDep = dep + 1;
        return;
    }

    auto [tx, ty] = winningMove[0];
    Grid[tx][ty] = opponent;
    // do another move
    int mn = 100;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            goSimul(i, j, dep + 1);
            if (ansFound) {
                Grid[x][y] = 'X';
                Grid[tx][ty] = 'X';
                return;
            }
        }
    }
    Grid[tx][ty] = 'X';
    Grid[x][y] = 'X';
    moveList[dep].pop_back();
    return;
}

void solve() {

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            cin >> Grid[i][j];
        }
    }
    cin >> player;
    opponent = char('B' + 'W' - player);

    // TBD : 한 수로 가능한지 확인
    int res = validMove();
    if (res == 1) {
        cout << winningMove[0].x + 1 << ' ' << winningMove[0].y + 1 << endl;
        return;
    }


    for (int i = 0; i < 15 && !ansFound; i++) {
        for (int j = 0; j < 15 && !ansFound; j++) {
            goSimul(i, j);
        }
    }

    if (!ansFound) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i <= ansDep; i++) {
        for (auto [a, b] : moveList[i]) {
            if (Grid[a][b] == 'X') {
                cout << a + 1 << ' ' << b + 1 << endl;
                Grid[a][b] = player;
                break;
            }
        }

        /*for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                if (Grid[i][j] == 'X') cout << '.';
                else  cout << Grid[i][j];
            }
            cout << '\n';
        }*/

        if (i != ansDep) {
            int a, b;
            cin >> a >> b;
            Grid[a - 1][b - 1] = opponent;
        }
    }
   // cout << -1 << endl;

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
       
    solve();

    return 0;
}
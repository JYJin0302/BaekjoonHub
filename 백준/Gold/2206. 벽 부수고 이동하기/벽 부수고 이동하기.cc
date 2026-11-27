#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

vector<vector<int>> grid;
vector<vector<int>> g1;
vector<vector<int>> g2;
vector<vector<int>> check;

queue<pair<int, int>> q;
queue<pair<int, int>> tQ;
int n, m, cnt, ans, x, y, nx, ny, t;
int step[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool ingrid(int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

void clearqueue(queue<pair<int, int>>& cq) {
    queue<pair<int, int>> te;
    swap(cq, te);

}
void bfs(vector<vector<int>>& inter) {
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++) {

            nx = x + step[i][0];
            ny = y + step[i][1];
            
            if (!ingrid(nx, ny) || check[nx][ny]) continue;
            check[nx][ny] = 1;
            if (grid[nx][ny] == 0) {
                inter[nx][ny] = cnt;
                tQ.push(make_pair(nx, ny));
            }
            if (grid[nx][ny] == 1) {
                inter[nx][ny] = cnt;
            }
        }
    }
    swap(q, tQ);
    if (q.empty()) return;
    cnt++;
    bfs(inter);
}

int main() {
    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m));
    g1 = vector<vector<int>>(n, vector<int>(m));
    g2 = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j] - '0';
            g1[i][j] = INF;
            g2[i][j] = INF;
        }
    }
    
    check = vector<vector<int>>(n, vector<int>(m));
    check[0][0] = 1;
    g1[0][0] = 0;
    cnt = 1;
    q.push({ 0, 0 });
    bfs(g1);
    
   

    check = vector<vector<int>>(n, vector<int>(m));
    check[n - 1][m - 1] = 1;
    g2[n - 1][m - 1] = 0;
    cnt = 1;
    q.push({ n - 1, m - 1 });
    bfs(g2);
    


    ans = INF;
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        ans = min(ans, g1[i][j] + g2[i][j]);
    }
    

    if (ans == INF) cout << -1;
    else cout << ans+1;
}
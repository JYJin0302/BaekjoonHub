#include <bits/stdc++.h>
using namespace std;

int n;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
vector<string> A;

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({ i, j });
    A[i][j] = '.';
    
    while (!q.empty()) {

        int a, b;
        tie(a, b) = q.front();
        q.pop();
        
        for (int k = 0; k < 4; k++) {
            int na = a + dx[k];
            int nb = b + dy[k];
            if (inGrid(na, nb) && A[na][nb] == '*') {
                A[na][nb] = '.';
                q.push({ na, nb });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    A = vector<string> (n);
    for (auto& i : A) cin >> i;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == '*') {
                cnt++;

                bfs(i, j);
            }
        }
    }
    cout << cnt;
}
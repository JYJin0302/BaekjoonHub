#include <bits/stdc++.h>
using namespace std;

int n, a, b, ta, tb, totaltime = 0;
int grid[20][20];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
bool eaten;

vector<vector<bool>> check;
priority_queue<pair<int, int>> q;
priority_queue<pair<int, int>> tq;

struct Minishark {
    int size = 2;
    int cnt = 0;
    pair<int, int> place;
};

Minishark shark;
bool inGrid(int x, int y) {
    return (x >= 0 && x < n&& y >= 0 && y < n);
}

void eat(int x, int y) {
    grid[x][y] = 0;
    shark.place = { -x, -y };
    shark.cnt++;
    if (shark.cnt == shark.size) {
        shark.size++;
        shark.cnt = 0;
    }

}

void emptyqueue(priority_queue<pair<int, int>>& q) {
    priority_queue<pair<int, int>> empty;
    swap(q, empty);
}

 void move(int t = 0) {     
     while (!q.empty()) {
         tie(a, b) = q.top();
         q.pop();
         a *= -1, b *= -1;

         if (grid[a][b] != 0 && grid[a][b] < shark.size) {
             eaten = 1;
             totaltime += t;
             eat(a, b);
             return;
         }
         

         for (int i = 0; i < 4; i++){
             ta = a + dx[i];
             tb = b + dy[i];
             if (inGrid(ta, tb) && !check[ta][tb]) {
                 check[ta][tb] = 1;
                 
                 if (grid[ta][tb] <= shark.size) tq.push({ -ta, -tb });
                 
             }
         }
     }

     swap(q, tq);
     if (q.empty()) return;
     move(t + 1);
 }



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 9) { shark.place = { -i, -j }; grid[i][j] = 0; }
        }
    }
    eaten = 1;
    while (eaten) {
        check = vector<vector<bool>>(n, vector<bool>(n));
        eaten = 0;
        q.push(shark.place);
        check[-shark.place.first][-shark.place.second] = 1;
        move();
        
        emptyqueue(q);
        emptyqueue(tq);
    }

    cout << totaltime;

}
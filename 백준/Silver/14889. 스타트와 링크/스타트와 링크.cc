#include <bits/stdc++.h>
using namespace std;

int grid[21][21];
bool selected[21];
vector<int> mem1;
vector<int> mem2;
int n, mem, mindiff;

void pick(int f = 1, int cnt = 0) {
    if (cnt == mem) {
        for (int i = 1; i <= n; i++) {
            if (!selected[i]) mem2.push_back(i);
        }

        int stat1 = 0;
        int h1, h2;
        for (int i = 1; i <= mem; i++) {
            h1 = mem1[i - 1];
            for (int j = i + 1; j <= mem; j++) {
                h2 = mem1[j - 1];
                stat1 += grid[h1][h2] + grid[h2][h1];
            }
        }
        int stat2 = 0;
        for (int i = 1; i <= mem; i++) {
            h1 = mem2[i - 1];
            for (int j = i + 1; j <= mem; j++) {
                h2 = mem2[j - 1];
                stat2 += grid[h1][h2] + grid[h2][h1];
            }
        }

        mindiff = min(mindiff, abs(stat1 - stat2));

        mem2.clear();
        return;
    }

    for (int i = f; i <= n; i++) {
        if (selected[i]) continue;
        selected[i] = true;
        mem1.push_back(i);
        pick(i + 1, cnt + 1);
        selected[i] = false;
        mem1.pop_back();
    }
}


int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    
    
    
    mem = n / 2;
    mindiff = 10000;

    

    pick();
    cout << mindiff;
}
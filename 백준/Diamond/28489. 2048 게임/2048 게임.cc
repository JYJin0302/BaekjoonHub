#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool mer[16];
vector<int> move(vector<int>& grid, int dir) {
    vector<int> tmp(16);
    memset(mer, 0, sizeof mer);

    bool diff = 0;
    if (dir == 0) {
        // up
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i * 4 + j] == 0) continue;
                
                int ti = i;
                while (ti > 0) {
                    if (tmp[(ti - 1) * 4 + j] == 0) ti--;
                    else if (tmp[(ti - 1) * 4 + j] == grid[i * 4 + j] && !mer[(ti - 1) * 4 + j]) {
                        ti--;
                        mer[ti * 4 + j] = 1;
                        break;
                    }
                    else break;
                }
                tmp[ti * 4 + j] += grid[i * 4 + j];
                if (ti != i) diff = 1;
            }
        }
        if (!diff) tmp[0] = -1;
        return tmp;
    }
    if (dir == 2) {
        // down
        for (int i = 3; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (grid[i * 4 + j] == 0) continue;

                int ti = i;
                while (ti < 3) {
                    if (tmp[(ti + 1) * 4 + j] == 0) ti++;
                    else if (tmp[(ti + 1) * 4 + j] == grid[i * 4 + j] && !mer[(ti + 1) * 4 + j]) {
                        ti++;
                        mer[ti * 4 + j] = 1;
                        break;
                    }
                    else break;
                }
                tmp[ti * 4 + j] += grid[i * 4 + j];
                if (ti != i) diff = 1;
            }
        }
        if (!diff) tmp[0] = -1;
        return tmp;
    }

    if (dir == 1) {
        // right
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 0; j--) {
                if (grid[i * 4 + j] == 0) continue;

                int tj = j;
                while (tj < 3) {
                    if (tmp[i * 4 + tj + 1] == 0) tj++;
                    else if (tmp[i * 4 + tj + 1] == grid[i * 4 + j] && !mer[i * 4 + tj + 1]) {
                        tj++;
                        mer[i * 4 + tj] = 1;
                        break;
                    }
                    else break;
                }
                tmp[i * 4 + tj] += grid[i * 4 + j];
                if (tj != j) diff = 1;
            }
        }
        if (!diff) tmp[0] = -1;
        return tmp;
    }

    // left
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i * 4 + j] == 0) continue;

            int tj = j;
            while (tj > 0) {
                if (tmp[i * 4 + tj - 1] == 0) tj--;
                else if (tmp[i * 4 + tj - 1] == grid[i * 4 + j] && !mer[i * 4 + tj - 1]) {
                    tj--;
                    mer[i * 4 + tj] = 1;
                    break;
                }
                else break;
            }
            tmp[i * 4 + tj] += grid[i * 4 + j];
            if (tj != j) diff = 1;
        }
    }
    if (!diff) tmp[0] = -1;
    return tmp;     
}


double evalGrid(vector<int>& g) {

    int emptyCnt = 0;
    for (auto f : g) if (f == 0) emptyCnt++;

    int monotoneTest = 0;
    vector<int> val(4);
    for (int i = 0; i < 4; i++) {
        vector<int> tmp;
        for (int j = 0; j < 4; j++) {
            if (g[i * 4 + j]) tmp.push_back(g[i * 4 + j]);
        }
        for (int j = 1; j < (int)tmp.size(); j++) {
            int tval = log2(tmp[j]) - log2(tmp[j - 1]);
            if (tval >= 0) val[0] += tval;
            else val[2] += -tval;
        }
        tmp.clear();

        for (int j = 0; j < 4; j++) {
            if (g[j * 4 + i]) tmp.push_back(g[j * 4 + i]);
        }
        for (int j = 1; j < (int)tmp.size(); j++) {
            int tval = log2(tmp[j]) - log2(tmp[j - 1]);
            if (tval >= 0) val[1] += tval;
            else val[3] += -tval;
        }
        tmp.clear();
    }
    monotoneTest = max(val[0], val[2]) + max(val[1], val[3]);

    int maxVal = 0;
    for (auto f : g) {
        if (f) maxVal = max(maxVal, (int)log2(f));
    }


    int smooth = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            int v1 = g[i * 4 + j] ? log2(g[i * 4 + j]) : 0;
            int v2 = g[i * 4 + j - 1] ? log2(g[i * 4 + j - 1]) : 0;
            smooth += abs(v1 - v2);

            v1 = g[j * 4 + i] ? log2(g[j * 4 + i]) : 0;
            v2 = g[(j - 1) * 4 + i] ? log2(g[(j - 1) * 4 + i]) : 0;
            smooth += abs(v1 - v2);
        }
    }

    return monotoneTest + 10*maxVal - 1.4*emptyCnt - 2*smooth;
}

void printGrid(vector<int>& grid) {
    vector<string> tmp;
    int sz = 1;
    for (int i = 0; i < 16; i++) {
        string ts = to_string(grid[i]);
        tmp.push_back(ts);
        sz = max(sz, (int)ts.size());
    }

    cout << string((sz+1)* 4 - 1, '-') << '\n';
    for (int i = 0; i < 16; i++) {
        string ts = tmp[i];
        while (ts.size() < sz) ts = ' ' + ts;
        cout << ts << ' ';
        if (i % 4 == 3) cout << '\n';
    }
    cout << string((sz + 1) * 4 - 1, '-') << '\n';
}

int getRandomCell(vector<int>& g) {
    vector<int> pos;
    for (int i = 0; i < 16; i++) if (g[i] == 0) pos.push_back(i);
    if (pos.empty()) return -1;
    return pos[rng() % (int)pos.size()];
}

pair<double, int> calNext(vector<int> g, int dep) {


    vector<pair<double, int>> res;
    if (dep == 0) {
        for (int dir = 0; dir < 4; dir++) {
            vector<int> tres = move(g, dir);
            if (tres[0] == -1) continue;

            double val = 0, cnt = 0;
            for (int j = 0; j < 16; j++) {
                if (tres[j] == 0) {
                    tres[j] = 2;
                    cnt++;
                    val += evalGrid(tres);
                    tres[j] = 0;
                }
            }

            if (cnt != 0) {
                val /= cnt;
            }

            res.push_back(mp(val, dir));
        }
    }
    else {
        for (int dir = 0; dir < 4; dir++) {
            vector<int> tres = move(g, dir);
            if (tres[0] == -1) continue;

            vector<pair<double, int>> res2;
            for (int j = 0; j < 16; j++) {
                if (tres[j] == 0) {
                    tres[j] = 2;
                    res2.push_back(mp(evalGrid(tres), j));
                    tres[j] = 0;
                }
            }
            sort(all(res2));

            if (res2.empty()) res.push_back(mp(-1e5, 0));
            else {
                tres[res2.back().y] = 2;
                res.push_back(mp(calNext(tres, dep - 1).x, dir));
            }

        }
    }

    sort(all(res));
    if (res.empty()) return mp(-1e5, 0);
    return res.back();
}


void solve() {

    vector<int> Grid(16);

    vector<string> Move = { "UP", "RIGHT", "DOWN", "LEFT" };

    while (1) {

        //int x = getRandomCell(Grid);
        int x;
        cin >> x;
        if (x == -1) break;
        x--;
        Grid[x] = 2;
       // printGrid(Grid);


        int dir = calNext(Grid, 5).y;
        cout << Move[dir] << endl;
        //cin >> dir;

        Grid = move(Grid, dir);
        if (Grid[0] == -1) break;
       // printGrid(Grid);
    }

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
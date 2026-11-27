#include<bits/stdc++.h>
using namespace std;

string F;

bool chk[1 << 8];

bool check(int member) {

    stack<char> oper;
    stack<bool> val;

    int ix = 0;
    int n = F.size();
    while (ix < n) {

        if (F[ix] == ' ') {
            ix++;
            continue;
        }
        if (F[ix] == '(') {
            oper.push('(');
            ix++;
        }
        else if (F[ix] == ')') {
            while (oper.top() != '(') {
                assert(oper.top() == '|');
                oper.pop();
                bool tmp1 = val.top();
                val.pop();
                bool tmp2 = val.top();
                val.pop();
                val.push(tmp1 || tmp2);
            }
            oper.pop();
            ix++;
        }
        else {
            // alphabet
            if (ix + 1 < n && isalpha(F[ix + 1])) {
                // and / or / not
                if (F[ix] == 'a') {
                    // and
                    oper.push('&');
                    ix += 3;
                }
                else if (F[ix] == 'o') {
                    // or
                    oper.push('|');
                    ix += 2;
                }
                else {
                    // not
                    oper.push('-');
                    ix += 3;
                }
                continue;
            }
            else {
                // member
                int nx = F[ix] - 'a';
                val.push(member & (1 << nx));
                ix++;
            }
        }

        while (!oper.empty() && oper.top() == '-') {
            oper.pop();
            bool tmp = val.top();
            val.pop();
            val.push(tmp ^ 1);
        }
        while (!oper.empty() && oper.top() == '&') {
            oper.pop();
            bool tmp1 = val.top();
            val.pop();
            bool tmp2 = val.top();
            val.pop();
            val.push(tmp1 && tmp2);
        }

        //cout << "Curr res: \n";
        //stack<char> tmp = oper;
        //while (!tmp.empty()) {
        //    cout << tmp.top() << ' ';
        //    tmp.pop();
        //}
        //cout << '\n';
        //stack<bool> t2 = val;
        //while (!t2.empty()) {
        //    cout << t2.top();
        //    t2.pop();
        //}
        //cout << '\n';
    }

    while (!oper.empty()) {
        assert(oper.top() == '|');
        oper.pop();
        bool tmp1 = val.top();
        val.pop();
        bool tmp2 = val.top();
        val.pop();
        val.push(tmp1 || tmp2);
    }

    return val.top();
}


char grid[55][55];

void fill(int x, int y, int m) {

    int cnt = 0;
    vector<int> lst;
    for (int i = 0; i < 8; i++) if (m & (1 << i)) {
        lst.push_back(i);
        cnt++;
    }

    for (int i = 0; i < cnt * 2 - 1; i++) {
        if (i & 1) {
            grid[x][y + i] = '-';
            grid[x + 1][y + i] = ' ';
            grid[x + 2][y + i] = '-';
        }
        else {
            grid[x][y + i] = '+';
            grid[x + 1][y + i] = char('a' + lst[i / 2]);
            grid[x + 2][y + i] = '+';
        }
    }

    /*cout << "RES: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < cnt * 2 - 1; j++) {
            cout << grid[i + x][y + j];
        }
        cout << '\n';
    }*/
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(grid, ' ', sizeof(grid));
    getline(cin, F);


    for (int i = 0; i < (1 << 8); i++) {
        chk[i] = check(i);
        /*if (chk[i]) {
            cout << "valid mem: ";
            for (int j = 0; j < 8; j++) if (i & (1 << j)) cout << char('a' + j) << ' ';
            cout << '\n';
        }*/
    }
    bool ok = 1;
    vector<pair<int, int>> lst;
    for (int i = 0; i < (1 << 8); i++) {

        bool valid = chk[i];
        for (int j = 0; j < (1 << 8); j++) {
            if (i == j) continue;
            if ((j & i) == j) {
                if (chk[j] && !chk[i]) ok = 0;
                if (chk[j] && chk[i]) valid = 0;
            }
        }

        int cnt = 0;
        for (int j = 0; j < 8; j++) if (i & (1 << j)) cnt++;

        if (valid) lst.push_back({ cnt, i });
    }

    if (!ok) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    if (lst.empty()) {
        cout << "+-+";
        return 0;
    }

    if (lst[0].second == 0) {
        cout << "+ +";
        return 0;
    }
    sort(lst.rbegin(), lst.rend());

    int x = 0, y = 0, mcnt = 0;
    bool down = 1;
    for (int i = 0; i < lst.size(); i++) {

        mcnt = max(mcnt, lst[i].first);
        int m = lst[i].second;
        if (down) {
            fill(x, y, m);
            x += 2;
            if (x == 48) {
                // move right

                for (int j = 0; j < mcnt * 2; j++) {
                    if (grid[x][y + j + 1] == ' ') grid[x][y + j + 1] = '-';
                }
                grid[x][y + mcnt * 2] = '+';

                y += mcnt * 2;
                mcnt = 0;
                down = 0;
            }
        }
        else {
            fill(x - 2, y, m);
            x -= 2;

            if (x == 0) {

                for (int j = 0; j < mcnt * 2; j++) {
                    if (grid[x][y + j + 1] == ' ') grid[x][y + j + 1] = '-';
                }
                grid[x][y + mcnt * 2] = '+';

                y += mcnt * 2;
                down = 1;
                mcnt = 0;
            }
        }
    }

    while (y < 49) {
        if (grid[x][y] == ' ') grid[x][y] = '-';
        y++;
    }
    grid[x][y] = '+';
    while (x >= 0) {
        if (grid[x][y] == ' ') grid[x][y] = '|';
        x--;
    }
    grid[0][49] = '+';

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if (grid[i][j] != '+') continue;

            bool col = 0, row = 0;
            if (i > 0 && grid[i - 1][j] != ' ') col = 1;
            if (i + 1 < 50 && grid[i + 1][j] != ' ') col = 1;
            if (j > 0 && grid[i][j - 1] != ' ') row = 1;
            if (j + 1 < 50 && grid[i][j + 1] != ' ') row = 1;

            if (row && !col) grid[i][j] = '-';
            else if (!row && col) grid[i][j] = '|';

        }
    }
    grid[0][0] = grid[0][49] = '+';

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
string operator+(string& a, string& b) {
    // 덧셈

    if (a == "0") return b;
    if (b == "0") return a;
    string res;
    int ix = 0, pv = 0;
    while (ix < a.size() || ix < b.size()) {
        int val1, val2;
        if (ix < a.size()) val1 = int(a[ix] - '0');
        else val1 = 0;
        if (ix < b.size()) val2 = int(b[ix] - '0');
        else val2 = 0;

        int nv = pv + val1 + val2;
        if (nv > 9) {
            pv = 1;
            nv -= 10;
        }
        else pv = 0;

        res += char('0' + nv);
        ix++;
    }
    if (pv == 1) res += '1';
    return res;
}

string t5(string a) {
    reverse(a.begin(), a.end());
    return a;
}
bool operator<=(string& a, string& b) {
    if (a == b) return 1;
    if (a.size() > b.size()) return 0;
    if (a.size() < b.size()) return 1;

    int ix = a.size() - 1;
    while (ix >= 0) {
        if (int(a[ix]-'0') < int(b[ix]-'0')) return 1;
        if (int(a[ix]-'0') > int(b[ix]-'0')) return 0;
        ix--;
    }
    return 1;
}

bool operator>=(string& a, string& b) {
    return b <= a;
}
string s2[101];

struct Area {
    int c;

    string xl, xr, yl, yr;
    void pf() {
        cout << t5(xl) << ' ' << t5(xr) << ' ' << t5(yl) << ' ' << t5(yr) << '\n';
    }
};

vector<Area> A;
bool f1 = 0;
void getArea(string xl, string yl, int dx, int dy) {

    string s;
    cin >> s;

    if (s[0] == 'v' || s == "-1") {
        string md = xl + s2[dx];
        getArea(xl, yl, dx-1, dy);
        getArea(md, yl, dx-1, dy);
    }
    else if (s[0] == 'h' || s == "-2") {
        string md = yl + s2[dy];
        getArea(xl, md, dx, dy-1);
        getArea(xl, yl, dx, dy-1);
    }
    else {
        int v = stoi(s);
        Area tmp = { v, xl, xl+s2[dx+1], yl, yl+s2[dy+1] };
        A.push_back(tmp);
    }
}

bool isConn(Area a, Area b) {

    bool checkR = (a.yl <= b.yr) && (a.yr >= b.yl);
    bool checkC = (a.xl <= b.xr) && (a.xr >= b.xl);

    if (!checkR || !checkC) return 0;

    if (a.xl == b.xr || a.xr == b.xl) {
        if (a.yl == b.yr || a.yr == b.yl) return 0;
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    s2[0] = "1";
    for (int i = 1; i <= 100; i++) {
        s2[i] = s2[i - 1] + s2[i - 1];
    }
    
    getArea("0", "0", 99, 99);
    int n = A.size();

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {
            if (isConn(A[i], A[j]) && A[i].c == A[j].c) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int ans = 1;
    vector<bool> vs(n);
    for (int i = 0; i < n; i++) {
        if (vs[i]) continue;
        vs[i] = 1;
        int cnt = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {

            int a = q.front();
            q.pop();
            cnt++;

            for (auto j : adj[a]) if (!vs[j]) {
                vs[j] = 1;
                q.push(j);
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
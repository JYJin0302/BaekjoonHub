#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 2011;

bool debug = 0;

ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

struct N {
    int v;
    N(int x = 0) {
        v = x % mod;
        while (v < 0) v += mod;
    }

    N operator+(N& o) {
        return N(o.v + v);
    }
    N operator-(N & o) {
        return N(v - o.v);
    }
    N operator*(N o) {
        return N(v * o.v % mod);
    }
    N operator/(N& o) {
        return N(v * fastPow(o.v, mod - 2, mod) % mod);
    }
    N pw(int x) {
        return N(fastPow(v, x, mod));
    }

};

int n, m;
char G[22][88];
int sG[22][88];

void pf(int x1, int  y1, int x2, int y2) {
    cout << string(m, '*') << '\n';
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            cout << G[i][j];
        }
        cout << '\n';
    }
    cout << string(m, '*') << '\n'; 
}

N parseExpr(int x1, int y1, int x2, int y2);
N parseTerm(int x1, int y1, int x2, int y2);
N parsePrimary(int x1, int y1, int x2, int y2);
N parseFraction(int x1, int y1, int x2, int y2);
N parsePowexpr(int x1, int y1, int x2, int y2);
N parseFactor(int x1, int y1, int x2, int y2);
N parseDigit(int x1, int y1, int x2, int y2);

// pair<int, int> : num / den

int getS(int x1, int y1, int x2, int y2) {
    return sG[x2][y2] - sG[x2][y1 - 1] - sG[x1 - 1][y2] + sG[x1 - 1][y1 - 1];
}

void rmvIndent(int& x1, int& y1, int& x2, int& y2) {
    while (x1 < x2 && getS(x1, y1, x1, y2) == 0) x1++;
    while (x1 < x2 && getS(x2, y1, x2, y2) == 0) x2--;

    while (y1 < y2 && getS(x1, y1, x2, y1) == 0) y1++;
    while (y1 < y2 && getS(x1, y2, x2, y2) == 0) y2--;
}

N parseExpr(int x1, int y1, int x2, int y2) {
    
    rmvIndent(x1, y1, x2, y2);
    if (debug) {
        cout << "Go expr: " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        pf(x1, y1, x2, y2);
    }

    int base = 0;
    for (int i = x1; i <= x2; i++) {
        if (G[i][y1] != '.') {
            base = i;
            break;
        }
    }

    int ph = 0;
    for (int i = y1; i <= y2; i++) {
        if (G[base][i] == '+' && ph == 0) {
            N p1 = parseTerm(x1, y1, x2, i - 2);
            N p2 = parseExpr(x1, i + 2, x2, y2);
            return p1 + p2;
        }
        if (i != y1 && G[base][i] == '-' && ph == 0) {
            // check validity
            if (G[base][i - 1] != '.' || G[base][i + 1] != '.') continue;
            char c = G[base][i - 2];
            if (c == ')' || isdigit(c) || c == '.' ||(c == '-' && i-3 >= 1 && G[base][i-3] == '-')) {
                // ok
                N p1 = parseTerm(x1, y1, x2, i - 2);
                N p2 = parseExpr(x1, i, x2, y2);
                return p1 + p2;
            }
        }
            
        if (G[base][i] == '(') ph++;
        else if (G[base][i] == ')') ph--;
    }
    return parseTerm(x1, y1, x2, y2);

}

N parseTerm(int x1, int y1, int x2, int y2) {
    rmvIndent(x1, y1, x2, y2);
    if (debug) {
        cout << "Go term: " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        pf(x1, y1, x2, y2);
    }

    int base = 0;
    for (int i = x1; i <= x2; i++) {
        if (G[i][y1] != '.') {
            base = i;
            break;
        }
    }

    int ph = 0;
    for (int i = y1; i <= y2; i++) {
        if (G[base][i] == '*' && ph == 0) {
            N t1 = parseFactor(x1, y1, x2, i - 2);
            N t2 = parseTerm(x1, i + 2, x2, y2);
            return t1 * t2;
        }
        
        if (G[base][i] == '(') ph++;
        else if (G[base][i] == ')') ph--;
    }
    return parseFactor(x1, y1, x2, y2);
}

N parseFactor(int x1, int y1, int x2, int y2) {
    rmvIndent(x1, y1, x2, y2);
    if (debug) {
        cout << "Go factor: " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        pf(x1, y1, x2, y2);
    }

    for (int i = x1; i <= x2; i++) {
        if (G[i][y1] == '.') continue;

        if (G[i][y1] == '-') {
            // fraction or -
            if (G[i][y1 + 1] == '-') {
                // fraction
                return parseFraction(x1, y1, x2, y2);
            }
            else {
                return parseFactor(x1, y1 + 2, x2, y2) * N(-1);
            }
        }
        else {
            return parsePowexpr(x1, y1, x2, y2);
        }
    }

    assert(0);
    return N(0);
}

N parsePowexpr(int x1, int y1, int x2, int y2) {
    rmvIndent(x1, y1, x2, y2);
    if (debug) {
        cout << "Go powexpr: " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        pf(x1, y1, x2, y2);
    }

    N base;
    int pw = 1;
    for (int i = x1; i <= x2; i++) {
        if (G[i][y1] == '(' || isdigit(G[i][y1])) {
            if (G[i][y2] == '.') {
                // pw exist
                pw = G[i - 1][y2] - '0';
                y2--;
            }
            base = parsePrimary(x1, y1, x2, y2);
            break;
        }
    }
    return base.pw(pw);
}

N parsePrimary(int x1, int y1, int x2, int y2) {
    rmvIndent(x1, y1, x2, y2);
    if (debug) {
        cout << "Go primary: " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        pf(x1, y1, x2, y2);
    }

    for (int i = x1; i <= x2; i++) {
        if (G[i][y1] == '(') {
            return parseExpr(x1, y1 + 2, x2, y2 - 2);
        }
    }
    return parseDigit(x1, y1, x2, y2);
}

N parseFraction(int x1, int y1, int x2, int y2) {
    rmvIndent(x1, y1, x2, y2); 
    if (debug) {
        cout << "Go fraction: " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        pf(x1, y1, x2, y2);
    }
    int line = 0;
    for (int i = x1; i <= x2; i++) {
        if (G[i][y1] == '-') {
            line = i;
            break;
        }
    }
    N num = parseExpr(x1, y1, line - 1, y2);
    N den = parseExpr(line + 1, y1, x2, y2);
    return num / den;
}

N parseDigit(int x1, int y1, int x2, int y2) {
    rmvIndent(x1, y1, x2, y2);
    if (debug) {
        cout << "Go digit: " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        pf(x1, y1, x2, y2);
    }
    assert(x1 == x2 && y1 == y2);
    return N(G[x1][y1] - '0');
}

void solve() {

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        m = s.size();

        for (int j = 1; j <= m; j++) G[i][j] = s[j-1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (G[i][j] == '.') sG[i][j] = 0;
            else sG[i][j] = 1;

            sG[i][j] += sG[i - 1][j] + sG[i][j - 1] - sG[i - 1][j - 1];
        }
    }


    N res = parseExpr(1, 1, n, m);
    cout << res.v << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    while (n) {
        solve();
        cin >> n;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1 << 15;

int n;
struct Mat {
    int r, c;
    vector<vector<int>> mat;
    Mat() {
        r = c = 0;
    }

    Mat(int x) {
        r = c = 1;
        x %= mod;
        while (x < 0) x += mod;
        mat.push_back(vector<int>(1, x));
    }

    bool isScalar() {
        return r == 1 && c == 1;
    }

    Mat operator+(Mat& o) {
        assert(r == o.r && c == o.c);
        Mat ret;
        ret.r = r, ret.c = c;
        ret.mat = vector<vector<int>>(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ret.mat[i][j] = (mat[i][j] + o.mat[i][j]) % mod;
            }
        }
        return ret;
    }

    Mat operator-(Mat& o) {
        assert(r == o.r && c == o.c);
        Mat ret;
        ret.r = r, ret.c = c;
        ret.mat = vector<vector<int>>(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ret.mat[i][j] = (mod + mat[i][j] - o.mat[i][j]) % mod;
            }
        }
        return ret;
    }

    Mat operator*(Mat& o) {
        Mat ret;
        if ((*this).isScalar()) {
            ret = o;
            for (int i = 0; i < o.r; i++) {
                for (int j = 0; j < o.c; j++) {
                    ret.mat[i][j] = ret.mat[i][j] * mat[0][0] % mod;
                }
            }
            return ret;
        }

        if (o.isScalar()) {
            ret = *this;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    ret.mat[i][j] = ret.mat[i][j] * o.mat[0][0] % mod;
                }
            }
            return ret;
        }

        assert(c == o.r);
        ret.r = r; ret.c = o.c;
        ret.mat = vector<vector<int>>(r, vector<int>(o.c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < o.c; j++) {
                for (int k = 0; k < c; k++) {
                    (ret.mat[i][j] += mat[i][k] * o.mat[k][j] % mod) %= mod;
                }
            }
        }
        return ret;
    }
        
    void pf() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }

};

Mat var[26];

bool debug = 0;
string s;

Mat parseExpr(int l, int r);
Mat parseTerm(int l, int r);
Mat parseFactor(int l, int r);
Mat parsePrimary(int l, int r);
Mat parseIndexedPrimary(int l, int md, int r);
Mat parseTransposedPrimary(int l, int r);
Mat parseMatrix(int l, int r);
Mat parseRowseq(int l, int r);
Mat parseRow(int l, int r);
Mat parseInum(int l, int r);

Mat parseExpr(int l, int r) {

    if (debug) {
        cout << "Go expr: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }

    int ph = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(' || s[i] == '[') ph++;
        else if (s[i] == ')' || s[i] == ']') ph--;

        if (ph != 0) continue;
        if (s[i] == '+') {
            Mat m1 = parseTerm(l, i - 1);
            Mat m2 = parseExpr(i + 1, r);
            return m1 + m2;
        }
        else if (i != l && s[i] == '-') {
            char c = s[i - 1];
            if (c == '(' || c == '[' || c == '-' || c == ' ' || c == ';' || c == '*' || c == '+') continue;
            Mat m1 = parseTerm(l, i - 1);
            Mat m2 = parseExpr(i, r);
            return m1 + m2;
        }
    }
    return parseTerm(l, r);
}
Mat parseTerm(int l, int r) {
    if (debug) {
        cout << "Go term: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }
    int ph = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(' || s[i] == '[') ph++;
        else if (s[i] == ')' || s[i] == ']') ph--;

        if (ph != 0 || s[i] != '*') continue;
        Mat m1 = parseFactor(l, i - 1);
        Mat m2 = parseTerm(i + 1, r);
        return m1 * m2;
    }
    return parseFactor(l, r);
}
Mat parseFactor(int l, int r) {
    if (debug) {
        cout << "Go factor: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }
    if (s[l] == '-') {
        Mat ret = parseFactor(l + 1, r);
        Mat t(-1);
        return ret * t;
    }
    return parsePrimary(l, r);
}

Mat parsePrimary(int l, int r) {
    if (debug) {
        cout << "Go primary: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }
    if (s[r] == '\'') {
        return parseTransposedPrimary(l, r);
    }

    if (s[r] == ')') {
        int ph = 0;
        for (int i = r; i >= l; i--) {
            if (s[i] == ')' || s[i] == ']') ph++;
            if (s[i] == '(' || s[i] == '[') ph--;
            if (ph == 0) {
                if (i == l) return parseExpr(l + 1, r - 1);
                return parseIndexedPrimary(l, i, r);
            }
        }
        
        assert(0);
        return Mat();
    }

    if (s[l] == '[') {
        return parseMatrix(l, r);
    }
    if (isalpha(s[l])) {
        int ix = s[l] - 'A';
        return var[ix];
    }
    if (isdigit(s[l])) {
        return parseInum(l, r);
    }

    assert(0);
    return Mat();
}
Mat parseIndexedPrimary(int l, int md, int r) {
    if (debug) {
        cout << "Go indexprimary: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }
    int ph = 0;
    int mid = -1;
    for (int i = r; i >= l; i--) {
        if (s[i] == ')' || s[i] == ']') ph++;
        else if (s[i] == '(' || s[i] == '[') ph--;

        if (ph == 1 && s[i] == ',') {
            mid = i;
            break;
        }
    }

    assert(mid != -1);
    Mat m = parsePrimary(l, md - 1);

    Mat i1 = parseExpr(md + 1, mid - 1);
    Mat i2 = parseExpr(mid + 1, r - 1);

    Mat ret;
    ret.r = i1.c;
    ret.c = i2.c;
    ret.mat = vector<vector<int>>(ret.r, vector<int>(ret.c));
    for (int i = 0; i < ret.r; i++) {
        for (int j = 0; j < ret.c; j++) {
            ret.mat[i][j] = m.mat[i1.mat[0][i] - 1][i2.mat[0][j] - 1];
        }
    }
    return ret;
}
Mat parseTransposedPrimary(int l, int r) {
    if (debug) {
        cout << "Go transpose: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }

    int cnt = 0;
    while (s[r] == '\'') {
        cnt ^= 1;
        r--;
    }
    Mat m = parsePrimary(l, r);
    // transpose
    if (cnt == 0) return m;
    vector<vector<int>> tmp(m.c, vector<int>(m.r));
    for (int i = 0; i < m.r; i++) {
        for (int j = 0; j < m.c; j++) {
            tmp[j][i] = m.mat[i][j];
        }
    }
    m.mat = tmp;
    swap(m.c, m.r);
    return m;
}

Mat parseMatrix(int l, int r) {
    if (debug) {
        cout << "Go matrix: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }
    return parseRowseq(l + 1, r - 1);
}

Mat parseRowseq(int l, int r) {
    if (debug) {
        cout << "Go rowseq: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }
    int ph = 0;
    int pre = l;

    vector<Mat> tmp;

    for (int i = l; i <= r; i++) {
        if (s[i] == '(' || s[i] == '[') ph++;
        if (s[i] == ')' || s[i] == ']') ph--;

        if (ph != 0) continue;
        if (s[i] == ';') {
            Mat m = parseRow(pre, i - 1);
            tmp.push_back(m);
            pre = i + 1;
        }
    }
    tmp.push_back(parseRow(pre, r));

    

    for (int i = 1; i < tmp.size(); i++) {
        for (int a = 0; a < tmp[i].r; a++) {
            tmp[0].mat.push_back(tmp[i].mat[a]);
        }
    }

    tmp[0].r = tmp[0].mat.size();

    if (debug) {
        cout << "Done rowseq: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
        tmp[0].pf();
        
    }
    return tmp[0];
}

Mat parseRow(int l, int r) {
    if (debug) {
        cout << "Go row: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }
    int ph = 0;
    int pre = l;
    vector<Mat> tmp;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(' || s[i] == '[') ph++;
        if (s[i] == ')' || s[i] == ']') ph--;
        if (ph != 0) continue;

        if (s[i] == ' ') {
            tmp.push_back(parseExpr(pre, i - 1));
            pre = i + 1;
        }
    }
    tmp.push_back(parseExpr(pre, r));

    for (int i = 1; i < tmp.size(); i++) {
        for (int a = 0; a < tmp[i].r; a++) {
            for (int b = 0; b < tmp[i].c; b++) {
                tmp[0].mat[a].push_back(tmp[i].mat[a][b]);
            }
        }
    }

    tmp[0].c = tmp[0].mat[0].size();

    if (debug) {
        cout << "Done row: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
        tmp[0].pf();

    }
    return tmp[0];
}

Mat parseInum(int l, int r) {
    if (debug) {
        cout << "Go inum: ";
        for (int i = l; i <= r; i++) cout << s[i];
        cout << '\n';
    }
    int val = 0;
    for (int i = l; i <= r; i++) {
        val = val * 10 + s[i] - '0';
        val %= mod;
    }
    return Mat(val);
}


void solve() {

    cin.ignore();
    for (int i = 0; i < 26; i++) var[i] = Mat();

    for (int i = 0; i < n; i++) {
        getline(cin, s);

        int ix = s[0] - 'A';
        s = s.substr(2, s.size());
        s.pop_back();

        //cout << s << '\n';

        var[ix] = parseExpr(0, s.size() - 1);

        //cout << "RES: \n";
        for (int a = 0; a < var[ix].r; a++) {
            for (int b = 0; b < var[ix].c; b++) {
                cout << var[ix].mat[a][b] << ' ';
            }
            cout << '\n';
        }
    }

    cout << string(5, '-') << '\n';
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
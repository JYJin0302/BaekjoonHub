#include <bits/stdc++.h>
using namespace std;

int n, q;
struct P {
    int x, y;
};
P p1, p2, p3, p4;
vector<int> sw;

// r : 0 1 2 3, c : 0 1 2 3 * n
void pf() {

    vector<vector<int>> res(n, vector<int>(n));

    res[0][0] = p1.x*n + p1.y;
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            res[i*2][j*2] = n * ((p1.x + i*2) % n) + (p1.y + j*2) % n;
        }
    }
    res[0][1] = p2.x * n + p2.y;
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            res[i*2][1+2*j] = n * ((p2.x + i*2) % n) + (p2.y + j*2) % n;
        }
    }
    res[1][0] = p3.x * n + p3.y;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            res[1 + i * 2][2 * j] = n * ((p3.x + i * 2) % n) + (p3.y + j * 2) % n;
        }
    }
    res[1][1] = p4.x * n + p4.y;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            res[1 + i * 2][1 + 2 * j] = n * ((p4.x + i * 2) % n) + (p4.y + j * 2) % n;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sw[res[i][j]]+1 << ' ';
        }
        cout << '\n';
    }

}

int getNum(int i, int j) {

    i--, j--;

    if (i % 2 == 0) {
        if(j % 2 == 0) {

            int dx = i;
            int dy = j;

            int res = ((p1.x + dx) % n) * n + (p1.y + dy) % n;
            return res;
        }
        else {
            int dx = i;
            int dy = j - 1;
            int res = ((p2.x + dx) % n) * n + (p2.y + dy) % n;
            return res;
        }
    }
    else {
        if (j % 2 == 0) {
            int dx = i - 1;
            int dy = j;

            int res = ((p3.x + dx) % n) * n + (p3.y + dy) % n;
            return res;
        }
        else {
            int dx = i - 1;
            int dy = j - 1;

            int res = ((p4.x + dx) % n) * n + (p4.y + dy) % n;
            return res;
        }
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    p1 = { 0, 0 };
    p2 = { 0, 1 };
    p3 = { 1, 0 };
    p4 = { 1, 1 };
    // 1 2
    // 3 4

    cin >> n >> q;
    sw = vector<int> (n * n);
    for (int i = 0; i < n * n; i++) sw[i] = i;

    while (q--) {

        string s;
        cin >> s;
        if (s == "S") {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            // swap

            int a = getNum(x1, y1);
            int b = getNum(x2, y2);
            //cout << "test: " << a << ' ' << sw[a] << ' ' << b << ' ' << sw[b] << '\n';
            swap(sw[a], sw[b]);
        }
        else {

            if (s == "RO") {
                P tmp = { p2.x ,(p2.y + n - 2) % n };
                p2 = p1;
                p1 = tmp;
            }
            else if (s == "RE") {
                P tmp = { p4.x, (p4.y + n - 2) % n };
                p4 = p3;
                p3 = tmp;
            }
            else if (s == "CO") {
                P tmp = { (p3.x + n - 2) % n,p3.y };
                p3 = p1;
                p1 = tmp;
            }
            else {
                P tmp = { (p4.x + n - 2) % n, p4.y };
                p4 = p2;
                p2 = tmp;
            }

        }

    }

    pf();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second



struct Node {
    char val = '?';
    int nxt = -1;
    int pre = -1;
};

Node lst[1001010];
int s1 = 0, s2 = 0;
int r1 = 0, r2 = 0;
void solve() {
    int n, r, q;
    cin >> n >> r >> q;

    string ts1, ts2;
    cin >> ts1 >> ts2;
    for (int i = 0; i < n; i++) {
        lst[i].val = ts1[i];
        lst[i].nxt = (i + 1) % n;
        lst[i].pre = (i - 1 + n) % n;;
        lst[i + n].val = ts2[i];
        lst[i + n].nxt = (i + 1) % n + n;
        lst[i + n].pre = (i - 1 + n) % n + n;
    }

    s1 = 0, s2 = n;
    r1 = r - 1, r2 = n + r - 1;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'S') {
            // s1 - r1 | s2 - r2
            int t1 = lst[s1].pre, t2 = lst[s2].pre;
            swap(lst[t1].nxt, lst[t2].nxt);
            swap(lst[s1].pre, lst[s2].pre);
            swap(s1, s2);
            int n1 = lst[r1].nxt, n2 = lst[r2].nxt;
            swap(lst[r1].nxt, lst[r2].nxt);
            swap(lst[n1].pre, lst[n2].pre);
            swap(r1, r2);
        }
        else if (c == 'L') {
            int x;
            cin >> x;

            if (x == 1) {
                s1 = lst[s1].nxt;
                r1 = lst[r1].nxt;
            }
            else {
                s2 = lst[s2].nxt;
                r2 = lst[r2].nxt;
            }
        }
        else if (c == 'R') {
            int x;
            cin >> x;
            if (x == 1) {
                s1 = lst[s1].pre;
                r1 = lst[r1].pre;
            }
            else {
                s2 = lst[s2].pre;
                r2 = lst[r2].pre;
            }
        }
        else if (c == 'I') {
            r1 = lst[r1].nxt;
            r2 = lst[r2].nxt;
        }
        else if (c == 'D') {
            r1 = lst[r1].pre;
            r2 = lst[r2].pre;
        }
        else {
            exit(1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << lst[s1].val;
        s1 = lst[s1].nxt;
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << lst[s2].val;
        s2 = lst[s2].nxt;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
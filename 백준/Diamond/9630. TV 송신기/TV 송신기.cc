#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll n, D;
struct B {
    bool on;
    ll x, y;

    bool operator<(const B& o) {
        return x < o.x;
    }
};

ll ccw(B& a, B& b, B& c) {
    ll res = a.x * b.y + b.x * c.y + c.x * a.y;
    res -= a.y * b.x + b.y * c.x + c.y * a.x;
    return res;
}

stack<int> stk;
vector<B> A;

ld getXpos(int x1, int x2) {
    if (A[x1].y <= A[x2].y) return D + 100;
    ld res = A[x1].x + 1.0 * A[x1].y * (A[x2].x - A[x1].x) / (A[x1].y - A[x2].y);
    return res;
}

void pf(stack<int> st) {

    vector<int> tmp;
    while (!st.empty()) {
        tmp.push_back(st.top()); st.pop();
    }
    reverse(all(tmp));
    for (auto f : tmp) cout << f << ' ';
    cout << '\n';

    reverse(all(tmp));
    for (auto f : tmp) st.push(f);
}

vector<pair<ld, ld>> light, light2;

int find(int v, vector<int>& root) {
    if (v < 0 || v >= n) return v;
    if (root[v] == v) return v;
    return root[v] = find(root[v], root);
}

void solve() {

    cin >> n >> D;

    A = vector<B> (n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].on >> A[i].x >> A[i].y;
    }
    sort(all(A));

    if (A[n - 1].x != D) A.push_back(B(0, D, 1e9 + 10));
    if (A[0].x != 0) A.push_back(B(0, 0, 1e9 + 10));
    n = A.size();


    auto F = []() {

        vector<pair<int, int>> connRec;
        connRec.push_back(mp(-1, -1));
        vector<int> connBox(n, -1);
        for (int i = 0; i < n; i++) {

            //cout << "State: "  << i << " | " << A[i].on << ' ' << A[i].x << ' ' << A[i].y << " " << string(10, '-') << '\n';
            //cout << "Stk: "; pf(stk);
            //cout << "Conn rec: "; for (auto [a, b] : connRec) cout << "(" << a << ' ' << b << ") ";
            //cout << '\n' << '\n';
            //
            if (A[i].on) {

                while (connRec.back().x != -1) {
                    auto [a, b] = connRec.back();
                    if (ccw(A[a], A[b], A[i]) >= 0) {
                        connRec.pop_back();
                        connBox[a] = -1;

                        while (!stk.empty() && stk.top() != a) stk.pop();
                    }
                    else break;
                }

                while (!stk.empty()) {

                    int b1 = stk.top(); stk.pop();
                    if (A[b1].y <= A[i].y) {
                        if (connRec.back().x == b1) {
                            connRec.pop_back();
                            connBox[b1] = -1;
                        }
                        continue;
                    }

                    if (connBox[b1] != -1) {
                        stk.push(b1);
                        break;
                    }
                    else {
                        if (!stk.empty() && connBox[stk.top()] == -1) {
                            int b2 = stk.top();
                            if (ccw(A[b2], A[b1], A[i]) >= 0) {}
                            else {
                                stk.push(b1);
                                break;
                            }
                        }
                        else {
                            stk.push(b1);
                            break;
                        }
                    }
                }

                stk.push(i);
            }
            else {

                while (connRec.back().x != -1) {
                    auto [a, b] = connRec.back();
                    if (ccw(A[a], A[b], A[i]) >= 0) {
                        ld xpos = getXpos(a, b);
                        if (xpos <= A[i].x) {
                           // cout << "light found: " << A[a].x << ' ' << A[b].x << " | " << xpos << ' ' << A[i].x << '\n';
                            light.push_back(mp(xpos, A[i].x));
                        }

                        connRec.pop_back();
                        connBox[a] = -1;
                        while (!stk.empty() && stk.top() != a) stk.pop();
                    }
                    else break;
                }

                if (stk.empty()) continue;
               // cout << "test: "; pf(stk);

                int b1 = -1;

                while (!stk.empty()) {
                    int b2 = stk.top(); stk.pop();
                    if (A[b2].y <= A[i].y) {
                        continue;
                    }
                    if (b1 == -1) {
                        if (connBox[b2] != -1) {
                            stk.push(b2);
                            break;
                        }
                        b1 = b2;
                        connBox[b1] = i;
                        continue;
                    }

                    if (connBox[b2] == -1) {
                        if (ccw(A[b2], A[b1], A[i]) >= 0) {
                            connBox[b1] = -1;
                            b1 = b2;
                            connBox[b1] = i;
                        }
                        else {
                            stk.push(b2);
                            break;
                        }
                    }
                    else {
                        stk.push(b2);
                        break;
                    }
                }

                if (b1 != -1) {
                    if (connRec.back().x != -1) {
                        ld xpos = getXpos(b1, i);
                        auto [a, b] = connRec.back();
                        ld xpos2 = getXpos(a, b);
                        if (xpos >= xpos2) {
                            continue;
                        }
                    }
                    connRec.push_back(mp(b1, i));
                    stk.push(b1);
                }

            }

        }

        while (!stk.empty()) stk.pop();
    };

    sort(all(A));

    for (int i = 0; i < n; i++) {
        if (!A[i].on) continue;
        ll tl = A[i].x, tr = A[i].x;
        if (i) tl = A[i - 1].x;
        if (i + 1 < n) tr = A[i + 1].x;
        light.push_back(mp(tl, tr));
    }
        
   // cout << "Phase1\n";
    F();
    for (auto& i : A) i.x = D - i.x;

    sort(all(A));
    //cout << "Phase2\n";
    swap(light, light2);
    F();
    swap(light, light2);
    for (auto& [a, b] : light2) {
        light.push_back(mp(D - b, D - a));
    }

    sort(all(light));
    ld tl = 0, tr = 0, tot = 0;
    for (auto [a, b] : light) {
        //cout << a << ' ' << b << '\n';
        if (a <= tr) tr = max(tr, b);
        else {
            tot += tr - tl;
            tl = a, tr = b;
        }
    }
    tot += tr - tl;

    cout << fixed << setprecision(10);
    cout << tot << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
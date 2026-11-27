#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b){
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b% a, a);
}

map<pair<ll, ll>, bool> invalid;
// {(-)a, b} = a/b

struct F { // 일차식 표현
    ll x1, x0;
    // x1 * x + x0
    F() : x1(0), x0(1) {}
    F(ll _x1, ll _x0) : x1(_x1), x0(_x0) {}

    F operator+(const F& o) {
        return F(x1 + o.x1, x0 + o.x0);
    }
    F operator*(const F& o) {
        if (x1 == 0) return F(o.x1 * x0, o.x0 * x0);
        assert(o.x1 == 0);
        return F(x1 * o.x0, x0 * o.x0);
    }
    F operator-(const F& o) {
        return F(x1 - o.x1, x0 - o.x0);
    }
    pair<F, F> operator/(const F& o) {
        ll gc = gcd(abs(x1), abs(x0));
        gc = gcd(gc, gcd(abs(o.x1), abs(o.x0)));
        return mp(F(x1 / gc, x0 / gc), F(o.x1 / gc, o.x0 / gc));
    }

};


void solve() {

    string s;
    getline(cin, s);
    cin.ignore();

    vector<char> inp;
    for (int i = 0; i < s.size(); i += 2) inp.push_back(s[i]);

    stack<pair<F, F>> st;
    // {a, b} = a / b

    for (auto f : inp) {
        if (f >= '0' && f <= '9') {
            int val = f - '0';
            st.push(mp(F(0, val), F(0, 1)));
        }
        else if (f == 'X') {
            st.push(mp(F(1, 0), F(0, 1)));
        }
        else {
            F den, num;
            pair<F, F> p1, p2;
            p2 = st.top(); st.pop();
            p1 = st.top(); st.pop();
            switch (f) {
            case '+':
                den = p1.second * p2.second;
                num = F(p1.first * p2.second) + F(p1.second * p2.first);
                st.push(num / den);
                break;
            case '-':
                den = p1.second * p2.second;
                num = F(p1.first * p2.second) - F(p1.second * p2.first);
                st.push(num / den);
                break;
            case '*':
                den = p1.second * p2.second;
                num = p1.first * p2.first;
                st.push(num / den);
                break;
            case '/':
                den = p1.second * p2.first;
                num = p1.first * p2.second;
                st.push(num / den);

                // divide by zero check
                if (den.x1 != 0) {
                    ll v1 = den.x1, v2 = -den.x0;
                    if (v1 < 0) v1 *= -1, v2 *= -1;
                    if (v2 == 0) v1 = 1;
                    invalid[mp(v2, v1)] = 1;
                    //cout << "invalid: " << v2 << ' ' << v1 << '\n';
                }
                break;
            }
        }

        //F f1 = st.top().first;
        //F f2 = st.top().second;
        //cout << "TOP : " << st.size() << " | ";
        //cout << f1.x1 << ' ' << f1.x0 << " \ " << f2.x1 << ' ' << f2.x0 << '\n';
    }

    F f1 = st.top().first;
    F f2 = st.top().second;
    if (f1.x1 == 0) {
        if (f1.x0 == 0) cout << "MULTIPLE\n";
        else cout << "NONE\n";
    }
    else {
        ll v1, v2;
        v1 = f1.x1, v2 = -f1.x0;
        if (v1 < 0) v1 *= -1, v2 *= -1;
        if (v2 == 0) v1 = 1;

        ll g = gcd(abs(v1), abs(v2));
        v1 /= g, v2 /= g;
        if (invalid[mp(v2, v1)]) cout << "NONE\n";
        else cout << "X = " << v2 << '/' << v1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
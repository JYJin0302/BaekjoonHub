#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


bool isValid(string exp) {

    exp += '=';
    // token check
    ll valL = 0, valR = 0;

    string token;
    char oper = '+';
    for (auto f : exp) {
        if (isdigit(f)) {
            token += f;
        }
        else{
            if (token.empty()) return 0;

            if (token.size() > 10) return 0;
            if (token.size() > 1 && token[0] == '0') return 0;

            if (oper == '+') valL += stoll(token);
            else valL -= stoll(token);
            token.clear();

            if (f == '=') {
                swap(valL, valR);
                oper = '+';
            }
            else oper = f;
        }
    }

    //cout << valL << ' ' << valR << '\n';

    return valL == valR;
}

void solve() {

    string s;
    cin >> s;

    if (isValid(s)) {
        cout << "Correct\n";
        return;
    }

    int n = s.size();
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (!isdigit(c)) continue;
        string tmp = s.substr(0, i) + s.substr(i + 1, n);

        for (int j = 0; j < n; j++) {
            string exp = tmp.substr(0, j) + c + tmp.substr(j, n);
           // cout << exp << '\n';
            if (isValid(exp)) {
                cout << exp << '\n';
                return;
            }
        }
    }
    cout << "Impossible\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
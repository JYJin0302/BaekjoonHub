#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int state[26];
map<char, int> ord;

bool cal(bool v1, char oper, bool v2) {
    if (oper == '&') return (v1 & v2);
    if (oper == '|') return (v1 | v2);
    return v1 ^ v2;
}

bool getVal(string exp) {

    stack<char> oper;
    stack<bool> val;

    for (auto f : exp) {

        if (isalpha(f)) {
            val.push(state[f - 'a']);
        }
        else if (f == '(') {
            oper.push('(');
        }
        else if (f == ')') {

            while (oper.top() != '(') {
                char op = oper.top(); oper.pop();
                bool v2 = val.top(); val.pop();
                if (op == '~') val.push(v2 ^ 1);
                else {
                    bool v1 = val.top(); val.pop();
                    val.push(cal(v1, op, v2));
                }
            }
            oper.pop();

        }
        else {
            while (!oper.empty() && oper.top() != '(' && ord[oper.top()] < ord[f]) {
                char op = oper.top(); oper.pop();
                bool v2 = val.top(); val.pop();
                if (op == '~') val.push(v2 ^ 1);
                else {
                    bool v1 = val.top(); val.pop();
                    val.push(cal(v1, op, v2));
                }
            }
            oper.push(f);
        }
    }

    while (!oper.empty()) {
        char op = oper.top(); oper.pop();
        bool v2 = val.top(); val.pop();
        if (op == '~') val.push(v2 ^ 1);
        else {
            bool v1 = val.top(); val.pop();
            val.push(cal(v1, op, v2));
        }
    }

    if (val.size() != 1 || !oper.empty()) {
        assert(0);
    }

    return val.top();

}

void solve() {

    string s;
    getline(cin, s);
    
    string ts;
    for (auto f : s)if (f != ' ') ts += f;
    s = ts;
    int n = s.size();
    int spl = 0;
    
    for (int i = 1; i < n; i++) {
        char c0 = s[i - 1];
        char c1 = s[i];

        bool ok = 1;
        if (c0 == '~' || c0 == '&' || c0 == '|' || c0 == '^' || c0 == '(') ok = 0;
        if (c1 == '&' || c1 == '|' || c1 == '^' || c1 == ')') ok = 0;

        if (ok) {
            spl = i;
        }
    }

    string exp1, exp2;
    exp1 = s.substr(0, spl);
    exp2 = s.substr(spl, n);

    vector<char> cLst;
    for (auto f : s) if (isalpha(f)) cLst.push_back(f);
    sort(all(cLst));
    cLst.erase(unique(all(cLst)), cLst.end());

    int sn = cLst.size();
    for (int i = 0; i < (1 << sn); i++) {

        for (int j = 0; j < sn; j++) {
            if (i & (1 << j)) state[cLst[j] - 'a'] = 1;
            else state[cLst[j] - 'a'] = 0;
        }
        //cout << "State: ";
        //for (int j = 0; j < sn; j++) cout << state[cLst[j] - 'a'];
        //cout << '\n';

        bool v1 = getVal(exp1);
        bool v2 = getVal(exp2);
        //cout << v1 << ' ' << v2 << '\n';

        if (v1 ^ v2) {
            cout << "Different\n";
            return;
        }
    }

    cout << "Equivalent\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ord['('] = 0;
    ord['~'] = 1;
    ord['&'] = 2;
    ord['^'] = 3;
    ord['|'] = 4;

    int t = 1;
    cin >> t;
    cin.ignore();
    for(int i = 1; i<= t; i++){
        cout << "Data set " << i << ": ";
        solve();
    }
}
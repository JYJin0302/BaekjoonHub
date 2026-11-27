#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair

#define all(x) x.begin(), x.end()

void solve() {

    map<string, int> A;
    vector<string> name;

    string ts;
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    A[s] -= b - a;
    name.push_back(s);

    while (cin >> ts) {
        if (ts[0] == '-') break;
        a = stoi(ts);
        cin >> b >> s;
        A[s] -= b - a;
        name.push_back(s);
    }

    cin >> a >> b >> s;
    A[s] += b - a;
    name.push_back(s);
    while (cin >> ts) {
        if (ts[0] == '=') break;
        a = stoi(ts);
        cin >> b >> s;
        A[s] += b - a;
        name.push_back(s);
    }

    sort(all(name));
    name.erase(unique(all(name)), name.end());

    bool chk = 0;

    for (auto f : name) {
        if (A[f] != 0) chk = 1;
    }

    if (chk) {
        for (auto f : name)  if (A[f] != 0) {
            cout << f << ' ';
            if (A[f] > 0) cout << '+';
            cout << A[f] << '\n';
        }
    }
    else {
        cout << "No differences found.\n";
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[9];

map<string, bool> check;

void solve() {

    adj[0] = { 1, 3, 4 };
    adj[1] = { 3 };
    adj[2] = { 2, 3 };
    adj[3] = { 1 };
    adj[6] = { 1 };


    vector<int> ord;
    for (int i = 0; i < 9; i++) ord.push_back(i);

    do {
        string grid(9, '.');

        for (int f = 0; f < 9; f++) {
            if (f & 1) {
                grid[ord[f]] = 'O';
            }
            else {
                grid[ord[f]] = 'X';
            }

            int finish = 0;
            for (int i = 0; i < 9; i++) {
                for (auto d : adj[i]) {
                    if (grid[i] == grid[i + d] && grid[i] == grid[i + 2 * d] && grid[i] != '.') finish++;
                }
            }

            if (finish) {
                break;
            }

        }
        check[grid] = 1;

    } while (next_permutation(all(ord)));


    string s;
    cin >> s;

    while (s.size() == 9) {

        if (check[s]) cout << "valid\n";
        else cout << "invalid\n";
        cin >> s;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}
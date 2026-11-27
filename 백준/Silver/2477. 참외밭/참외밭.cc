#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int v;
    cin >> v;
    vector<int> cal(5);
    vector<pair<int, int>> A(6);
    for (auto& i : A) {
        cin >> i.first >> i.second;
        cal[i.first] += i.second;
    }

    int area = cal[1] * cal[3];
    for (int i = 0; i < 6; i++) {
        int p2 = (i + 4) % 6;
        int p1 = (i + 5) % 6;
        int n1 = (i + 1) % 6;
        if (A[i].first == A[p2].first && A[n1].first == A[p1].first) {
            area -= A[i].second * A[p1].second;
            break;
        }
    }
    cout << area * v;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
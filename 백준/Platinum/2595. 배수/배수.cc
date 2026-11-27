#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n;
int track[11];

vector<string> ansList;
int from[30000];

bool cmp(string& s1, string& s2) {
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    return s1 < s2;
}

void check(int cnt) {
    memset(from, -1, sizeof(from));

    queue<int> q;
    for (int i = 0; i < cnt; i++) {
        if (track[i] != 0) {
            q.push(track[i]);
            from[track[i]] = 0;
        }
    }

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        //cout << "Que: " << a << ' ' << from[a] << '\n';
        if (a == 0) break;
        for (int j = 0; j < cnt; j++) {
            int na = (a * 10 + track[j]) % n;
            if (from[na] == -1) {
                from[na] = a;
                q.push(na);
            }
        }
    }

    if (from[0] == -1) return;

    string ans;
    int cur = 0;
    while (from[cur] != 0) {
        int pv = from[cur];
        for (int j = 0; j < cnt; j++) {
            if ((pv * 10 + track[j]) % n == cur) {
                ans += '0' + track[j];
                break;
            }
        }
        cur = pv;
    }
    ans += '0' + cur;
    reverse(all(ans));
    ansList.push_back(ans);
    //cout << "ANS found: " << ans << '\n';
}



void choose(int cnt, int cur = 0, int pre = 0) {
    if (cur == cnt) {
        if (cnt == 1 && track[0] == 0) return;
        check(cnt);
        return;
    }
    for (int j = pre; j <= 9; j++) {
        track[cur] = j;
        choose(cnt, cur + 1, j + 1);
    }
}

void solve() {
    
    cin >> n;

    if (n <= 11) {
        cout << n << '\n';
        return;
    }

    for (int j = 1; j <= 10; j++) {
        choose(j);
        if (!ansList.empty()) break;
    }

    sort(all(ansList), cmp);

    //for (auto f : ansList) cout << f << '\n';
    cout << ansList[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll c;
int n, m, k;

struct Stock {
    int s, k;
    string name;
    vector<ll> value;
} stockList[8];

vector<int> tmp;
int stateCnt = 0;

vector<int> num2state[101010];
map<ll, int> state2num;

ll getNum(vector<int>& v) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = res * 9 + v[i];
    }
    return res;
}

void setState(int sz, int rem) {
    if (sz == n) {
        ll val = getNum(tmp);
        num2state[stateCnt] = tmp;
        state2num[val] = stateCnt;
        stateCnt++;
        return;
    }
    for (int i = 0; i <= stockList[sz].k && i <= rem; i++) {
        tmp[sz] = i;
        setState(sz + 1, rem - i);
    }
}

vector<ll> dp[105], from[105];

vector<int> getState(ll v) {
    vector<int> res;
    for (int i = 0; i < n; i++) {
        res.push_back(v % 9);
        v /= 9;
    }
    reverse(all(res));
    return res;
}

int getState(vector<int>& v) {
    ll val = getNum(v);
    return state2num[val];
}


ll getCost() {
    string s;
    cin >> s;

    ll res = 0;
    int ix = 0;
    while (ix < s.size()) {
        if (s[ix] == '.') {
            s += '0';
            s += '0';

            for (int j = ix + 1; j <= ix + 2; j++) {
                res = res * 10 + (s[j] - '0');
            }
            return res;
        }
        int v = s[ix] - '0';
        res = res * 10 + v;
        ix++;
    }
    
    return res * 100;
}


void backtrack(int day, int state) {
    if (day == 0) return;

    vector<int> curr = num2state[state];
    vector<int> pre = num2state[from[day][state]];

    backtrack(day - 1, from[day][state]);
    for (int i = 0; i < n; i++) {
        if (curr[i] != pre[i]) {
            if (curr[i] == pre[i] + 1) {
                cout << "BUY " << stockList[i].name << '\n';
                return;
            }
            else if (curr[i] == pre[i] - 1) {
                cout << "SELL " << stockList[i].name << '\n';
                return;
            }
        }
    }
    cout << "HOLD\n";

}
void solve() {

   

    ll c = getCost();
    cin >> m >> n >> k;

    tmp = vector<int>(n);

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int s, k;
        cin >> s >> k;
        vector<ll> value(m);
        for (auto& f : value) f = getCost();
        stockList[i] = { s, k, name, value };
    }

    setState(0, k);

    for (int i = 0; i <= m; i++) {
        dp[i] = vector<ll>(stateCnt, -1);
        from[i] = vector<ll>(stateCnt, -1);
    }

    tmp = vector<int>(n);
    int init = getNum(tmp);
    dp[0][init] = c;
    from[0][init] = init;

    for (int i = 0; i < m; i++) {
        for (int state = 0; state < stateCnt; state++) {

            vector<int> currState = num2state[state];
            int rem = k;
            ll money = dp[i][state];
            if (money == -1) continue;

            for (auto f : currState) rem -= f;

            if (rem > 0) {
                // buy
                for (int f = 0; f < n; f++) {
                    if (currState[f] < stockList[f].k) {
                        ll cost = stockList[f].value[i] * stockList[f].s;
                        if (money >= cost) {
                            currState[f]++;

                            int newState = getState(currState);
                            dp[i + 1][newState] = max(dp[i + 1][newState], money - cost);
                            if (dp[i + 1][newState] == money - cost) {
                                from[i + 1][newState] = state;
                            }
                            currState[f]--;
                        }
                    }
                }
            }

            // sell
            for (int f = 0; f < n; f++) {
                if (currState[f] > 0) {
                    ll cost = stockList[f].value[i] * stockList[f].s;
                    currState[f]--; 
                    int newState = getState(currState);
                    dp[i + 1][newState] = max(dp[i + 1][newState], money + cost);
                    if (dp[i + 1][newState] == money + cost) {
                        from[i + 1][newState] = state;
                    }
                    currState[f]++;
                }
            }

            // hold
            dp[i + 1][state] = max(dp[i + 1][state], money);
            if (dp[i + 1][state] == money) {
                from[i + 1][state] = state;
            }
        }
    }
    ll ans = dp[m][init];
    cout << ans / 100 << '.';
    if (ans % 100 < 10) cout << 0;
    cout << ans % 100 << '\n';
    backtrack(m, init);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}
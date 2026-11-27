#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

bool isOper(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isAlpha(char c) {
    return c >= 'a' && c <= 'z';
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<string> sList;

    int pv = 0;
    int ix = 0;
    string curr;
    while(ix < n){
        if (curr.empty()) curr += s[ix++];
        else{
            char c1 = curr.back();
            char c2 = s[ix];

            bool ok = 1;
            if (isOper(c1) && isOper(c2)) {
                ok = 0;
            }
            else if (isAlpha(c1) && c2 == '(') {
                ok = 0;
            }
            else if (c1 == ')' && isAlpha(c2)) {
                ok = 0;
            }
            else if (c1 == '(' && c2 == ')') {
                ok = 0;
            }
            else if (c1 == ')' && c2 == '(') {
                ok = 0;
            }
            else if (c1 == '(' && isOper(c2)) {
                ok = 0;
            }
            else if (isOper(c1) && c2 == ')') {
                ok = 0;
            }

            if (!ok) {
                sList.push_back(curr);
                curr = "";
            }
            curr += s[ix++];
        }
    }

    if (!curr.empty()) sList.push_back(curr);
    curr = "";

    ll ans = 0;

    for (auto s : sList) {
        ll res = 0;

        int tn = s.size();
        stack<int> st;
        vector<int> nxt(tn + 1, -1);
        for (int i = 0; i < tn; i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (st.empty()) nxt[i] = -1;
                else {
                    nxt[st.top()] = i;
                    st.pop();
                }
            }
        }

        int l = 0, r = tn - 1;
        while (l < tn && (s[l] == ')' || isOper(s[l]))) l++;
        while (r >= 0 && (s[r] == '(' || isOper(s[r]))) r--;

        vector<bool> vs(tn + 10);
        for (int i = l; i <= r; i++) {
            if (vs[i]) continue;
            if (s[i] == ')' || isOper(s[i])) continue;

            int currIdx = i;
            int cnt = 0;
            vector<ll> tmp;

            while (currIdx < tn) {
                if (vs[currIdx]) break;
                vs[currIdx] = 1;
                if (isAlpha(s[currIdx])) {
                    cnt++;
                    currIdx++;
                }
                else {
                    if (cnt != 0) tmp.push_back(cnt);
                    cnt = 0;

                    if (s[currIdx] == '(') {
                        if (nxt[currIdx] != -1) {
                            tmp.push_back(1);
                            currIdx = nxt[currIdx] + 1;
                        }
                        else break;
                    }
                    else if (s[currIdx] == ')') break;
                    else currIdx++;
                }
            }
            if (cnt) tmp.push_back(cnt);
            cnt = 0;

            if (tmp.empty()) continue;

            int tz = tmp.size();
            vector<ll> sA(tz);
            sA[0] = tmp[0];
            for (int i = 1; i < tz; i++) sA[i] = sA[i - 1] + tmp[i];

            for (int i = 0; i < tz; i++) {
                res += tmp[i] * (tmp[i] + 1) / 2;
                res += tmp[i] * (sA[tz - 1] - sA[i]);
            }
        }

        ans += res;
    }
    cout << ans;

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
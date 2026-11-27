#include <bits/stdc++.h>
using namespace std;

struct T {
    int t, a, b, y;
    char c1, c2;
    T(int x1, int x2, int x3) {
        t = x1;
        a = x2;
        b = x3;
    }
    T(int x1, int x2, char cc, char cc2) {
        t = x1;
        y = x2;
        c1 = cc;
        c2 = cc2;
    }
};
vector<T> ans, rev;

char merge(char c1, char c2) {
    return char('R' + 'G' + 'B' - c1 - c2);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n1, n2;
    string s1 , s2;
    cin >> n1 >> s1 >> n2 >> s2;

    stack<char> st;
    for (int i = 0; i < n1; i++) {
        if (st.empty()) {
            st.push(s1[i]);
        }
        else {
            if (st.top() != s1[i]) {
                char tmp = merge(st.top(), s1[i]);
                ans.push_back({ 1, (int)st.size(), (int)st.size() + 1 });
                st.pop();

                if (!st.empty()) {
                    ans.push_back({ 1, 1, 2 });
                    st.pop();
                    st.push(s1[i]);
                }
                else st.push(tmp);
            }
            else if (st.size() == 2) {
                // 세개 스택
                char curr = s1[i];
                if (curr == 'R') {
                    ans.push_back({ 2, 1, 'G' ,'B' });
                }
                else if (curr == 'G') {
                    ans.push_back({ 2, 1, 'R', 'B' });
                }
                else {
                    ans.push_back({ 2, 1, 'R', 'G' });
                }
                ans.push_back({ 1, 2, 3 });
                ans.push_back({ 1, 2, 3 });
                ans.push_back({ 1, 1, 2 });
                st.pop();
            }
            else st.push(s1[i]);
        }
    }

    string res1;
    while (!st.empty()) {
        res1 += st.top();
        st.pop();
    }

    for (int i = 0; i < n2; i++) {
        if (st.empty()) {
            st.push(s2[i]);
        }
        else {
            if (st.top() != s2[i]) {
                char tmp = merge(st.top(), s2[i]);
                //ans.push_back({ 1, (int)st.size(), (int)st.size() + 1 });
                char tp = st.top();
                st.pop();

                if (!st.empty()) {
                    //ans.push_back({ 1, 1, 2 });
                    rev.push_back({ 2, 2, tp, s2[i] });
                    rev.push_back({ 2, 1, tp, tmp });
                    st.pop();
                    st.push(s2[i]);
                }
                else {
                    rev.push_back({ 2, 1, tp, s2[i] });
                    st.push(tmp);
                }
            }
            else if (st.size() == 2) {

                char curr = s2[i];
                if (curr == 'R') {
                    rev.push_back({ 1, 1, 2 });
                    rev.push_back({ 2, 2, 'B', 'R' });
                    rev.push_back({ 2, 2, 'G', 'R' });
                    rev.push_back({ 2, 1, 'G' ,'B' });
                }
                else if (curr == 'G') {
                    rev.push_back({ 1, 1, 2 });
                    rev.push_back({ 2, 2, 'B', 'G' });
                    rev.push_back({ 2, 2, 'R', 'G' });
                    rev.push_back({ 2, 1, 'R', 'B' });
                }
                else {
                    rev.push_back({ 1, 1, 2 });
                    rev.push_back({ 2, 2, 'G', 'B' });
                    rev.push_back({ 2, 2, 'R', 'B' });
                    rev.push_back({ 2, 1, 'R', 'G' });
                }
                st.pop();
            }
            else st.push(s2[i]);
        }
    }

    string res2;
    while (!st.empty()) {
        res2 += st.top();
        st.pop();
    }

   // cout << res1 << ' ' << res2 << '\n';

    if (res1.size() == 2 && res2.size() == 2) {
        if (res1 != res2) {
            char tmp = merge(res1[0], res2[0]);
            ans.push_back({ 2, 2, tmp, res2[0] });
            ans.push_back({ 1, 1, 2 });
        }
    }

    if (res1 != res2 && (res1.size() == 1 || res2.size() == 1)) {
        cout << -1;
        return 0;
    }

    

  //  cout << "ANS: \n";

    cout << ans.size() + rev.size() << '\n';
    for (auto i : ans) {
        if (i.t == 1) {
            cout << i.t << ' ' << i.a << ' ' << i.b << '\n';
        }
        else cout << i.t << ' ' << i.y << ' ' << i.c1 << ' ' << i.c2 << '\n';
    }

    //cout << "REV: \n";
    reverse(rev.begin(), rev.end());
    for (auto i : rev) {
        if (i.t == 1) {
            cout << i.t << ' ' << i.a << ' ' << i.b << '\n';
        }
        else cout << i.t << ' ' << i.y << ' ' << i.c1 << ' ' << i.c2 << '\n';
    }

}
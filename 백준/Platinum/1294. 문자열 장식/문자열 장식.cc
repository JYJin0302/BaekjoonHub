#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(string s1, string s2) {
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] != s2[i]) return s1[i] > s2[i];
        }
        return s1 + s2 > s2 + s1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<string, vector<string>, cmp> pq;
    for (int i = 0; i < n; i++) {
        string  s;
        cin >> s;
        pq.push(s);
    }

    while (!pq.empty()) {
        string a = pq.top();
        pq.pop();
        cout << a[0];

        if (a.size() > 1) {
            pq.push(a.substr(1, a.size()));
        }
    }
}
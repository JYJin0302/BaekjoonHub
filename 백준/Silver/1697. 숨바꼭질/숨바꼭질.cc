#include <bits/stdc++.h>
using namespace std;

int n, k, ans, test, a, b, c;
queue<int> q;
queue<int> temp;
vector<bool> check(100001);
void bfs() {
    while (!q.empty()) {
        test = q.front();
        q.pop();
        if (test == k) return;
        a = test - 1;
        b = test + 1;
        c = test * 2;
        if (test > 0) {
            if (!check[a]) { temp.push(a); check[a] = 1; }
        }
        if (test < k) {
            if (!check[b]) { temp.push(b); check[b] = 1; }
            if (test <= 50000 && !check[c] ) { temp.push(c); check[c] = 1; }
        }
    }
    swap(q, temp);
    ans++;
    bfs();
}



int main() {
    cin >> n >> k;
    q.push(n);
    ans = 0;
    bfs();
    cout << ans;
}
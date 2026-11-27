#include <bits/stdc++.h>
using namespace std;

int root[1000001];
int lev[1000001];

int n, m, a, b, c;

int find(int k) {
    if (k == root[k]) return k;
    return root[k] = find(root[k]);
}

void add(int t1, int t2) {
    int x = find(t1);
    int y = find(t2);

    if (x == y) return;

    if (lev[x] > lev[y]){
        root[y] = x;
    }
    else if (lev[x] < lev[y]){
        root[x] = y;
    }
    else{
        root[x] = y;
        lev[x]++;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        root[i] = i;
        lev[i] = 0;
    }
    

    while (m--) {
        cin >> a >> b >> c;
        if (a == 0) {
            add(b, c);
        }
        else {
            cout << (find(b) == find(c) ? "YES\n" : "NO\n");
        }
    }
}
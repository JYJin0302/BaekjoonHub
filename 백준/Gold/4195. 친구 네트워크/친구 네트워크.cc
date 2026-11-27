#include <bits/stdc++.h>
using namespace std;

int root[200002];
int friends[200002];


int t, n, m, a, b;
string s1, s2;

int find(int k) {
    if (k == root[k]) return k;
    return root[k] = find(root[k]);
}

void add(int t1, int t2) {
    int x = find(t1);
    int y = find(t2);

    if (x == y) {cout << friends[x] << '\n'; return;}
    root[y] = x;

    int temp = friends[x] + friends[y];
    friends[x] = temp;
    friends[y] = temp;
    cout << temp << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2*n; i++) {
            root[i] = i;
            friends[i] = 1;
        }
        int ind = 1;
        map<string, int> peep;
        while (n--) {
            cin >> s1 >> s2;
            if (peep[s1] == 0) peep[s1] = ind++;
            if (peep[s2] == 0) peep[s2] = ind++;
            a = peep[s1];
            b = peep[s2];
            add(a, b);
        }
        peep.clear();
    }
}
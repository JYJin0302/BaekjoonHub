#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second

struct Trie {
    int ch[26];
    int val = 0;
} root[4001010];
int sdx = 0;

void insert(Trie& curr, const char* s) {
    if (*s == NULL) {
        return;
    }

    int ndx = *s - 'a';
    int val = curr.val;
    if (curr.ch[ndx] == 0) {
        curr.ch[ndx] = ++sdx;
    }
    else {
        val ^= root[curr.ch[ndx]].val + 1;
    }
    insert(root[curr.ch[ndx]], s + 1);
    val ^= root[curr.ch[ndx]].val + 1;
    curr.val = val;
   // cout << "Curr: " << *s << " . " << curr.val << '\n';
}
void pf(Trie& curr, int cnt = 0) {

    for (int i = 0; i < 26; i++) {
        if (curr.ch[i]) {
           // cout << string(cnt * 2, '-') << char('a' + i) << ' ' << root[curr.ch[i]].val << '\n';
            pf(root[curr.ch[i]], cnt + 1);
        }
    }
}

void solve() {


    while (sdx) {
        root[sdx--] = Trie();
    }
    root[0] = Trie();
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        insert(root[0], s.c_str());

        //cout << root[0].val << '\n';
        //pf(root[0]);
    }

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        insert(root[0], s.c_str());
        /*cout << root[0].val << '\n';
        pf(root[0]);*/

        if (root[0].val != 0) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}

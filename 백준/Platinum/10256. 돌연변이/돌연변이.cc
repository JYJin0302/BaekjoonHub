#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

map<char, int> ctoi;

struct Node {

    int go[4];
    int fail;
    bool isEnd;

    Node() {
        memset(go, -1, sizeof(go));
        fail = 0;
        isEnd = 0;
    }


} Trie[1010101];


int sdx = 0;
void insert(const char* s, Node& curr) {
    if (*s == NULL) {
        curr.isEnd = 1;
        return;
    }

    int ix = ctoi[*s];
    if (curr.go[ix] == -1) {
        curr.go[ix] = ++sdx;
    }

    insert(s + 1, Trie[curr.go[ix]]);
}

void solve() {

    int n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;

    vector<string> st;
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            string tmp = s2;
            reverse(tmp.begin() + i, tmp.begin() + j+1);
            st.push_back(tmp);
        }
    }
    st.push_back(s2);
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());

    for (int i = 0; i <= sdx; i++) Trie[i] = Node();
    sdx = 0;

    for (string s : st) {
        insert(s.c_str(), Trie[0]);
    }

    queue<int> q;
    q.push(0);
    while (!q.empty()) {

        int a = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (Trie[a].go[i] == -1)continue;
            int currx = Trie[a].go[i];

            int nxt = Trie[a].fail;
            if (a == 0) {
                Trie[currx].fail = 0;
            }
            else {
                while (nxt && Trie[nxt].go[i] == -1) nxt = Trie[nxt].fail;

                if (Trie[nxt].go[i] != -1) nxt = Trie[nxt].go[i];
                Trie[currx].fail = nxt;
            }
            if (Trie[Trie[currx].fail].isEnd) Trie[currx].isEnd = 1;

            q.push(currx);
        }
    }

    int ans = 0;
    int curr = 0, idx = 0;
    while (idx < n) {
        int c = ctoi[s1[idx]];

        if (Trie[curr].go[c] != -1) {
            curr = Trie[curr].go[c];
        }
        else {
            while (curr && Trie[curr].go[c] == -1) curr = Trie[curr].fail;
            if (Trie[curr].go[c] != -1) curr = Trie[curr].go[c];
        }

        if (Trie[curr].isEnd) ans++;
        idx++;
    }
    cout << ans << '\n';


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ctoi['A'] = 0;
    ctoi['C'] = 1;
    ctoi['G'] = 2;
    ctoi['T'] = 3;

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

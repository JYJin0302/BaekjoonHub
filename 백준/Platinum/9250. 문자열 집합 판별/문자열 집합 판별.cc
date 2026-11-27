#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

struct Node {

    int go[26];
    int fail;
    bool isEnd;

    Node() {
        memset(go, -1, sizeof(go));
        fail = 0;
        isEnd = 0;
    }


} lst[101010];

int sdx = 0;
void insert(const char* s, Node& curr) {
    if (*s == NULL) {
        curr.isEnd = 1;
        return;
    }

    int ix = *s - 'a';
    if (curr.go[ix] == -1) {
        curr.go[ix] = ++sdx;
    }

    insert(s + 1, lst[curr.go[ix]]);
}

void pf(Node& curr, string tmp = "", int idx = 0) {
    
    cout << string(tmp == "" ? "EMPTY" : tmp) << ' ' << idx << ": ";
    cout << curr.isEnd << ' ' << curr.fail << '\n';

    for (int i = 0; i < 26; i++) {
        if (curr.go[i] != -1) {
            pf(lst[curr.go[i]], tmp + char('a' + i), curr.go[i]);
        }
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        // insert i
        insert(s.c_str(), lst[0]);
    }

    queue<int> q;
    q.push(0);
    while (!q.empty()) {

        int a = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            if (lst[a].go[i] == -1)continue;
            int currx = lst[a].go[i];

            int nxt = lst[a].fail;
            if (a == 0) {
                lst[currx].fail = 0;
            }
            else {
                while (nxt && lst[nxt].go[i] == -1) nxt = lst[nxt].fail;

                if (lst[nxt].go[i] != -1) nxt = lst[nxt].go[i];
                lst[currx].fail = nxt;
            }
            if (lst[lst[currx].fail].isEnd) lst[currx].isEnd = 1;

            q.push(currx);
        }
    }

   // pf(lst[0]);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        bool found = 0;

        int currx = 0;

        for (auto f : s) {
            int ix = f - 'a';
            //cout << "Curr: " << char(f) << ' ' << currx << '\n';

            int nx = currx;
            while (nx && lst[nx].go[ix] == -1) {
                nx = lst[nx].fail;
            }
            if (lst[nx].go[ix] != -1) nx = lst[nx].go[ix];

            if (lst[nx].isEnd) {
                found = 1;
                break;
            }
            currx = nx;
        }

        if (found) {
            cout << "YES\n";
        }
        else cout << "NO\n";

    }

}
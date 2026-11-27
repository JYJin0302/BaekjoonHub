#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int s[100010], e[100010];

struct Node {
    int val;
    Node* l, * r;

    Node() {
        l = NULL;
        r = NULL;
        val = 0;
    }
};

Node* root[100010];

void init(int l, int r, Node* curr) {
    if (l == r) {
        curr->val = 0;
        return;
    }
    int m = (l + r) / 2;
    curr->l = new Node();
    init(l, m, curr->l);
    curr->r = new Node();
    init(m + 1, r, curr->r);
    curr->val = curr->l->val + curr->r->val;
}

void update(int l, int r, int u, int v, Node* curr, Node* prev) {

    if (l == u && r == u) {
        curr->val = prev->val + v;
        return;
    }

    int m = (l + r) / 2;
    if (u <= m) {
        curr->l = new Node();
        curr->r = prev->r;
        update(l, m, u, v, curr->l, prev->l);
    }
    else {
        curr->r = new Node();
        curr->l = prev->l;
        update(m + 1, r, u, v, curr->r, prev->r);
    }
    curr->val = curr->l->val + curr->r->val;
}

int ssum(int l, int r, int sl, int sr, Node* curr) {

    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return curr->val;

    int m = (l + r) / 2;

    int res = 0;
    if (curr->l != NULL) res += ssum(l, m, sl, sr, curr->l);
    if (curr->r != NULL) res += ssum(m + 1, r, sl, sr, curr->r);
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cin.ignore();

    int sn = 1;
    while (sn < n) sn *= 2;

    for (int i = 0; i < n; i++) {
        string ss;
        getline(cin, ss);

        //cout << "Curr: " << ss << '\n';
        int ix = 0;
        while (ix < ss.size()) {

            int nx = ix + 1;
            int val = 0;
            while (nx < ss.size() && ss[nx] != ' ') {
                val = val * 10 + (ss[nx] - '0');
                nx++;
            }
            nx++;

            if (ss[ix] == '-') {
                e[val] = i + 1;
            }
            else {
                s[val] = i + 1;
            }
            ix = nx;
        }
    }

    for (int i = 0; i <= n; i++) root[i] = new Node();
    init(0, sn - 1, root[n]);


    for (int i = n - 1; i >= 0; i--) {

       // cout << "update: " << s[i] << ' ' << e[i] << '\n';

        Node* tmp = new Node();
        update(0, sn - 1, s[i], 1, root[i], root[i+1]);
        update(0, sn - 1, e[i], -1, tmp, root[i]);
        root[i] = tmp;
       /* cout << "DBG\n";

        for (int ti = 0; ti <= n; ti++) {

            for (int j = 0; j < sn*2; j++) {
                cout << ssum(0, sn - 1, j, j, root[ti]) << ' ';
            }
            cout << '\n';
        }*/
    }

    

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int val = ssum(0, sn - 1, 0, x, root[ans]);
        ans = (ans + val) % n;

        //cout << val << " -> "  << ans << '\n';
    }
    cout << ans;

}
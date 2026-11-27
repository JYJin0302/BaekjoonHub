#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define E pair<int,pair<int, int>>

int x, y, z;


int root[1010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

vector<int> num;
vector<pair<int, int>> adj[1010];

int getIdx(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

struct Node {
    //Node* l, * r;

    int val, ldx, rdx;

    Node() {
        ldx = rdx = -1;
        val = 0;
    }
};

Node nodeA[5001010];
int rootidx[100010];
int nodeCnt = 0;


void newNode() {
    nodeA[++nodeCnt] = Node();
}


void init(int l, int r, Node& curr) {
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    newNode();
    curr.ldx = nodeCnt;
    newNode();
    curr.rdx = nodeCnt;
    init(l, m, nodeA[curr.ldx]);
    init(m + 1, r, nodeA[curr.rdx]);
}

void update(int l, int r, int u, int v, Node& curr, Node& prev) {

    if (l == u && r == u) {
        curr.val = prev.val + v;
        return;
    }

    int m = (l + r) / 2;
    if (u <= m) {
        newNode();
        curr.ldx = nodeCnt;
        curr.rdx = prev.rdx;
        update(l, m, u, v, nodeA[curr.ldx], nodeA[prev.ldx]);
    }
    else {
        newNode();
        curr.rdx = nodeCnt;
        curr.ldx = prev.ldx;
        update(m + 1, r, u, v, nodeA[curr.rdx], nodeA[prev.rdx]);
    }
    curr.val = nodeA[curr.ldx].val + nodeA[curr.rdx].val;
}

int ssum(int l, int r, int sl, int sr, Node& curr) {

    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return curr.val;

    int m = (l + r) / 2;

    int res = 0;
    if (curr.ldx != -1) res += ssum(l, m, sl, sr, nodeA[curr.ldx]);
    if (curr.rdx != -1) res += ssum(m + 1, r, sl, sr, nodeA[curr.rdx]);
    return res;
}

pair<int, int> rmv;
int getRes(int u, int v, int pv, int mxV, pair<int, int> curr) {

    if (u == v) {
        rmv = curr;
        return mxV;
    }

    for (auto i : adj[u])if (i.first != pv) {
        int rs;
        if (i.second < mxV) {
            rs = getRes(i.first, v, u, mxV, curr);
        }
        else {
            rmv = { u, i.first };
            rs = getRes(i.first, v, u, i.second, make_pair(u, i.first));
        }
        if (rs != -1) return rs;
    }
    return -1;
}

void solve() {

    nodeCnt = 0;
    int n, m;
    cin >> n >> m;

    num.clear();
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        adj[i].clear();
    }


    vector<E> A(m);
    for (auto& i : A) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);

        i = { c, {a, b} };
        num.push_back(c);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    int sz = num.size();

    vector<E> currEdge;
    sort(A.rbegin(), A.rend());

    newNode();
    rootidx[0] = 1;
    init(0, sz - 1, nodeA[1]);

    int pv = 1;
    for (auto i : A) {

        assert(currEdge.size() < n + 10);

        int a = find(i.second.first), b = find(i.second.second);
        int ix = getIdx(i.first) + 1;
        // cout << "curr state: " << nodeCnt << '\n';
        int prev, curr;
        // add weight
       // cout << "Go update: " << ix - 1 << ' ' << i.first << ' ' << ix << '\n';
        newNode();
        curr = nodeCnt;
        prev = pv;
        pv = curr;
        update(0, sz - 1, ix - 1, i.first, nodeA[curr], nodeA[prev]);
        rootidx[ix - 1] = curr;

        if (a == b) {
            // get maxWeight
            int res = -1;
            rmv = { -1, -1 };
            //cout << "Gores: ";
            res = getRes(i.second.first, i.second.second, -1, -1, rmv);

            assert(res != -1);

            int ra, rb;
            tie(ra, rb) = rmv;
            if (ra > rb) swap(ra, rb);
            // cout << "RMv: " << ra << ' ' << rb << ' ' << res << '\n';
            adj[ra].erase(find(adj[ra].begin(), adj[ra].end(), make_pair(rb, res)));
            adj[rb].erase(find(adj[rb].begin(), adj[rb].end(), make_pair(ra, res)));
            currEdge.erase(remove_if(currEdge.begin(), currEdge.end(), [&](E& tE) {
                return tE.second.first == ra && tE.second.second == rb;
                }),
                currEdge.end());
            //  cout << "Go update: " << getIdx(res) << ' ' << -res << ' ' << ix << '\n';
            newNode();
            curr = nodeCnt;
            prev = pv;
            pv = curr;
            update(0, sz - 1, getIdx(res), -res, nodeA[curr], nodeA[prev]);

            rootidx[ix - 1] = curr;
        }
        else root[a] = b;

        adj[i.second.first].push_back({ i.second.second, i.first });
        adj[i.second.second].push_back({ i.second.first, i.first });
        currEdge.push_back(i);
    }
  //  cout << "Fin\n";

    //for (int i = 0; i <= currix; i++) {
    //   //print tree
    //   cout << "RES: " << i << '\n';
    //   pf(0, sz-1, troot[i]);
    //}

    int q, df = 0;
    cin >> q;
    while (q--) {

        int l, r;
        cin >> l >> r;

        l -= df;
        r -= df;
        l = getIdx(l);
        r = getIdx(r + 1) - 1;

        // cout << l << ' ' << r << ' ' << aix[l] << '\n';
        int ans;
        if (l <= r) ans = ssum(0, sz - 1, l, r, nodeA[rootidx[l]]);
        else ans = 0;

        cout << ans << '\n';
        df = ans;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}
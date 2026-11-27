#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int A[310101];

struct Node {
    Node* l, * r, * p;
    ll v, sz, sm, mx, mn;


    bool flip, rev;
    Node(ll _v, Node* p) : v(_v), p(p) {
        l = r = nullptr;
        sm = mx = mn = v;
        sz = 1, flip = 0, rev = 0;
    }
    Node(int _v) : Node(_v, nullptr) {}
    Node() : Node(0) {}
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }

};

struct SplayTree {
    Node* root;
    Node* ptr[310101]; //node pointer
    int N;
    string pf;

    void update(Node* x) {
        x->sz = 1;
        x->sm = x->mx = x->mn = x->v;

        if (x->l) {
            x->sz += x->l->sz;
            x->sm += x->l->sm;
            x->mn = min(x->mn, x->l->mn);
            x->mx = max(x->mx, x->l->mx);
        }
        if (x->r) {
            x->sz += x->r->sz;
            x->sm += x->r->sm;
            x->mn = min(x->mn, x->r->mn);
            x->mx = max(x->mx, x->r->mx);
        }
    }

    void push(Node* x) { // lazy propagate
        if (x->flip) {
            swap(x->l, x->r);
            if (x->l) x->l->flip = !x->l->flip;
            if (x->r) x->r->flip = !x->r->flip;
            x->flip = 0;
        }
    }

    Node* gather(int s, int e) { //gather [s, e]
        if (s == 1 && e == N) return root;
        if (s == 1) {
            kth(e + 1);
            return root->l;
        }
        if (e == N) {
            kth(s - 1);
            return root->r;
        }
        kth(e + 1);
        auto tmp = root;
        kth(s - 1);
        splay(tmp, root);
        return root->r->l;
    }

    void rotate(Node* x) {
        auto p = x->p;
        Node* y;
        push(p); push(x);
        if (x == p->l) {
            p->l = y = x->r;
            x->r = p;
        }
        else {
            p->r = y = x->l;
            x->l = p;
        }
        x->p = p->p; p->p = x;
        if (y) y->p = p;
        if (x->p) {
            if (p == x->p->l) x->p->l = x;
            else x->p->r = x;
        }
        else root = x;
        update(p); update(x);
    }

    void splay(Node* x, Node* g = nullptr) {
        if (!x) return;
        Node* y;
        while (x->p != g) {
            Node* p = x->p;
            if (p->p == g) {
                rotate(x); break;
            }
            auto pp = p->p;
            if ((p->l == x) == (pp->l == p)) {
                rotate(p); rotate(x);
            }
            else {
                rotate(x); rotate(x);
            }
        }
        if (!g) root = x;
    }

    SplayTree() : root(), N(0) {
        memset(ptr, 0, sizeof ptr);
    }
    ~SplayTree() {
        if (root) delete root;
    }

    void init(int n) {
        if (root) delete root;
        N = n;
        ptr[1] = root = new Node(A[1]);
        auto now = root;
        for (int i = 2; i <= n; i++) {
            ptr[i] = now->r = new Node(A[i], now);
            now = now->r;
        }
        for (int i = n; i >= 1; i--) update(ptr[i]);
        splay(ptr[n / 2]);
    }

    void flip(int s, int e) {
        Node* x = gather(s, e);
        x->flip = !x->flip;
        splay(x);
    }

    void shift(int s, int e, int k) {
        Node* x = gather(s, e);
        if (k >= 0) {
            k %= (e - s + 1);
            if (!k) return;
            flip(s, e); flip(s, s + k - 1); flip(s + k, e);
        }
        else {
            k *= -1;
            k %= (e - s + 1);
            if (!k) return;
            flip(s, e); flip(s, e - k); flip(e - k + 1, e);
        }
        splay(x);
    }

    void kth(int k) {
        k--;
        auto now = root;
        push(now);
        while (1) {
            while (now->l && now->l->sz > k) {
                now = now->l; push(now);
            }
            if (now->l) k -= now->l->sz;
            if (!k) break; k--;
            now = now->r;
            push(now);
        }
        splay(now);
    }

    void print(Node* x) {
        push(x);
        if (x->l) print(x->l);
        cout << x->v << ' ';
        if (x->r) print(x->r);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        A[i] = i;
    }

    SplayTree st;
    st.init(n);

    while (m--) {
        int t;
        cin >> t;

        int l, r, x;
        Node* tmp;
        switch (t) {
        case 1:
            cin >> l >> r;
            tmp = st.gather(l, r);
            cout << tmp->mn << ' ' << tmp->mx << ' ' << tmp->sm << '\n';
            st.flip(l, r);
            break;
        case 2:
            cin >> l >> r >> x;
            tmp = st.gather(l, r);
            cout << tmp->mn << ' ' << tmp->mx << ' ' << tmp->sm << '\n';
            st.shift(l, r, x);
            break;
        case 3:
            cin >> x;
            st.kth(x);
            cout << st.root->v << '\n';
            break;
        case 4:
            cin >> x;
            st.splay(st.ptr[x]);

            int v = 0;
            if (st.root->l) v = st.root->l->sz;
            cout << v + 1 << '\n';
            break;
        }
    }

    st.print(st.root);
}

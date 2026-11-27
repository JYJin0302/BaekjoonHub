#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int A[101010];

struct Node {
    Node* l, * r, * p;
    ll v, Lv, Rv, Mv, sz;
    bool dummy, flip;

    Node(ll _v, Node* p) : v(_v), p(p) {
        l = r = nullptr;
        Lv = Rv = Mv = _v;
        sz = 1, dummy = 0, flip = 0;
    }
    Node(int _v) : Node(_v, nullptr) {}
    Node() : Node(0) {}
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }

    void pf() {
        cout << v << ' ' << Lv << ' ' << Rv << ' ' << Mv << ' ' << sz << '\n';
    }
};

struct SplayTree {
    Node* root;
    Node* ptr[101010]; //node pointer
    int N;

    void update(Node* x) {
        x->sz = 1;
        x->Mv = x->Lv = x->Rv = x->v;

        if (x->l) {
            push(x->l);

            x->Mv = max({ x->Mv, x->l->Mv, x->l->Rv + x->Lv });
            if (x->l->Lv == x->l->sz) x->Lv += x->l->Lv;
            else x->Lv = x->l->Lv;
            if (x->Rv == x->sz) x->Rv += x->l->Rv;
            x->sz += x->l->sz;

        }
        if (x->r) {
            push(x->r);

            x->Mv = max({ x->Mv, x->r->Mv, x->r->Lv + x->Rv });
            if (x->r->Rv == x->r->sz) x->Rv += x->r->Rv;
            else x->Rv = x->r->Rv;
            if (x->Lv == x->sz) x->Lv += x->r->Lv;
            x->sz += x->r->sz;
        }
    }

    void push(Node* x) { // lazy propagate
        if (!x->flip) return;
        swap(x->l, x->r);
        swap(x->Lv, x->Rv);
        if (x->l) x->l->flip = !x->l->flip;
        if (x->r) x->r->flip = !x->r->flip;
        x->flip = 0;
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

    void kth(int k) { //1-based
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

    void print(Node* x, int cnt = 1) {
        push(x);

        //cout << string(cnt, '-');
        //cout << '{' << x->v << ' ' << x->Lv << ' ' << x->Rv << ' ' << x->Mv << ' ' << x->sz << '}' << "\n";
        if (x->l) {
            //cout << 'L';
            print(x->l, cnt + 2);
        }
        if (x->r) {
           // cout << 'R';
            print(x->r, cnt + 2);
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> A[i];

    SplayTree st;
    st.init(n);

    cin >> m;
    while (m--) {

        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            // flip
            st.flip(l, r);
        }
        else {
            // query
            Node* tmp = st.gather(l, r);
            cout << tmp->Mv << '\n';
        }

        /*st.print(st.root);
        cout << '\n';*/
    }

}

#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
#define mp make_pair
ui A[210101];
ui comb[11][11];

struct Node {
    Node* l, * r, * p;
    ui v, sz, val[11], valf[11];

    bool flip, rev, dummy;
    Node(ui _v, Node* p) : v(_v), p(p) {
        l = r = nullptr;
        for (int i = 0; i <= 10; i++) val[i] = valf[i] = v;
        sz = 1, flip = 0, rev = 0, dummy = 0;
    }
    Node(ui _v) : Node(_v, nullptr) {}
    Node() : Node(0) {}
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }

    void pf(int k = 0) {
        cout << '{' << v << ' ' << sz << " | " << val[0] << ' ' << val[1] << ' ' << val[2] << " | " << valf[0] << ' ' << valf[1] << ' ' << valf[2] << "}";
    }

};

ui p(ui b, ui ex) {
    ui res = 1;
    while (ex--) res *= b;
    return res;
}

ui pwLen[11];
void setPw(ui x) {
    pwLen[0] = 1;
    for (int i = 1; i <= 10; i++) pwLen[i] = pwLen[i - 1] * x;
}

struct SplayTree {
    Node* root;
    int N;
    string pf;

    void update(Node* x) {
        x->sz = 1;
        for (int i = 0; i <= 10; i++) x->val[i] = x->valf[i] = x->v;

        if (x->l) {
            x->sz += x->l->sz;
            push(x->l);
        }
        if (x->r) {
            x->sz += x->r->sz;
            push(x->r);
        }

        ui tlen = 0;
        if (x->l) tlen = x->l->sz;
        setPw(tlen + 1);

        if (x->l) {
            for (int i = 0; i <= 10; i++) {
                x->val[i] *= pwLen[i];
                x->val[i] += x->l->val[i];
            }
        }
        if (x->r) {
            for (int i = 0; i <= 10; i++) {
                for (int j = 0; j <= i; j++) {
                    x->val[i] += x->r->val[j] * comb[i][i-j] * pwLen[i-j];
                }
            }
        }

        tlen = 0;
        if (x->r) tlen = x->r->sz;
        setPw(tlen + 1);
        if (x->r) {
            for (int i = 0; i <= 10; i++) {
                x->valf[i] *= pwLen[i];
                x->valf[i] += x->r->valf[i];
            }
        }
        if (x->l) {
            for (int i = 0; i <= 10; i++) {
                for (int j = 0; j <= i; j++) {
                    x->valf[i] += x->l->valf[j] * comb[i][i-j] * pwLen[i-j];
                }
            }
        }
    }

    void push(Node* x) { // lazy propagate
        if (x->flip) {
            swap(x->l, x->r);
            swap(x->val, x->valf);
            if (x->l) x->l->flip = !x->l->flip;
            if (x->r) x->r->flip = !x->r->flip;
            x->flip = 0;
        }
    }

    Node* gather(int s, int e) { //gather [s, e]
        if (s == 1 && e == N) {
            kth((N + 1) / 2);
            return root;
        }
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
    }
    ~SplayTree() {
        if (root) delete root;
    }

    void init(int n) {
        if (root) delete root;
        N = n;
        root = new Node(A[1]);
        auto now = root;
        for (int i = 2; i <= n; i++) {
            now->r = new Node(A[i], now);
            now = now->r;
        }

        while (now->p) {
            now = now->p;
            update(now);
        }
    }

    void flip(int s, int e) {
        if (s >= e) return;
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

    void kth(ui k) {
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

    void add(ui p, ui v) {
        p++;
        N++;
        if (N == 1) {
            root = new Node(v);
            return;
        }
        kth(N - 1);
        root->r = new Node(v, root);
        update(root);
        flip(p, N);
        flip(p + 1, N);
    }

    void rmv(ui p) {
        p++;
        // error when only p == 1.. why??
        if (N == 1) {
            root = nullptr;
            N--;
            return;
        }

        flip(p, N);
        kth(N);
        root = root->l;
        root->p = nullptr;
        N--;
        flip(p, N);
        update(root);
    }

    void print(Node* x, int sz = 0) {
        if (!x) {
            cout << "Empty\n";
            return;
        }
        //push(x);
        int tz = 0;
        if (x->l) tz = x->l->sz;
        cout << string((sz + tz) * 3, ' ');
        x->pf();
        cout << x->flip;
        cout << '\n';
        if (x->l) print(x->l, sz);
        //cout << x->v << ' ';

        if (x->r) print(x->r, sz + tz + 1);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    comb[0][0] = comb[1][0] = comb[1][1] = 1;
    for (int i = 2; i <= 10; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }

    ui n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];

    SplayTree st;
    st.init(n);


    cin >> m;
    while (m--) {
        int t;
        cin >> t;

        if (t == 1) {
            ui p, v;
            cin >> p >> v;
            st.add(p, v);
        }
        else if (t == 2) {
            ui p;
            cin >> p;
            st.rmv(p);
        }
        else if (t == 3) {
            ui p, v;
            cin >> p >> v;
            p++;
            st.kth(p);
            st.root->v = v;
            st.update(st.root);
        }
        else {
            ui l, r, k;
            cin >> l >> r >> k;
            l++, r++;

            Node* tmp = st.gather(l, r);
            st.push(tmp);
            cout << tmp->val[k] << '\n';
        }
    }
}

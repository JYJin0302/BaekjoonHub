#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int A[1010101];

struct Node {
    Node* l, * r, * p;
    int v, sz;
    int L[4], R[4], S[4];
    /*
    001 100 110 011

    */

    bool flip, rev;
    Node(ll _v, Node* p) : v(_v), p(p) {
        l = r = nullptr;
        S[0] = S[1] = S[2] = S[3] = 0;
        if (v == 1) {
            L[2] = L[3] = R[0] = R[1] = 1;
            L[0] = L[1] = R[2] = R[3] = 0;
        }
        else {
            L[0] = L[1] = R[2] = R[3] = 1;
            L[2] = L[3] = R[0] = R[1] = 0;
        }
        sz = 1, flip = 0, rev = 0;
    }
    Node(int _v) : Node(_v, nullptr) {}
    Node() : Node(0) {}
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }

    void pf() {
        cout << '{' <<  v << ' ' << sz << "}\n";
        for (int i = 0; i < 4; i++) {
            cout << L[i] << ' ' << R[i] << ' ' << S[i] << '\n';
        }
    }
};

struct SplayTree {
    Node* root;
    Node* ptr[1010101]; //node pointer
    int N;
    string pf;

    /*
    001 100 110 011
    */

    void update(Node* x) {
        x->sz = 1;
        x->S[0] = x->S[1] = x->S[2] = x->S[3] = 0;
        if (x->v == 1) {
            x->L[2] = x->L[3] = x->R[0] = x->R[1] = 1;
            x->L[0] = x->L[1] = x->R[2] = x->R[3] = 0;
        }
        else {
            x->L[0] = x->L[1] = x->R[2] = x->R[3] = 1;
            x->L[2] = x->L[3] = x->R[0] = x->R[1] = 0;
        }

        if (x->l) {
            push(x->l);
            x->sz += x->l->sz;

            x->S[0] += x->l->S[0];
            if (x->L[0] >= x->l->R[0]) {
                x->S[0] += x->l->R[0];
                x->L[0] = x->L[0] - x->l->R[0] + x->l->L[0];
            }
            else {
                x->S[0] += x->L[0];
                x->R[0] += x->l->R[0] - x->L[0];
                x->L[0] = x->l->L[0];
            }

            x->S[2] += x->l->S[2];
            if (x->L[2] >= x->l->R[2]) {
                x->S[2] += x->l->R[2];
                x->L[2] = x->L[2] - x->l->R[2] + x->l->L[2];
            }
            else {
                x->S[2] += x->L[2];
                x->R[2] += x->l->R[2] - x->L[2];
                x->L[2] = x->l->L[2];
            }

            x->S[1] += x->l->S[1];
            if (x->R[1] >= x->l->L[1]) {
                x->S[1] += x->l->L[1];
                x->R[1] = x->R[1] - x->l->L[1] + x->l->R[1];
            }
            else {
                x->S[1] += x->R[1];
                x->L[1] += x->l->L[1] - x->R[1];
                x->R[1] = x->l->R[1];
            }
            x->S[3] += x->l->S[3];
            if (x->R[3] >= x->l->L[3]) {
                x->S[3] += x->l->L[3];
                x->R[3] = x->R[3] - x->l->L[3] + x->l->R[3];
            }
            else {
                x->S[3] += x->R[3];
                x->L[3] += x->l->L[3] - x->R[3];
                x->R[3] = x->l->R[3];
            }
        }
        if (x->r) {
            push(x->r);
            x->sz += x->r->sz;

            x->S[0] += x->r->S[0];
            if (x->R[0] >= x->r->L[0]) {
                x->S[0] += x->r->L[0];
                x->R[0] = x->R[0] - x->r->L[0] + x->r->R[0];
            }
            else {
                x->S[0] += x->R[0];
                x->L[0] += x->r->L[0] - x->R[0];
                x->R[0] = x->r->R[0];
            }
            x->S[2] += x->r->S[2];
            if (x->R[2] >= x->r->L[2]) {
                x->S[2] += x->r->L[2];
                x->R[2] = x->R[2] - x->r->L[2] + x->r->R[2];
            }
            else {
                x->S[2] += x->R[2];
                x->L[2] += x->r->L[2] - x->R[2];
                x->R[2] = x->r->R[2];
            }

            x->S[1] += x->r->S[1];
            if (x->L[1] >= x->r->R[1]) {
                x->S[1] += x->r->R[1];
                x->L[1] = x->L[1] - x->r->R[1] + x->r->L[1];
            }
            else {
                x->S[1] += x->L[1];
                x->R[1] += x->r->R[1] - x->L[1];
                x->L[1] = x->r->L[1];
            }

            x->S[3] += x->r->S[3];
            if (x->L[3] >= x->r->R[3]) {
                x->S[3] += x->r->R[3];
                x->L[3] = x->L[3] - x->r->R[3] + x->r->L[3];
            }
            else {
                x->S[3] += x->L[3];
                x->R[3] += x->r->R[3] - x->L[3];
                x->L[3] = x->r->L[3];
            }
        }
    }

    void push(Node* x) { // lazy propagate
        if (x->flip) {
            // (() -> )((
            swap(x->l, x->r);
            for (int i = 0; i < 4; i+=2) {
                swap(x->S[i], x->S[i+1]);
                swap(x->L[i], x->L[i+1]);
                swap(x->R[i], x->R[i+1]);
            }
            if (x->l) x->l->flip = !x->l->flip;
            if (x->r) x->r->flip = !x->r->flip;
            x->flip = 0;
        }
        if (x->rev) {
            // (() -> ))(
            x->v *= -1;
            for (int i = 0; i < 2; i++) {
                swap(x->S[i], x->S[i + 2]);
                swap(x->L[i], x->L[i + 2]);
                swap(x->R[i], x->R[i + 2]);
            }
            if (x->l) x->l->rev = !x->l->rev;
            if (x->r) x->r->rev = !x->r->rev;
            x->rev = 0;
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

    void rev(int s, int e) {
        Node* x = gather(s, e);
        x->rev = !x->rev;
        splay(x);
    }

    void turn(int s, int e) {
        Node* x = gather(s, e);
        x->flip = !x->flip;
        x->rev = !x->rev;
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

    void print(Node* x, string dir = "") {
        push(x);
        if (x->l) print(x->l, dir+ 'L');
        if (dir != "") cout << dir << '\n';
        else cout << "Root\n";
        x->pf();
        if (x->v == 1) pf += '(';
        else pf += ')';
        if (x->r) print(x->r, dir + 'R');
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '(') A[i] = 1;
        else A[i] = -1;
    }

    SplayTree st;
    st.init(n);

    while (m--) {

        int t, l, r;
        cin >> t >> l >> r;

        switch (t) {
        case 1:
            st.rev(l, r);
            break;
        case 2:
            st.flip(l, r);
            break;
        case 3:
            st.turn(l, r);
            break;
        case 4:
            Node * tmp = st.gather(l, r);
            st.push(tmp);
            cout << tmp->S[0] << '\n';
            break;
        }

        /*st.pf = "";
        st.print(st.root);
        cout << st.pf << '\n';*/
    }

}

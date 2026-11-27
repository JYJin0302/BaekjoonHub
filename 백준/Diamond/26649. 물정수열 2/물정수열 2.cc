#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;

#define mp make_pair

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Node {
    Node* l, * r, * p;
    ll v, lazy;

    Node(ll _v, Node* p) : v(_v), p(p) {
        l = r = nullptr;
        lazy = 0;
    }
    Node(int _v) : Node(_v, nullptr) {}
    Node() : Node(0) {}
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }
};

int dp[101010];

struct SplayTree {
    Node* root;
    int N;

    void push(Node* x) { // lazy propagate
        if (x->lazy == 0) return;
        x->v += x->lazy;
        if (x->l) x->l->lazy += x->lazy;
        if (x->r) x->r->lazy += x->lazy;
        x->lazy = 0;
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
    }

    void splay(Node* x, Node* g = nullptr) {
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
    }

    SplayTree() : root() {
    }
    ~SplayTree() {
        if (root) delete root;
    }

    void init(int n) {
        if (root) delete root;
        N = 1;
        root = new Node(dp[1]);
    }

    bool find(int k) {
        // k이상의 값이 나오는 가장 왼쪽 지점을 root로 바꿈
        Node* now = root;
        Node* res = nullptr;
        push(now);
        while (now) {
            if (now->v < k) {
                if (now->r) now = now->r;
                else break;
            }
            else {
                res = now;
                if (now->l) now = now->l;
                else break;
            }
            push(now);
        }
        if (res) {
            splay(res);
            return 1;
        }
        splay(now);
        return 0;
    }

    vector<int> res;

    void print(Node* x) {
        if (x == root) res.clear();

        push(x);
        if (x->l) print(x->l);
        //cout << x->v << " ";
        res.push_back(x->v);
        if (x->r) print(x->r);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;
    for (auto& i : C) cin >> i;

    vector<pair<int, int>> P(n);
    for (int i = 0; i < n; i++) {
        P[i].first = min({ A[i], B[i], C[i] });
        P[i].second = max({ A[i], B[i], C[i] });
    }

    dp[1] = P[0].first;
    SplayTree st;
    st.init(1);

    for (int i = 1; i < n; i++) {

        int L, R;
        tie(L, R) = P[i];

        // L 이상의 값이 처음 나오는 곳 -> p1
        // R 이상의 값이 나오는 곳 -> p2
        // ______1abcde2_____  ->
        // ______L1abcde_____
        //       +111111

        if (!st.find(L)) {
            if (st.root->v < L) {
                st.root->r = new Node(L, st.root);
                st.N++;
            }
            continue;
        }
        Node* tmp = st.root;

        bool t = st.find(R);
        st.push(st.root);

        if (st.root->v < tmp->v) {
            continue;
        }

        if (t) {
            // delete root

            if (tmp == st.root) {
                st.root->v = L;
                continue;
            }
            
            Node* t1 = st.root->l;
            Node* t2 = st.root->r;

            if (t1) {
                t1->lazy++;
                st.push(t1);
            }

            if (!t1) {
                st.root = st.root->r;
                st.root->p = nullptr;
            }
            else if (!t2) {
                st.root = st.root->l;
                st.root->p = nullptr;
            }
            else {
                t1->p = nullptr;
                t2->p = nullptr;

                while (t1->r) {
                    st.push(t1);
                    t1 = t1->r;
                }
                st.push(t1);
                st.splay(t1);

                while (t2->l) {
                    st.push(t2);
                    t2 = t2->l;
                }
                st.push(t2);
                st.splay(t2);

                t1->p = t2;
                t2->l = t1;
                st.root = t2;
            }
        }
        else {
            st.N++;
            st.root->lazy++;
            st.push(st.root);
        }

        st.splay(tmp);
        st.push(st.root);
        if (st.root->l) {
            st.root->l->lazy--;
            st.push(st.root->l);

            Node* tmp = new Node(L);

            st.root->l->p = tmp;
            tmp->l = st.root->l;
            
            st.root->l = nullptr;
            st.root->p = tmp;
            tmp->r = st.root;

            st.root = tmp;
        }
        else {
            Node* tmp = new Node(L);
            st.root->p = tmp;
            tmp->r = st.root;
            st.root = tmp;
        }
    }


    cout << st.N << '\n';
}
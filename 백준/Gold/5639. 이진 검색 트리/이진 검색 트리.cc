#include <bits/stdc++.h>
using namespace std;

struct Node {
    
    map<int, Node> child;
    int v = -1;
    bool l = 0, r = 0;
};
Node root;

void insert(Node& n, int x) {

    if (n.v == -1) {
        n.v = x;
    }
    else if (n.v < x) {
        n.r = 1;
        insert(n.child[1], x);
    }
    else {
        n.l = 1;
        insert(n.child[0], x);
    }
}

void display(Node& n) {
    if (n.l) display(n.child[0]);
    if (n.r) display(n.child[1]);
    cout << n.v << '\n';
}

int main() {

    int x;
    while (cin >> x) {
        insert(root, x);
    }

    display(root);
}
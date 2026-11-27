#include <bits/stdc++.h>
using namespace std;

struct Node {
    map<char, Node> child;
};

Node root;

void insert(Node& n, string s, int i = 0) {
    if (i == s.size()) return;
    insert(n.child[s[i]], s, i + 1);
}

int search(Node& n, string s, int i = 0) {
    if (i == s.size()) return 0;

    if (n.child.size() == 1) return search(n.child[s[i]], s, i + 1);
    return search(n.child[s[i]], s, i + 1) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cout << fixed << setprecision(2);
    while (cin >> n) {
        root = Node();
        vector<string> A(n);
        for (auto& i : A) cin >> i;

        for (string s : A) {
            insert(root, s + '\0');
        }

        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            cnt[i] = search(root.child[A[i][0]], A[i], 1);
        }

        int tot = n;
        for (int i : cnt) tot += i;

        cout << (double)tot / n << '\n';
    }
}
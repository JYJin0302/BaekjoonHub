#include <bits/stdc++.h>
using namespace std;

struct Node {
    map<char, Node> child;
    bool used = 0;
};

Node root;

void insert(Node& n, string s, int i = 0) {
    if (i == s.size()) return;

    n.child[s[i]].used = 1;
    insert(n.child[s[i]], s, i + 1);
}

void search(Node& n, string s, int i = 0) {
    if (i == s.size()) {
        cout << '\n';
        return;
    }

    cout << s[i];
    if (n.child[s[i]].used == 1) {
        search(n.child[s[i]], s, i + 1);
    }
    else {
        n.child[s[i]].used = 1;
        cout << '\n';
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n;
    cin >> n;

    map<string, int> cnt;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        cnt[s]++;
        if (cnt[s] != 1) cout << s << cnt[s] << '\n';
        else {
            search(root, s);
        }
        insert(root, s);
    }
}
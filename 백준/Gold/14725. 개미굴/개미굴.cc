#include <bits/stdc++.h>
using namespace std;

struct Node {
    map<string, Node> child;
};

Node root;
vector<vector<string>> inp;

void insert(Node& curr, int i, int j) {
    if (j == inp[i].size()) return;
    string s = inp[i][j];
    insert(curr.child[s], i, j + 1);
}

void display(Node& curr, int dep = 0) {

    for (auto i : curr.child) {

        string t(dep * 2, '-');
        cout << t << i.first << '\n';
        display(i.second, dep + 1);
    }
}

int main() {

    int n;
    cin >> n;

    inp = vector<vector<string>> (n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<string> temp(k);
        for (auto& i : temp) cin >> i;
        inp[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        insert(root, i, 0);
    }

    display(root);
}
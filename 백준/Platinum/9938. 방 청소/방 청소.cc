#include<bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int n) {
    if (root[n] == n) return n;

    return root[n] = find(root[n]);
}



int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n, l;
    cin >> n >> l;

    root = vector<int>(l + 1);
    for (int i = 1; i <= l; i++) root[i] = i;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        find(a), find(b);
        if (root[a] == a) {
            cout << "LADICA\n";
            if (root[a] != root[b]) root[a] = root[b];
            else root[a] = 0;
        }
        else if (root[b] == b) {
            cout << "LADICA\n";
            if (root[b] != root[a]) root[b] = root[a];
            else root[b] = 0;
        }
        else if (root[a] != 0) {
            cout << "LADICA\n";
            if (root[root[a]] != root[b]) root[root[a]] = root[b];
            else root[root[a]] = 0;
        }
        else if (root[b] != 0) {
            cout << "LADICA\n";
            if (root[a] != root[root[b]]) root[root[b]] = root[a];
            else root[root[b]] = 0;
        }
        else{
            cout << "SMECE\n";
        }
    }
}
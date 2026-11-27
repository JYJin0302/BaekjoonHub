#include <bits/stdc++.h>
using namespace std;


struct Node{
    int l = -1, r = -1;
    int p = 0;
};

vector<Node> tree;
int dep[10001];
int mval[10001];
int Mval[10001];

int val = 0;

void dfs(int v){
    
    if (tree[v].l != -1) {
        dep[tree[v].l] = dep[v] + 1;
        dfs(tree[v].l);
    }
    
    mval[dep[v]] = min(mval[dep[v]], val);
    Mval[dep[v]] = max(Mval[dep[v]], val);
    val++;
    
    if (tree[v].r != -1) {
        dep[tree[v].r] = dep[v] + 1;
        dfs(tree[v].r);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
        
    int n;
    cin >> n;
    
    tree = vector<Node> (n+1);
    for(int i = 0; i < n; i++){
        
        int a, b, c;
        cin >> a>> b >> c;
        
        tree[a].l = b;
        tree[a].r = c;
        if (b != -1) tree[b].p = a;
        if (c != -1) tree[c].p = a;
    }
    
    memset(mval, 10001, sizeof(mval));
    memset(Mval, -1, sizeof(Mval));
    
    int root = 1;
    while(tree[root].p != 0) root = tree[root].p;
    
    dfs(root);
    
    int ai = 0, av = 0;
    int h = 0;
    while(Mval[h] != -1){
        int ta = Mval[h] - mval[h] + 1;
        if (av < ta){
            av = ta;
            ai = h+1;
        }
        h++;
    }
    cout << ai << ' ' << av;
}
#include <bits/stdc++.h>
using namespace std;

int ans = 0;

struct Node{
    bool is = 0;
    map<int, Node> child;
} root;

void insert(Node& n, int x, int pos = 29){
    if (x & ( 1 << pos)){
        n.child[1].is = 1;
        if (pos > 0) insert(n.child[1], x, pos-1);
    }
    else{
        n.child[0].is = 1;
        if (pos > 0) insert(n.child[0], x, pos-1);
    }
}

void search(Node& n, int x, int pos = 29){
    bool b = x & (1 << pos);
    if (n.child[1-b].is){
        x |= (1 << pos);
        if(pos > 0) search(n.child[1-b], x, pos-1);
        else ans = max(ans, x);
    }
    else{
        x &= ~(1 << pos);
        if(pos > 0) search(n.child[b], x, pos-1);
        else ans = max(ans, x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    for (int i : A){
        insert(root, i);
    }
    
    for (int i : A) search(root, i);
    cout << ans;
}
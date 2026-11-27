#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

struct Node{
    Node* fail;
    Node* nxt[26];
    string state;
    bool isEnd;
    int len, dep;
    Node(){
        fail = nullptr;
        for(int i =0 ; i < 26; i++) nxt[i] = nullptr;
        isEnd = 0;
        len = 0;
        dep = 0;
    }
    ~Node(){
        for(int i = 0 ; i< 26; i++) delete nxt[i];
    }
} *root;

string tmp;
void insert(Node* cur, int idx){
    if (idx == (int)tmp.size()){
        cur->isEnd = 1;
        cur->len = cur->dep;
        return;
    }

    int nx = tmp[idx] - 'a';
    if(!cur->nxt[nx]){
        cur->nxt[nx] = new Node();
        cur->nxt[nx]->dep = cur->dep + 1;
    }
    insert(cur->nxt[nx], idx+1);
}

void solve(){
    
    string s;
    cin >> s;

    string ts;
    for(auto f : s) {
        ts += f;
        ts += '.';
    }

    int n = (int)ts.size();
    vector<int> M(n+1);
    M[0] = 1;
    int c = 0, r = 0;
    for(int i = 1; i < n; i++){
        if(i <= r) M[i] = min(r-i, M[c*2-i]);
        while(i + M[i] < n && i - M[i] >= 0 && ts[i+M[i]] == ts[i-M[i]]) M[i]++;
        if (i + M[i] - 1 > r){
            c = i, r = i+M[i]-1;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if (i & 1){
            ans = max(ans, M[i] - M[i] % 2);
        }
        else{
            ans = max(ans, M[i] - (M[i] % 2 ? 0 : 1));
        }
    }
    cout << ans << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

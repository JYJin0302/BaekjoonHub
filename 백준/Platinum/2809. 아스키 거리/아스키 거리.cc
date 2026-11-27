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

    int n;
    cin >> n;
    string s;
    cin >> s;

    int k;
    cin >> k;
    vector<string> inp;
    for(int i =0 ;i  < k; i++){
        cin >> tmp;
        inp.push_back(tmp);
    }

    vector<int> rec(n+1);
    queue<Node*> q;

    for(int i = 0; i < k; i += 200){
        
        root = new Node();
        for(int j = i; j < min(k, i+200); j++){
            // insert
            tmp = inp[j];
            insert(root, 0);
        }

        root->fail = root;
        q.push(root);
        while(!q.empty()){
            Node* f = q.front(); q.pop();

            for(int i =0  ;i < 26; i++){
                if(!f->nxt[i]) continue;

                if (f == root) {
                    f->nxt[i]->fail = root;
                }
                else{
                    Node* tt = f->fail;
                    while(tt != root && !tt->nxt[i]) tt = tt->fail;
                    if (tt->nxt[i]) tt = tt->nxt[i];
                    f->nxt[i]->fail = tt;
                }

                f->nxt[i]->len = max(f->nxt[i]->len, f->nxt[i]->fail->len);
                q.push(f->nxt[i]);
            }
        }

        Node* cur = root;
        //cout << "Go serach " << endl;
        for(int f = 0; f < n; f++){
            int cx = s[f] - 'a';
            while(cur != root && !cur->nxt[cx]) cur = cur->fail;
            if (cur->nxt[cx]){
                cur = cur->nxt[cx];
            }

            if (cur->len){
                int len = cur->len;
                rec[f-len+1]++;
                rec[f+1]--;
                //cout << "Found: " << f-len+1 << ' ' << f << '\n';
            }
        }

        delete root;
    }

    

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i) rec[i] += rec[i-1];
        if (rec[i] == 0) ans++;
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

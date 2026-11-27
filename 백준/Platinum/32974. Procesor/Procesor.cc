#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct Node{
    Node* l, *r;

    int winner = -1;
    int depth = 0;

    Node(int idx = -1){
        l = nullptr;
        r = nullptr;
        winner = idx;
        depth = 0;
    }
};

Node* match(Node* l, Node* r){
    cout << "? "<< l->winner << ' ' << r->winner << endl;

    int res;
    cin >> res;
    Node* ret;
    if (res == 0){
        ret = new Node(l->winner);
    }
    else{
        ret = new Node(r->winner);
    }
    ret->l = l;
    ret->r = r;
    ret->depth = max(l->depth, r->depth) + 1;
    return ret;
}

// void pf(Node* root){
//     queue<Node*> q, tq;
//     q.push(root);
//     while(!q.empty()){
//         while(!q.empty()){
//             auto f= q.front(); q.pop();
//             cout << f->winner << "  ";

//             if (f->l) tq.push(f->l);
//             if (f->r) tq.push(f->r);
//         }
//         cout << '\n';
//         swap(q, tq);
//     }
// }

void solve(){
    int q;
    cin >> q;

    int pre = 0;
    vector<Node*> R; // remaining

    while(q--){
        int n;
        cin >> n;

        // n element added
        // pre + 1, pre + 2, ..., pre + n

        queue<Node*> q;
        for(int i = 0; i <n ;i++){
            pre++;
            q.push(new Node(pre));
        }

        while(1){
            if(!R.empty()){
                if ((int)q.size() < 2 || q.front()->depth == R.back()->depth){
                    int cc = R.back()->depth;
                    while(!R.empty() && R.back()->depth == cc){
                        q.push(R.back());
                        R.pop_back();
                    }
                }
            }
            if(q.size() == 1) break;

            int cc = (int)q.size() / 2;
            while(cc--){
                auto a =q.front(); q.pop();
                auto b =q.front(); q.pop();
                Node* c = match(a, b);
                q.push(c);
            }
        }

        Node* root = q.front(); q.pop();


        // cout << "State: " << endl;
        // pf(root);
        // cout << endl;

        cout << "! " << root->winner << endl;
        int W = root->winner;

        // Process
        while(1){
            if (!root->l) break;
            
            if (root->l->winner == W){
                R.push_back(root->r);
                root = root->l;
            }
            else{
                R.push_back(root->l);
                root = root->r;
            }

            int sn = (int)R.size();
            for(int i = sn-1; i; i--){
                if (R[i]->depth > R[i-1]->depth){
                    swap(R[i], R[i-1]);
                }
                else break;
            }
        }
    }
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}

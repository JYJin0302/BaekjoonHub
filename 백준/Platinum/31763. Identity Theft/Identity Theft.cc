#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct CMP{
    bool operator()(const array<int, 3>& a, const array<int, 3>& b) const {
        int c1 = a[0] + (a[1] == 1 ? 2 : 0);
        int c2 = b[0] + (b[1] == 1 ? 2 : 0);
        if(c1 != c2) return c1 < c2;
        return a < b;
    }
};

struct Node{
    int dep = 0;
    int cnt = 0;
    int idx = -1;
    Node* l, * r;
    Node(){
        l = r = nullptr;
        dep = cnt = 0;
        idx = -1;
    }
}*D[1000010];

set<array<int, 3>, CMP> st[1000010]; // dep, type, cnt. T0: 비활성화, T1: 활성화
int o = 0;

string ss;
void insert(Node* cur, int idx = 0){
    if (idx == (int)ss.size()) {
        cur->cnt++;
        return;
    }
    
    int v = ss[idx] - '0';
    if (v == 0){
        if (!cur->l){
            cur->l = new Node();
            cur->l->dep = cur->dep + 1;
            cur->l->idx = ++o;
            D[o] = cur->l;
        }
        insert(cur->l, idx+1);
    }
    else{
        if (!cur->r){
            cur->r = new Node();
            cur->r->dep = cur->dep + 1;
            cur->r->idx = ++o;
            D[o] = cur->r;
        }
        insert(cur->r, idx+1);
    }
}

void insertSt(set<array<int ,3>, CMP>* ss, array<int ,3> v){
    auto iter = ss->lower_bound({v[0], v[1], -1});
    if(iter != ss->end() && (*iter)[0] == v[0] && (*iter)[1] == v[1]){
        v[2] += (*iter)[2];
        ss->erase(iter);
    }
    ss->insert(v);
}

void solve(){
    
    int n;
    cin >> n;

    vector<string> A(n);
    for(auto& i : A) cin >> i;

    ll ans = 0;
    for(auto f : A) ans += (int)f.size();
    ans *= -1;

    Node* root = new Node();
    D[0] = root;
    root->idx = 0;
    
    for(auto f: A){   
        ss = f;   
        insert(root);
    }
    vector<pair<int, int>> g;
    for(int i = 1; i <= o; i++){
        g.push_back(mp(D[i]->dep, i));
    }
    sort(all(g));
    reverse(all(g));

    for(auto f: g){
       // cout << "Cur: " << D[f.y]->idx << " | " << D[f.y]->cnt << ' ' << D[f.y]->dep << '\n';

        int cur = f.y;
        if (!D[cur]->l && !D[cur]->r){
            // leaf
            insertSt(&st[cur], {D[cur]->dep, 0, 1});
        }
        else{
            if (!D[cur]->l){
                insertSt(&st[cur], {D[cur]->dep+1, 0, 1});
            }
            else{
                int ix = D[cur]->l->idx;
                if (st[cur].size() < st[ix].size()) swap(st[cur], st[ix]);
                for(auto f : st[ix]) insertSt(&st[cur], f);
            }
            if (!D[cur]->r){
                insertSt(&st[cur], {D[cur]->dep+1, 0, 1});
            }
            else{
                int ix = D[cur]->r->idx;
                if (st[cur].size() < st[ix].size()) swap(st[cur], st[ix]);
                for(auto f : st[ix]) insertSt(&st[cur], f);
            }
        }

       // cout << "Cur set: " << D[cur]->cnt << " => ";
       // for(auto f :st[cur]) cout << f[0] << ' '<< f[1] << ' ' << f[2] << " || ";
       // cout << '\n';

        int cc = D[cur]->cnt;
        while(cc){
            auto f = st[cur].begin();

            int dep = (*f)[0];
            int type = (*f)[1];
            int cnt = (*f)[2];
            st[cur].erase(f);

            int mm = min(cc, cnt);
            cc -= mm;
           // cout << "used; " << dep << ' ' << type << " | " << mm << '\n';
            if (type == 0){
                ans += 1ll * mm * dep;
                insertSt(&st[cur], {dep, 1, mm});
            }
            else{
                ans += 1ll * mm * (2 + dep);
                insertSt(&st[cur], {dep + 1, 1, mm * 2});
            }

            
            if (cnt != mm){
                insertSt(&st[cur],  {dep, type, cnt - mm});
            }
        }
    }

    cout << ans << '\n';

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

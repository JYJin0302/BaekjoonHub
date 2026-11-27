#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pii;
#define mp make_pair

struct seg2d{

    struct Node{
        int v, l, r;
        Node(){
            v = -202020;
            l = r = 0;
         }
    };

    int M, N, sz=  2;
    vector<int> L, R;
    vector<Node> t;
    vector<vector<Node>> seg;

    seg2d(int N, int M):N(N), M(M){
        L.resize(2);
        R.resize(2);
        t.resize(2);
        seg.resize(2, t);
        seg.reserve(10000000);
    }

    void upd1(int x, int val, int l, int r, int ny, int nx){
        if (l==r){
            seg[ny][nx].v = val;
            return;
        }
        seg[ny][nx].v = max(seg[ny][nx].v, val);
        int mid =(l+r)>>1;
        if (x <= mid){
            if(seg[ny][nx].l == 0){
                seg[ny].push_back(Node());
                seg[ny][nx].l = seg[ny].size() - 1;
            }
            upd1(x, val, l, mid, ny, seg[ny][nx].l);
        }else{
            if (seg[ny][nx].r == 0){
                seg[ny].push_back(Node());
                seg[ny][nx].r = seg[ny].size() - 1;
            }
            upd1(x, val, mid+1, r, ny, seg[ny][nx].r);
        }

    }

    void upd2(int y, int x, int val, int l, int r, int ny){

        upd1(x, val, 0, N, ny, 1);
        if(l == r) return;

        int mid = (l+r)>>1;
        if (y <= mid){

            if(L[ny] == 0){
                seg.push_back(t);
                L.push_back(0);
                R.push_back(0);
                ++sz;
                L[ny] = sz-1;
            }
            upd2(y, x, val, l, mid, L[ny]);

        }else{

            if(R[ny] == 0){
                seg.push_back(t);
                L.push_back(0);
                R.push_back(0);
                ++sz;
                R[ny] = sz-1;
            }
            upd2(y, x, val, mid+1, r, R[ny]);

        }

    }

    int query1(int x1, int x2, int l, int r, int ny, int nx){
        if (ny == 0 || nx == 0)return -202020;
        if (x2 < l || r <x1) return -202020;
        if(x1 <= l && r <= x2) return seg[ny][nx].v;

        int mid = (l+r)>>1;
        return max(query1(x1, x2, l, mid, ny, seg[ny][nx].l),query1(x1, x2, mid+1, r, ny, seg[ny][nx].r));
    }

    int query2(int y1,  int y2, int x1, int x2, int l, int r, int ny){
        if (ny == 0 )return -202020;
        if (y2 < l || r <y1) return -202020;
        if(y1 <= l && r <= y2) return query1(x1, x2, 0, N, ny, 1);

        int mid = (l+r)>>1;
        return max(query2(y1, y2, x1, x2, l, mid, L[ny]),query2(y1, y2, x1, x2, mid+1, r, R[ny]));
    }

    void update(int y, int x, int val){
        upd2(y, x, val, 0, N, 1);
    }

    int query(int y1, int x1, int y2, int x2){
        return query2(y1, y2, x1, x2, 0, N, 1);
    }

};

vector<ll> posx, posy;
int getX(ll x){
    return lower_bound(posx.begin(), posx.end(), x) - posx.begin();
}
int getY(ll x){
    return lower_bound(posy.begin(), posy.end(), x) - posy.begin();
}

void solve(){

    ll n, v;
    cin >> n >> v;

    vector<ll> t(n), a(n);
    for(auto &i :t)cin >> i;
    for(auto &i : a)cin >>i;

    for(int i = 0; i < n ;i++){
        posx.push_back(-a[i] + t[i]*v);
        posy.push_back(a[i] + t[i]*v);
    }
    posx.push_back(0);
    posy.push_back(0);

    sort(posx.begin(), posx.end());
    posx.erase(unique(posx.begin(), posx.end()), posx.end());
    sort(posy.begin(), posy.end());
    posy.erase(unique(posy.begin(), posy.end()), posy.end());
    /*
    cout <<"RES;\n";
    for(auto f :posx)cout << f <<' ' ;
    cout <<'\n';for(auto f :posy)cout << f <<' ' ;
    cout <<'\n';*/

    int ans = 0;
    seg2d Seg(n, n);
    Seg.update(getX(0), getY(0), 0);
    for(int i = 0; i < n; i++){
        ll nx = getX(-a[i] + t[i]*v);
        ll ny = getY(a[i] +t[i]*v);

        int val = Seg.query(0, 0, nx, ny);
        ans = max(ans, val+1);

       // cout << "Get:"<< nx <<' ' <<ny <<": "<<val <<'\n';
        if (val >= 0){
            Seg.update(nx, ny, val+1);
        }
    }

    cout <<ans <<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int t=1;
//    cin >>t;
    while(t--){
        solve();
    }
}

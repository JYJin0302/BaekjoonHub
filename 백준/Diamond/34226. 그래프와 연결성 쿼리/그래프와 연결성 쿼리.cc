#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int b = 350;
int n, m, q;

pair<int, int> edg[101010];
pair<int, int> qur[101010];

int root[101010];
int find(int n){
    if (root[n] == n) return n;
    return find(root[n]);
}
ll sz[101010];

ll ans = 0;
vector<pair<int, int>> rec;
bool merge(int u, int v){
    int tu = find(u);
    int tv = find(v);
    if (tu == tv) return 0;
    if (sz[tu] > sz[tv]) swap(tu, tv);

    ans += sz[tv] * sz[tu];
    sz[tv] += sz[tu];
    root[tu] = tv;
    rec.push_back(mp(tu, tv));
    return 1;
}

void rollback(){
    assert(!rec.empty());
    auto[a,b] = rec.back(); rec.pop_back();
    sz[b] -= sz[a];
    ans -= sz[b] * sz[a];
    root[a] = a;
}

void solve() {
    cin >> n >> m >> q;

    for(int i = 0; i < m;i++){
        int a, b;
        cin >> a>> b;
        edg[i] = mp(a, b);
    }

    vector<int> type2;
    vector<array<int ,3>> type1;
    for(int i =0 ;  i<q ; i++){
        int l, r;
        cin >> l >> r;

        l--, r--;
        qur[i] = mp(l, r);

        int tl = l / b;
        if (l % b != 0) tl++;

        int tr = r / b;
        if(r % b != b-1) tr--;

        if (tl > tr){
            type2.push_back(i);
        }
        else {
            type1.push_back({tl * b, (tr + 1) * b - 1, i});
        }
    }
    sort(all(type1));

    for(int i = 1; i <= n; i++) sz[i] = 1, root[i] = i;

    vector<ll> res(q);
    // go type2
    for(auto f : type2){
        int l = qur[f].x, r = qur[f].y;
        int cnt = 0;
        for(int i = l; i <= r; i++){
            auto [u,v] = edg[i];
            cnt += merge(u, v);
        }
        res[f] = ans;
        while(cnt--) rollback();

    }


    // go type1
    int ix = 0;
    int ss = (int)type1.size();
    while(ix < ss){
        int nx = ix;
        while(nx < ss && type1[nx][0] == type1[ix][0]) nx++;

        int l = type1[ix][0];
        for(int r = l; r < m; r++){
            auto[u,v] = edg[r];
            merge(u, v);

            while(ix < nx && type1[ix][1] == r){

                int idx = type1[ix][2];
                // process query
                auto[tl, tr] = qur[idx];

                int cnt = 0;
                for(int i = l-1; i >= tl; i--){
                    auto[u, v] = edg[i];
                    cnt += merge(u, v);
                }
                for(int i = r + 1; i <= tr; i++){
                    auto[u, v] = edg[i];
                    cnt += merge(u, v);
                }

                res[idx] = ans;

                while(cnt--){
                    rollback();
                }

                ix++;
            }
        }

        while(!rec.empty()){
            rollback();
        }
    }

    for(auto f: res) cout <<f << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
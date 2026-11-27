#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

// bool cmp(pair<int, int>& p1, pair<int, int>& p2){
//     return p1.x * p2.y > p1.y * p2.x;
// }

struct P{
    ll x, y;
    int idx;

    bool operator<(P& o){
        if (x * o.y == y * o.x){
            return x*x + y*y < o.x*o.x + o.y*o.y;
        }
        return x * o.y > y * o.x;
    }

};

ll ccw(P& p1, P& p2, P& p3){
    ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    return res;
}
void solve(){
    
    int n, m;
    cin >> n >> m;
    
    vector<P> A(n), B(m);
    
    int xi = n, yi = n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        A[i] = {a, b, i};
        if (a == 0 && yi == n) yi = i;
        if (b == 0 && xi == n) xi = i;
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        B[i] = {a, b, i};
    }


    ll mx = 0, my = 0;
    for(int i = 0; i < n; i++){
        mx = max(mx, A[i].x);
        my = max(my, A[i].y);
    }

    A.push_back({mx, 0, n + 1});
    A.push_back({0, my, n+1});

    sort(all(A));
    sort(all(B));

    vector<P> nA;
    for(int i = 0; i < n + 2; i++){
        if (A[i].x < mx && A[i].y == 0) continue;
        if (A[i].y < my && A[i].x == 0) continue;

        if (nA.empty() || nA.back().x != A[i].x || nA.back().y != A[i].y){
            nA.push_back(A[i]);
        }
        else nA.back().idx = min(nA.back().idx, A[i].idx);
    }
    swap(nA, A);
    n = A.size();
    A.push_back({0 ,0, n+1});
    // for(int i = 0; i < m; i++) cout << B[i].x<< ' '<< B[i].y << " | "  << B[i].idx << '\n';
    
    //cout << "A: \n";
   // for(auto f : A) cout << f.x << ' '<< f.y << " | " << f.idx << '\n';
    vector<P> H;
    H.push_back({0, 0, n+1});
    for(int i = 0; i <= n; i++){
        while(H.size() >= 2){
            P p2 = H.back(); H.pop_back();
            P p1 = H.back();

            ll res = ccw(p1, p2, A[i]);
            if (res >= 0){
                // ok
                H.push_back(p2);
                break;
            }
            else if (res < 0){
                continue;
            }
        }
        H.push_back(A[i]);
    }

    //for(auto f : H) cout << f.x << ' ' << f.y << '\n';

    set<int> cur;

    int l = 1, r = 1;
    cur.insert(H[1].idx);
    vector<int> ans(m);
    for(int i = 0; i < m; i++){
        ll a = B[i].x;
        ll b = B[i].y;

        while(l < r){
            ll valL = H[l].x * a + H[l].y * b;
            ll valR = H[r].x * a + H[r].y * b;
            if (valL < valR) {
                cur.erase(cur.find(H[l].idx));
                l++;
            }
            else break;
        }

        while(r < H.size()){
            int tr = r + 1;
            if (tr >= H.size() - 1) break;

            ll tv = H[tr].x * a + H[tr].y * b;
            ll curV = H[l].x * a + H[l].y * b;
            if (tv > curV){
                cur.clear();
                l = tr;
                r = tr;
                cur.insert(H[l].idx);
                continue;
            }
            if (tv == curV){
                r++;
                cur.insert(H[r].idx);
                continue;
            }
            break;
        }

        //cout << "Go: " << a << ' '<< b << " | " << l << ' ' << r << '\n';

        ans[B[i].idx] = *cur.begin();

        ll val = H[l].x * a + H[l].y * b;
        if(val == 0){
            if(a == 0) ans[B[i].idx] = min(ans[B[i].idx], xi);
            else if (b == 0) ans[B[i].idx] = min(ans[B[i].idx], yi);
        }
    }

    for(auto f : ans) cout << f + 1 << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
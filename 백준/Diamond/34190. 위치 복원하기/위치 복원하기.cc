#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
int ans[101010];
int cal1(int d1, int d2){
    // 1 - v, 2 - v
    if (abs(ans[2] - d1) == d2) return d1;
    assert(abs(ans[2] + d1) == d2);
    return -d1;
} 
 
pair<int, int> cal2(int d1, int d2, int d3){
    // 1 - v, 2 - u, v -- u
 
    vector<pair<int, int>> res;
 
    for(auto v1 : {-d1, d1}){
        for(auto v2 : {ans[2] - d2, ans[2] + d2}){
            if (abs(v1 - v2) == d3) res.push_back(mp(v1, v2));
        }
    }
 
    assert((int)res.size() == 1);
    return res[0];
}
 
 
void solve() {
 
    int n;
    cin >> n;
 
 
 
    // ans[1] = 0;
    cout << "? 1 2" << endl;
    cin >> ans[2];
 
    if(n % 2 == 1){
        int d1, d2;
        cout << "? 1 " << n << endl;
        cin >> d1;
        cout << "? 2 " << n << endl;
        cin >> d2;
 
        ans[n] = cal1(d1, d2);
    }
 
    vector<pair<int, int>> D1, D2;
 
    for(int i = 3; i < n; i += 2){
        int d1, d2;
        cout << "? 1 " << i << endl;
        cin >> d1;
        cout << "? 2 " << i+1 << endl;
        cin >> d2;
 
        D1.push_back(mp(d1, i));
        D2.push_back(mp(d2, i+1));
    }
    sort(all(D1));
    sort(all(D2));
 
    // for(auto [a,b] : D1) cout << a<< ' ' << b << " | ";
    // cout << '\n';
    // for(auto [a,b] : D2) cout << a<< ' ' << b << " | ";
    // cout << '\n';
 
    int sn = (int)D1.size();
    vector<bool> done(sn);
 
    vector<int> mul;
    for(int i = 0; i < sn; i++){
        if (D1[i].x == D2[i].x){
            mul.push_back(i);
        }
    }
 
    int pre = -1;
    for(int i = 0; i < (int)mul.size();){
        if (i+1 < (int)mul.size()){
            int i1= mul[i], i2 = mul[i+1];
            if (D1[i1].x == D2[i2].x){
                // pair
                done[i1] = 1;
                done[i2] = 1;
 
                int u = D1[i1].y;
                int v = D1[i2].y;
 
                //cout << "Go pair: " << u << ' ' << v << '\n';
                int d;
                cout << "? 2 " << u << endl;
                cin >> d;
 
                ans[u] = cal1(D1[i1].x, d);
                ans[v] = -ans[u];
 
                u = D2[i1].y;
                v = D2[i2].y;
                //cout << "Go pair: " << u << ' ' << v << '\n';
                cout << "? 1 " << u << endl;
                cin >> d;
                ans[u] = cal1(d, D2[i1].x);
                ans[v] = 2 * ans[2] - ans[u];
 
                i += 2;
            }
            else{
                if (pre != -1){
                    //swap()
                    int i1= mul[pre];
                    int i2 = mul[i];
                    swap(D2[i1], D2[i2]);
                }
                pre = i;
                i++;
            }
        }
        else{
            if (pre != -1){
                //swap()
                int i1= mul[pre];
                int i2 = mul[i];
                swap(D2[i1], D2[i2]);
            }
            pre = i;
            i++;
        }
    }
 
    if (pre != -1){
        int ix = mul[pre];
        if (D1[ix].x == D2[ix].x){
            // process
            int u = D1[ix].y;
            int v = D2[ix].y;
 
            int d;
            cout << "? 2 " << u << endl;
            cin >> d;
 
            ans[u] = cal1(D1[ix].x, d);
 
            cout << "? 1 " << v << endl;
            cin >> d;
            ans[v] = cal1(d, D2[ix].x);
            done[ix] = 1;
        }
    }
 
    for(int i = 0 ;i < sn; i++){
        if (done[i]) continue;
 
        int u = D1[i].y;
        int v = D2[i].y;
 
        int d1 = D1[i].x;
        int d2 = D2[i].x;
        int d3;
        cout << "? " << min(u, v) << ' ' << max(u, v) << endl;
        cin >> d3;
 
        pair<int, int> res = cal2(d1,d2,d3);
 
        ans[u] = res.x;
        ans[v] = res.y;
    }
 
    cout << "! ";
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
 
 
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

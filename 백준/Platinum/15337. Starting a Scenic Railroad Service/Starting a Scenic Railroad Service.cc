#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, maxn = 100010;
int segL[202020], segR[202020];

void update(int ix, int val, int seg[]){
    for( ; ix <= maxn; ix += ix & -ix) seg[ix] += val;
}

int getSum(int ix, int seg[]){
    int res = 0;
    for( ; ix > 0; ix -= ix & -ix) res += seg[ix];
    return res;
}

void solve() {
    
    cin >> n;
    vector<pair<int, int>> A(n);
    for(auto&[a,b] : A) cin >> a >> b;
    
    vector<pair<int, int>> B;
    for(int i = 0; i < n ;i++){
        B.push_back({A[i].x, i+1});
        B.push_back({A[i].y, -i-1});
    }
    sort(all(B));

    vector<int> cnt(n+1);
    int ix = 0;
    int ans2 = 0, val = 0;
    while(ix < int(B.size())){
        int nx = ix;
        while(nx < int(B.size()) && B[nx].x == B[ix].x) nx++;

        for(int i = ix; i < nx; i++){
            auto[a,b] = B[i];
            if (b < 0){
                val--;
                b *= -1;
                int ta = A[b-1].x;
                cnt[b] += getSum(maxn, segL) - getSum(ta - 1, segL) - 1;
            }
            else{
                val++;
                cnt[b] += getSum(maxn, segR) - getSum(a, segR);
            }
            ans2 = max(ans2, val);
        }
        
        for(int i = ix; i < nx; i++){
            auto[a,b] = B[i];
            if (b < 0){
            }
            else{
                int ta = A[b-1].y;
                update(a, 1, segL);
                update(ta, 1, segR);
            }
        }
        
        ix = nx;
    }
    
    int ans1 = 0;
    for(int i = 1; i <= n; i++){
        ans1 = max(ans1, cnt[i] + 1);
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
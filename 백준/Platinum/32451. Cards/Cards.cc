#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n;
int seg[1202020];
void update(int ix, int val){
    for (ix += n; ix; ix >>= 1){
        seg[ix] += val;
    }
}

int getS(int l, int r){
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1) res += seg[l++];
        if (r&1) res += seg[--r];
    }
    return res;
}

void solve(){
    
    
    cin >> n;
    vector<int> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;

    vector<pair<int, int>> C(n);
    for(int i =0; i < n ;i++) C[i] = mp(B[i], A[i]);
    sort(all(C));
    
    ll inv = 0;
    for(int i = n-1; i >= 0; i--){
        int ix = C[i].second;
        inv += getS(1, ix+1);
        update(ix, 1);
    }

    if(inv & 1) {
        cout << "No\n";
        return;
    }
    inv >>= 1;

    for(int i =0 ;i <= n *2  + 10; i++) seg[i] = 0;
    for(int i = 1; i <= n; i++) update(i, 1);

    vector<pair<int ,int>> ans;
    int len = n;
    for(int i = n-1; i >= 0; i--){
        int ix = C[i].second;

        int pos = getS(1, ix + 1);
        
        int able = len - pos;
       // cout << i + 1 << ' ' << able << '\n';
        len--;
        if(able <= inv){
            inv -= able;
            update(ix, -1);
            continue;
        }
        
        for(int j = 0; j <= i; j++) ans.push_back(mp(C[j].second, C[j].first));
        sort(all(ans));
        for(int j = i + 1; j < n; j++) ans.push_back(mp(C[j].second, C[j].first));

        // cout << "Go ans: " << inv << "\n";
        // for(int i =0 ;i < n; i++) cout  << ans[i].first << ' ';
        // cout << '\n';
        // for(int i =0 ;i < n; i++) cout  << ans[i].second << ' ';
        // cout << '\n';

        int idx = 0;
        for(int j =0 ; j < n;j++){
            if (ans[j].first == ix) idx = j;
        }

        for(int j = 0; j < inv; j++){
            swap(ans[idx], ans[idx+1]);
            idx++;
        }
        inv = 0;

        break;
    }

    if(ans.empty()){
        for(int j = 0; j < n; j++) ans.push_back(mp(C[j].second, C[j].first));
    }

    if(inv != 0){
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
        for(int i =0 ;i < n; i++) cout  << ans[i].first << ' ';
        cout << '\n';
        for(int i =0 ;i < n; i++) cout  << ans[i].second << ' ';
        cout << '\n';
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
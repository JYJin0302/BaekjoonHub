#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int root[301010];
int find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}
void solve(){
    
    int n;
    cin >> n;
    vector<array<int, 3>> rule;
    vector<int> num;
    for(int i = 0; i < n ;i++){
        int a, b, c;
        cin >> a >> b>> c;
        rule.push_back({a, b, c});
        num.push_back(a);
        num.push_back(b);
    }
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    for(auto& f: rule){
        f[0] = lower_bound(all(num), f[0]) - num.begin();
        f[1] = lower_bound(all(num), f[1]) - num.begin();
    }

    int sn = (int)num.size();
    for(int i = 0; i < sn; i++) root[i] = i;

    for(auto f :rule){
        if (f[2] == 1){
            int u =f[0];
            int v= f[1];
            u = find(u);
            v = find(v);
            root[u] = v;
        }
    }

    bool ok =1 ;
    for(auto f : rule){
        if(f[2] == 0){
            int u = f[0];
            int v = f[1];
            u = find(u);
            v = find(v);
            if (u == v) ok = 0;
        }
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
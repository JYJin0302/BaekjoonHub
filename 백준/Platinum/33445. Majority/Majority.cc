#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<pair<int, int>> adj[3000]; // 0 : or, 1 : and
int cur = 0;
pair<int, int> setup(int l, int r){
    
    if (l == r) {
        return mp(l, l);
    }

    int md = (l+r)>>1;
    auto[l1, r1] = setup(l, md);
    auto[l2, r2] = setup(md+1, r);

    int len1 = r1 - l1 + 1;
    int len2 = r2 - l2 + 1;

    vector<pair<int, int>> rec;
    for(int j = 1; j <= r-l+1; j++){
        int tl = cur;
        for(int a = 0;a <= len1 && a <= j; a++){
            int b = j -a;
            if (b > len2) continue;

            if (a) adj[cur].push_back(mp(l1 + a - 1, 1));
            if (b) adj[cur].push_back(mp(l2 + b - 1, 1));
            cur++;
        }
        rec.push_back(mp(tl, cur- 1));
    }

    int tl = cur;
    for(int j =1; j <= r-l+1;j++){
        auto[a, b] = rec[j-1];
        for(int f= a; f <= b; f++){
            adj[cur].push_back(mp(f, 0));
        }
        cur++;
    }

    return mp(tl, cur-1);
}


void solve(){
    
    int n;
    cin >> n;

    cur = n + 1;
    auto[l, r] = setup(1, n);
    // setup Answer
    for(int i = (n+1)/2; i <= n; i++){
        adj[cur].push_back(mp(l + i - 1, 0));
    }
    cur++;

    cout << cur - n - 1<< '\n';
    for(int i = n + 1; i < cur; i++){
        if (adj[i][0].y == 0) cout << "OR ";
        else cout << "AND ";
        cout << (int)adj[i].size() << ' ';
        for(auto[a,b] : adj[i]) cout << a << ' ';
        cout << '\n';
    }
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

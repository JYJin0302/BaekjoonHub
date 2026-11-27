#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> Adx[10101];
vector<int> Bdx[10101];

bool cmp(pair<int, int>& p1, pair<int, int>& p2){
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second > p2.second;
}
void solve(){   
    
    int n, m;
    cin >> n >> m;

    for(int i =0 ; i < n*m; i++){
        int x;
        cin >> x;
        Adx[x].push_back(i);
    }
    for(int i =0 ; i < n*m; i++){
        int x;
        cin >> x;
        Bdx[x].push_back(i);
    }

    vector<pair<int, int>> res;
    for(int i = 1; i <= n;i++){
        for(int j =0; j < m; j++){
            for(int f= 0; f < m; f++){
                res.push_back(mp(Adx[i][j], Bdx[i][f]));
            }
        }
    }

    sort(all(res), cmp);

    //for(auto[a,b]: res) cout << a<< ' ' << b<< '\n';
    vector<int> C;
    for(auto[a,b] : res){
        int iter = lower_bound(all(C), b) - C.begin();
        if (iter == C.size()) C.push_back(b);
        else C[iter] = b;
    }

    cout << C.size() << '\n';
}


int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
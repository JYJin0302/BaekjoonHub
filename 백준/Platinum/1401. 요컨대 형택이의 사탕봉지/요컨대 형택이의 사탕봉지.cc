#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<vector<int>> pre[10];

void setup(){
    pre[1].push_back({1});

    pre[2].push_back({1, 2});

    pre[3].push_back({1, 2});
    pre[3].push_back({1, 3});
    pre[3].push_back({2, 3});
    
    pre[4].push_back({1, 2, 4});
    pre[4].push_back({2, 3, 4});

    pre[5].push_back({1, 2, 4}); 
    pre[5].push_back({2, 3, 4});
    pre[5].push_back({1, 2, 5});
    pre[5].push_back({1, 3, 5});
    pre[5].push_back({2, 4, 5});
    pre[5].push_back({3, 4, 5});

    pre[6].push_back({3, 4, 5, 6});

    pre[7].push_back({3, 4, 5, 6}); 
    pre[7].push_back({1, 2, 4, 7});
    pre[7].push_back({1, 3, 5, 7});
    pre[7].push_back({2, 3, 6, 7});
    pre[7].push_back({3, 5, 6, 7});
    pre[7].push_back({4, 5, 6, 7});

    pre[8].push_back({4, 5, 6, 7, 8});

    pre[9].push_back({4, 5, 6, 7, 8}); 
    pre[9].push_back({1, 3, 5, 7, 9});
    pre[9].push_back({2, 3, 4, 8, 9});
    pre[9].push_back({4, 6, 7, 8, 9});
    pre[9].push_back({5, 6, 7, 8, 9});

    for(int i =1 ; i <= 9; i++) sort(all(pre[i]));
}


void solve(){
    
    int n;
    cin >>n;
    int rs = n/2 + 1;

    if (n <= 9){
        cout << rs << ' ' << pre[n].size() << '\n';
        for(auto f : pre[n]){
            for(auto a : f) cout << a<< ' ';
            cout << '\n';
        }
        return;
    }

    if(n & 1){
        cout << rs << ' ' << 4 << '\n';
        vector<vector<int>> ans(4);
        for(int i = 0; i < rs; i++) ans[0].push_back(n/2 + i);
        for(int i = 0; i < rs; i++) ans[1].push_back(n/2 + i + 1);
        for(int i =1 ; i <= n; i += 2) ans[2].push_back(i);
        ans[3].push_back(n/2);
        for(int i =0 ; i < rs-1; i++) ans[3].push_back(n/2 + 2 + i);

        sort(all(ans));

        for(auto f: ans){
            for(auto a : f){
                cout << a<< ' ';
            }
            cout << '\n';
        }


    }
    else{
        cout << rs << ' ' << "1\n";
        for(int i = n/2; i <= n; i++) cout << i << ' ';
        cout << '\n';
    }
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    setup();

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

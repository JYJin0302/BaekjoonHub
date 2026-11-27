#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char G[55][55];
struct D{
    char c;
    int i;
    bool oper;

    void pf(){
        cout << c << ' '<< i << ' ' << (oper ? "push" : "pull") << '\n';
    }
};

void solve(){
    
    int n, r, c;
    cin >> n >> r >> c;

    for(int i =1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> G[i][j];
        }
    }

    vector<D> ans;
    for(int i = c-1; i >= 1; i--){
        ans.push_back({'L', r, 1});
    }

    for(int i = c+1; i <= n; i++){
        ans.push_back({'R', r, 1});
    }

    for(int i = 1; i < r; i++){
        ans.push_back({'U', 1, 1});
    }
    for(int i = r+1; i <= n; i++) ans.push_back({'D', 1, 1});

    for(int i = r; i >= 1; i--){
        if (i != r){
            for(int f = 1; f < n; f++) ans.push_back({'R', i, 1});
        }

        for(int j = 2; j <= n; j++){
            if (G[i][j] == '.') ans.push_back({'U', j, 0});
        }
    }

    for(int i = r +1; i <= n; i++){
        for(int f = 1; f < n; f++) ans.push_back({'R', i, 1});

        for(int j = 2; j <= n; j++){
            if (G[i][j] == '.') ans.push_back({'D', j, 0});
        }
    }

    for(int i = 1; i <= n; i++){
        if (G[i][1] == '.') ans.push_back({'L', i, 0});
    }

    cout << ans.size() << '\n';
    for(auto f : ans) f.pf();

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
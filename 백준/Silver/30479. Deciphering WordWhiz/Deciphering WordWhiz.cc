#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;


void solve(){

    int n;
    cin >>n;

    vector<string> A(n);
    for(auto& i:A) cin >>i;

    vector<string > res(n);

    for(int i = 0; i < n;i++){
        string ts(5, 'X');
        vector<int> tmp;
        for(int j = 0; j < 5; j++){
            if (A[i][j] == A[0][j]) ts[j] = '*';
            else tmp.push_back(j);
        }

        for(int j = 0; j < 5; j++){
            if (ts[j] == '*') continue;

            for(auto f : tmp) {
                if (A[0][f] == A[i][j]){
                    ts[j] = '!';
                    break;
                }
            }
        }
        res[i] = ts;
    }

    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if (res[i] == s) cnt++;
        }
        cout << cnt << '\n';

    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

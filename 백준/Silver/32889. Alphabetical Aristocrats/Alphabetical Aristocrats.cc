#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair

void solve(){
    
    int n;
    cin >> n;
    cin.ignore();

    vector<pair<string, string>> res;
    string s;
    for(int i =0 ; i < n;i++){
        getline(cin, s);
        
        string ts;
        for(int j = 0; j < s.size(); j++){
            if (s[j] >= 'A' && s[j] <= 'Z'){
                for(int f = j; f < s.size(); f++){
                    ts += s[f];
                }
                break;
            }
        }
        res.push_back(mp(ts, s));
    }
    sort(res.begin(), res.end());

    for(auto[a,b] : res) cout << b<< '\n';

}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
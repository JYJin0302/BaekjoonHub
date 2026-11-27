#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i=a;i<(b);++i)

typedef long long ll;

void solve(){
    
    int n;cin >> n;

    if (n == 0){
        cout << 0 << '\n';
        return;
    }

    string s;
    while(n){
        if (n & 1){
            s += '1';
        }
        else s += '0';
        n >>= 1;
    }

    while(int(s.size()) % 7 != 0) s += '0';

    //cout << s<< '\n';
    //reverse(all(s));

    vector<int> res;
    for(int i =0 ; i< (int)s.size(); i+= 7){
        int val = 0;
        for(int j = 0; j < 7; j++){
            val += (s[i+j] - '0') << j;
        }
        res.push_back(val);
    }
    reverse(all(res));
    

    for(int i = 0; i < (int)res.size(); i++){
        if (i == (int)res.size() - 1) {}
        else res[i] += 1 << 7;
        
        cout<< res[i] << ' ';
    }
    cout << '\n';



}


int main(){ 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
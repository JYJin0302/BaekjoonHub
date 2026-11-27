#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int n;
    cin >> n;

    vector<int> d1, d2;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        d1.push_back(x);
        cout << "1\n";
    }

    int cur = 1;
    int pos = 1;
    while(cur <= n){
        if (pos == 1){
            while(!d1.empty()){
                int x = d1.back();
                if(x == cur){
                    cur++;
                    cout << "-1\n";
                }
                else {
                    cout << "12\n";
                    d2.push_back(x);
                }
                d1.pop_back();
            }
        }
        else{
            while(!d2.empty()){
                int x = d2.back();
                if(x == cur){
                    cur++;
                    cout << "-2\n";
                }
                else {
                    cout << "21\n";
                    d1.push_back(x);
                }
                d2.pop_back();
            }
        }
        pos = 3 - pos;
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


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
 
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    map<int, int> rec;
    for(int i =0 ;i < (1 << n); i++){
        int tot = 0;
        for(int j =0 ;j < n;j++){
            if (i & ( 1 << j)){
                tot += A[j];
            }
        }
        if (rec[tot] == 0){
            rec[tot] = i;
        }
        else{
            int mask1 = rec[tot];
            vector<int> ans1, ans2;
            for(int j = 0; j < n;j++){
                if (mask1 & (1 << j)){
                    if (i & (1 << j)){}
                    else ans1.push_back(A[j]);
                }
                else if (i & (1 << j)) ans2.push_back(A[j]);
            }

            for(auto f : ans1) cout << f<< ' ';
            cout << '\n';
            for(auto f : ans2) cout << f<< ' ';
            cout << '\n';
            return;
        }
    }
    cout << "Impossible\n";
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int t = 1;
    cin >> t;
    for(int i =0 ;i < t;i ++){
        cout << "Case #" << i + 1 << ":\n";
        solve();
    }


    return 0;
}
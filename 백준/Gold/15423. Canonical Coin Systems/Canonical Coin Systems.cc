#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
        
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int mx = A[n-1] * 2;
    bool o = 1;
    vector<int> dp(mx + 1, mx+3);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= mx; i++){
        int ix = 0;
        int ai = 0;
        while(ix < n && A[ix] <= i){
            if (dp[i] >= dp[i - A[ix]] + 1){
                dp[i] = dp[i-A[ix]] + 1;
                ai = ix;
            }
            ix++;
        }

        if (ai != ix - 1){
            o = 0;
            break;
        }
    }
    
    if(o) cout << "canonical";
    else cout << "non-canonical";
}
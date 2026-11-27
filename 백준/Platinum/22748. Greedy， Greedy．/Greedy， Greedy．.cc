#include <iostream>
#include <vector>

using namespace std;

int case_cnt = 0;

void ok(){
    cout << "Case #" << case_cnt << ": OK\n";
}
void cpsa(){
    cout << "Case #" << case_cnt << ": Cannot pay some amount\n";
}
void cuga(){
    cout << "Case #" << case_cnt << ": Cannot use greedy algorithm\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n){
        case_cnt++;
        
        vector<int> A(n);
        for(auto& i : A) cin >> i;
        
        if (A[0] != 1) cpsa();
        else{
            
            bool o = 1;
            vector<int> dp(2001, 2222);
            dp[0] = 0;
            dp[1] = 1;
            for(int i = 2; i <= 2000; i++){
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
            
            if (o) ok();
            else cuga();
        }
        cin >> n;
    }
}
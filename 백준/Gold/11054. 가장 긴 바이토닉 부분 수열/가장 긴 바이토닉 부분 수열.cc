#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int>base(n);
    for(auto& i : base) cin >> i;
    
    vector<int> upper(n+1);
    vector<int> lower(n+1);
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(base[j] < base[i]){
                upper[i] = max(upper[i], upper[j]);
            }
        }
        upper[i]++;
    }

    for(int i = n-1; i >= 0; i--){
        for (int j = n-1; j > i; j--){
            if (base[j]<base[i]){
                lower[i] = max(lower[i], lower[j]);
            }
        }
        lower[i]++;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, lower[i] + upper[i]);
    }
    
    cout << ans-1;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int ix[1000];
    vector<int> A(n+1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        ix[A[i]] = i;
    }
    
    int ans = 0;
    for (int x = n; x >= 2; x--){
        int idx = ix[x];
        int li = idx-1, ri = idx+1;
        while(li > 0 && A[li] > x) li--;
        while(ri <= n && A[ri] > x) ri++;
        
        if (li == 0) ans += x - A[ri];
        else if (ri == 0) ans += x - A[li];
        else ans += x - (max(A[li], A[ri]));
    }
    
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    int tot = 0, cnt = 0;
    vector<int> A(n);
    for(auto& i : A) {
        cin >> i;
        tot += i;
    }
    
    int minv = *min_element(A.begin(), A.end());
    for(int i : A) cnt += (i > minv);
    
    int ans = tot - n*minv;
    cout << ans << ' ' << cnt << '\n';
}
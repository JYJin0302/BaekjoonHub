#include <bits/stdc++.h>
using namespace std;

double pow(double a, int x){
    double res = 1;
    while(x--) res *= a;
    return res;
}

int main(){
    
    int k;
    cin >> k;
    
    vector<int> A(k+1);
    for(auto& i : A) cin >> i;
    reverse(A.begin(), A.end());
    
    int a, b, n;
    cin >> a >> b>> n;
    
    double val = 0;
    for(int i = 0; i <= k; i++){
        double t = 1.0 * A[i] / (i+1);
        val += t * (pow(b, i+1) - pow(a, i+1));
    }
    
    double dx = 1.0 * (b-a) / n;
    double l = 0, r = dx;
    
    while(r - l >= 0.0000001){
        
        double mid = (r + l) / 2;
        double res = 0;
        
        for(int i = 0; i < n; i++){
            
            double tx = a + i*dx + mid;
            
            double tval = 0;
            for (int j = 0; j <= k; j++){
                tval += pow(tx, j) * A[j];
            }
            res += tval * dx;
        }
        
        if (abs(res - val) < 0.0000001) break;
        
        if (res > val) r = mid;
        else l = mid;
    }
    
    cout << (l + r) /2;
}
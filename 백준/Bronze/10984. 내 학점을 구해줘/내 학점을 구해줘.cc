#include <bits/stdc++.h>
using namespace std;

int main(){
    
    cout << fixed << setprecision(1);
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        int val = 0;
        double gpa = 0;
        
        int a;
        double b;
        for(int i =0; i < n; i++){
            cin >> a >> b;
            val += a;
            gpa += b*a;
        }
        
        cout << val << ' ' << gpa/val << '\n';
        
    }
    
}
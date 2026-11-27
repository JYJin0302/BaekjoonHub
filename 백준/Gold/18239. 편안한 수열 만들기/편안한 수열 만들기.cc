#include <bits/stdc++.h>
using namespace std;

void yes(){
    cout << "YES\n";
}

void no(){
    cout << "NO\n";
}
void rev(int a, int b){
    cout << "reverse " << a << ' ' << b << '\n';
}

void s(int a, int b){
    cout << "swap " << a<< ' ' << b << '\n';
}

int main(){
    
    int n, k;
    cin >> n >> k;
    
    if (n == 3){
        no();
        return 0;
    }
    
    yes();
    if (k == 1){
        if (n == 2){
            for (int i = 0; i < 5; i++) s(1, 2);
        }
        else{
            rev(2, n);
            rev(1, n);
            s(1, 4);
            s(2, 3);
            rev(1, 4);
        }
    }
    else if (k + 1 == n){
        rev(1, n-1);
        rev(1, n);
        s(1, 4);
        s(2, 3);
        rev(1, 4);
        
    }
    
    else{
        s(1, 2);
        s(1, 2);
        rev(1, k);
        rev(k+1, n);
        rev(1, n);
    }
}
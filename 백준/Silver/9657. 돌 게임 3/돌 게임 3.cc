#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int t = n % 7;
    if (t == 0 || t == 2){
        cout << "CY";
    }
    else cout << "SK";
    
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int num = 1;
    int den = 1;
    for (int i = 1; i <= k; i++){
        num *= n + 1 - i;
        den *= i;
    }
    cout << num / den;
}
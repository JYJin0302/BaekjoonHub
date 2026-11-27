#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, a, b;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if (s == "KBS1") a = i;
        if (s == "KBS2") b = i;
    }
    
    if (a > b) b++;
    
    for (int i = 0; i < a - 1; i++) cout << 1;
    for (int i = 0; i < a-1; i++) cout << 4;
    
    for (int i = 0; i < b-1; i++) cout << 1;
    for (int i = 0; i < b-2; i++) cout << 4;
}
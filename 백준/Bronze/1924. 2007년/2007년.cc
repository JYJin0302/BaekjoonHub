#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string d[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    
    int a, b;
    cin >> a >> b;
    
    int v = 0;
    for(int i = 0; i < a; i++) v += m[i];
    v += b;
    v -= 1;
    v %= 7;
    cout << d[v];
}
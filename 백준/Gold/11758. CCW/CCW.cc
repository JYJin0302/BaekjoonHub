#include <bits/stdc++.h>
using namespace std;

int main(){
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >>x2 >> y2 >> x3 >> y3;
    pair<int, int> p1 = { x1-x2, y1-y2};
    pair<int, int> p2 = { x3-x2, y3-y2};
    
    int temp = p1.first*p2.second - p1.second*p2.first;
    if (temp > 0) cout << -1;
    else if (temp < 0) cout << 1;
    else cout << 0;
}
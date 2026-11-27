#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d, t;
    cin >> a >>b >>c >>d >>t;

    int ans1 = a + max(0, t-30)*b*21;
    int ans2 = c +max(0, t-45)*d*21;
    cout <<ans1 <<' ' <<ans2;
}

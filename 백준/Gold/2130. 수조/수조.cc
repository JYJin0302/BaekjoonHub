#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cout <<fixed << setprecision(2);
    
    vector<pair<ll, ll>> A;
    ll a, b, c, d;
    for (int i = 0; i < n;i ++){
        cin >> a>> b >> c >> d;
        
        A.push_back({a, c*d});
        A.push_back({a + b, -c*d});
    }
    
    cin >> d;
    sort(A.begin(), A.end());
    
    ll px = 0, ph = 0, tot = 0;
    for (auto i : A){
        
        if ((i.x - ph) * px + tot >= d){
            double th = (d - tot) / (double)px;
            cout << th + ph;
            return 0;
        }
        
        tot += (i.x - ph) * px;
        ph = i.x;
        px += i.y;
    }
    
    cout << "OVERFLOW\n";
}
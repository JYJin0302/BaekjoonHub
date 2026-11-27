#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define a first
#define b second

pair<ll, ll> c_h[100001];

ll idx = 0;
void push_line(ll x, ll y){
    c_h[idx].a = x;
    c_h[idx].b = y;
    idx++;
}

double cross_x(ll i1, ll i2){
    return 1.0 * (c_h[i2].b - c_h[i1].b) / (c_h[i1].a - c_h[i2].a);
}

void del_line(){
    idx--;
    c_h[idx - 1] = c_h[idx];
    c_h[idx].a = 0;
    c_h[idx].b = 0;
    
}

ll find_line_idx(int x){
    
    ll l = 0, r = idx - 1;
        while(l < r){
            ll m = (l+r)/2;
            
            if (cross_x(m, m+1) <= x){
                l = m + 1;
            }
            else r = m;
        }
    
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    vector<ll> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    
    push_line(B[0], 0);
    
    for (int i = 1; i < n; i++){
        
        
        ll curr_x = A[i];
        // find line idx
        ll l = find_line_idx(curr_x);
        
        ll nb = c_h[l].a * curr_x + c_h[l].b;
        ll na = B[i]; 
       
        // insert new line
        push_line(na, nb);
        
        while(idx > 2) {
            ll i0 = idx - 1, i1 = idx - 2, i2 = idx - 3;
            double c1 = cross_x(i0, i1), c2 = cross_x(i0, i2);
            if (c1 <= c2){
                del_line();
            } 
            else break;
        }
    }
    
    cout << c_h[idx - 1].b;
    
}
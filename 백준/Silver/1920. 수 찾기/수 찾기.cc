#include <bits/stdc++.h>
using namespace std;

int n, m, a;
vector<int> A;
bool found;

void search(int num, int l = 0, int r = n-1){
    if(l > r) return;
    int mid = (l+r)/2;
    
    if (A[mid] == num) {
        found = true;
        return;
    }
    
    if (A[mid] > num) search(num, l, mid-1);
    else search(num, mid+1, r);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    A = vector<int> (n);
    for (auto& i : A) cin >> i;
    
    sort(A.begin(), A.end());
    
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> a;
        found = false;
        search(a);
        if (found) cout << "1\n";
        else cout << "0\n";
    }
}
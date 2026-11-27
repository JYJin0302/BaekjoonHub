#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<int, int>> A;
int ans = 0;

bool update(){

    if (A.size() == 1) return 0;
    int n = A.size();
    sort(all(A));
    bool diff = 0;
    if (A[0].x < A[1].x){
        ans += A[1].x - A[0].x;
        A[0].x = A[1].x;
        diff = 1;
    }
    if (A[n-1].x > A[n-2].x){
        ans += A[n-1].x - A[n-2].x;
        A[n-1].x = A[n-2].x;
        diff = 1;
    }
    sort(all(A));
    A.erase(unique(all(A)), A.end());

    if (A.size() == 1) return 0;

    for(auto&[a,b] : A) swap(a, b);
    n = A.size();
    sort(all(A));
    if (A[0].x < A[1].x){
        ans += A[1].x - A[0].x;
        A[0].x = A[1].x;
        diff = 1;
    }
    if (A[n-1].x > A[n-2].x){
        ans += A[n-1].x - A[n-2].x;
        A[n-1].x = A[n-2].x;
        diff = 1;
    }
    sort(all(A));
    A.erase(unique(all(A)), A.end());
    
    for(auto&[a,b] : A) swap(a, b);
    return diff;
}

void solve(){
    
    for(int i =0 ; i < 5; i++){
        int a, b;
        cin >> a>> b;
        A.push_back(mp(a, b));
    }

    while(update()){
        // pass
    }

    if (A.size() != 1){
        int mx = 1010, Mx = -1;
        int my = 1010, My = -1;

        int tx = -1, ty = -1;
        for(auto[a,b] : A) {
            mx = min(mx, a);
            Mx = max(Mx, a);
            my = min(my, b);
            My = max(My, b);
        }

        for(auto[a,b] : A) {
            if (a == mx || a == Mx) continue;
            if (b == my || b == My) continue;
            tx = a, ty = b;
        }
        ans += (Mx - mx) * 2 + (My - my) * 2;
        if(tx != -1){
            ans += min(Mx - mx, My - my);
        }
    }

    cout << ans << '\n';
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
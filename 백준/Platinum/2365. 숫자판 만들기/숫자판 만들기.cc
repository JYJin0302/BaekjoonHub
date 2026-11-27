#include <bits/stdc++.h>
using namespace std;

// 0 : source, 1-50 : left, 51-100: right, 101 : sink

int c[105][105];
int f[105][105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;    
    
    int l = 0, r = 10000, tot = 0, ans = 0;
    for (int i : A) tot += i;
    
    for (int i = 0; i < n; i++){
        c[0][i+1] = A[i];
        c[i+51][101] = B[i];
    }
        
    while(l <= r){
        int mid = (l+r)/2;
        
        for (int i = 0; i < n; i++){
            f[0][i+1] = 0;
            f[i+1][0] = 0;
            f[i+51][101] = 0;
            f[101][i+51] = 0;
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                c[i+1][j+51] = mid;
                f[i+1][j+51] = 0;
                f[j+51][i+1] = 0;
            }
        }
        
        int mf = 0;
        while(1){
            
            vector<int> from(103, -1);
            from[0] = 0;
            queue<int> q;
            q.push(0);
            while(!q.empty()){
                
                int a = q.front();
                q.pop();
                
                if (a == 0){
                    for (int i = 1; i <= n; i++){
                        if (from[i] == -1 && c[a][i] - f[a][i] > 0){
                            from[i] = a;
                            q.push(i);
                        }
                    }
                }
                else if (a >= 1 && a <= 50){
                    for (int i = 51; i <= 50+n; i++){
                        if (from[i] == -1 && c[a][i] - f[a][i] > 0){
                            from[i] = a;
                            q.push(i);
                        }
                    }
                }
                else if (a >= 51 && a <= 100){
                    for (int i = 1; i <= n; i++){
                        if (from[i] == -1 && c[a][i] - f[a][i] > 0){
                            from[i] = a;
                            q.push(i);
                        }
                    }
                    if (from[101] == -1 && c[a][101] - f[a][101] > 0){
                        from[101] = a;
                        q.push(101);
                    }
                }
            }
            
            if (from[101] == -1) break;
            
            int tx = 101, mx = 10000;
            while(tx != 0){
                int nxt = from[tx];
                mx = min(mx, c[nxt][tx] - f[nxt][tx]);
                tx = nxt;
            }
            
            tx = 101;
            while(tx != 0){
                int nxt = from[tx];
                f[nxt][tx] += mx;
                f[tx][nxt] -= mx;
                tx = nxt;
                
            }
            mf += mx;
        }
        
        if (mf == tot) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    int mid = ans;
    cout << mid << '\n';
    for (int i = 0; i < n; i++){
            f[0][i+1] = 0;
            f[i+1][0] = 0;
            f[i+51][101] = 0;
            f[101][i+51] = 0;
        }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            c[i+1][j+51] = mid;
            f[i+1][j+51] = 0;
            f[j+51][i+1] = 0;
        }
    }
    
    int mf = 0;
    while(1){
        
        vector<int> from(103, -1);
        queue<int> q;
        from[0] = 0;
        q.push(0);
        while(!q.empty()){
            
            int a = q.front();
            q.pop();
            
            if (a == 0){
                for (int i = 1; i <= 50; i++){
                    if (from[i] == -1 && c[a][i] - f[a][i] > 0){
                        from[i] = a;
                        q.push(i);
                    }
                }
            }
            else if (a >= 1 && a <= 50){
                for (int i = 51; i <= 100; i++){
                    if (from[i] == -1 && c[a][i] - f[a][i] > 0){
                        from[i] = a;
                        q.push(i);
                    }
                }
            }
            else if (a >= 51 && a <= 100){
                for (int i = 1; i <= 50; i++){
                    if (from[i] == -1 && c[a][i] - f[a][i] > 0){
                        from[i] = a;
                        q.push(i);
                    }
                }
                if (from[101] == -1 && c[a][101] - f[a][101] > 0){
                    from[101] = a;
                    q.push(101);
                }
            }
        }
        
        if (from[101] == -1) break;
            
        int tx = 101, mx = 10000;
        while(tx != 0){
            int nxt = from[tx];
            mx = min(mx, c[nxt][tx] - f[nxt][tx]);
            tx = nxt;
        }
        
        tx = 101;
        while(tx != 0){
            int nxt = from[tx];
            f[nxt][tx] += mx;
            f[tx][nxt] -= mx;
            tx = nxt;
            
        }
        mf += mx;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << f[i][j+50] << ' ';
        }
        cout << '\n';
    }
}
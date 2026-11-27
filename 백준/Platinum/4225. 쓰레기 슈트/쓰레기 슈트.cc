#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const double PI = 3.141592;
// 컨벡스 헐 -> 한 직선과 가장 멀리 떨어진 점까지의 거리들 중 최솟값 !

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << fixed << setprecision(2);
    
    int n, case_cnt = 0;
    cin >> n;
    
    while(n != 0){
        
        case_cnt++;
        
        vector<pair<int, int>> Ai(n);
        for(auto& i : Ai) cin >> i.X >> i.Y;
        
        int tx, ty;
        tie(tx, ty) = *min_element(Ai.begin(), Ai.end());
        sort(Ai.begin(), Ai.end());
        
        vector<pair<double, int>> B;
        
        for (int i = 1; i < n; i++) {
            
            int a, b;
            tie(a, b) = Ai[i];
            
            double ang = PI/2;
            
            if (a != tx) ang = atan((double)(b - ty) / (a - tx));
            
            B.push_back({ang, i});
        }
        
        sort(B.begin(), B.end());
        
        stack<int> st;
        st.push(0);
        
        for (int i = 0; i < n - 1; i++){
            
            bool ok = 0;
            st.push(B[i].Y);
            while(!ok && st.size() > 2){
                int a, b, c;
                c = st.top();
                st.pop();
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                
                int d = Ai[a].X * Ai[b].Y + Ai[b].X * Ai[c].Y + Ai[c].X * Ai[a].Y \
                    - (Ai[a].Y * Ai[b].X + Ai[b].Y * Ai[c].X + Ai[c].Y * Ai[a].X);
            
                if (d > 0) st.push(a), st.push(b), st.push(c), ok = 1;
                else if (d == 0) st.push(a), st.push(c), ok = 1;
                else st.push(a), st.push(c);
            }
        }
        
        vector<int> A;
        while(!st.empty()) A.push_back(st.top()), st.pop();
        
        int m = A.size();
        
        double ans = 20000000;
        
        for (int i = 0; i < m; i++){
            
            int a, b, c;
            a = i, b = (i + 1) % m;
            
            double ttans = 0;
            for (int c = 0; c < n; c++){
                int d = abs(Ai[A[a]].X * Ai[A[b]].Y + Ai[A[b]].X * Ai[c].Y + Ai[c].X * Ai[A[a]].Y \
                            - (Ai[A[a]].Y * Ai[A[b]].X + Ai[A[b]].Y * Ai[c].X + Ai[c].Y * Ai[A[a]].X));
                
                double tans = (double)d / \
                    sqrt((Ai[A[a]].X - Ai[A[b]].X)*(Ai[A[a]].X - Ai[A[b]].X) + (Ai[A[a]].Y - Ai[A[b]].Y)*(Ai[A[a]].Y - Ai[A[b]].Y));
                
                ttans = max(ttans, tans);
            }
            
            ans = min(ans, ttans);
        }
                
        cout << "Case " << case_cnt << ": " << ceil(ans * 100) / 100 << '\n';
        cin >> n;
    }
}
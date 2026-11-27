#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >>k;

    vector<int> A(n);
    for(auto& i : A) cin >>i;

    sort(A.begin(), A.end());
    priority_queue<int> pq;


    int ans = 0;
    for(int i = 0; i < k; i++){
        ans+= A[i];
        pq.push(-A[i]);
    }
    for(int i = k; i < n; i++){
        int v = -pq.top();
        pq.pop();

        ans += v + A[i];
        pq.push(-v-A[i]);
    }
    cout <<ans;


    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct T {
    ll val, cnt, idx;
};

struct cmp {
    bool operator()( T& a, T& b ) {
        return a.val < b.val;
    }
};
std::vector<long long> find_minimum_costs(int N, std::vector<int> A, std::vector<int> B) {
    std::vector<long long> C(N);
    int M = A.size();

    priority_queue<T, vector<T>, cmp> pq;
    for (int i = 0; i < M; i++) {
        pq.push({ -(A[i] + B[i]), 1, i });
    }

    ll curr = 0;
    T tmp1, tmp2;
    tmp1 = pq.top();
    pq.pop();
    tmp2 = pq.top();
    pq.pop();
    C[1] = -tmp2.val;
    pq.push({ -(C[1] + 1ll* A[tmp1.idx] * 2 + B[tmp1.idx]), 2, tmp1.idx });
    pq.push({ -(C[1] + 1ll* A[tmp2.idx] * 2 + B[tmp2.idx]), 2, tmp2.idx });
    curr = C[1];
    for (int i = 2; i < N; i++) {
        T tmp = pq.top();
        pq.pop();

       // cout << "CURR: " << -tmp.val << ' ' << tmp.cnt << ' ' << tmp.idx << '\n';

        curr = max(curr, -tmp.val);
        C[i] = curr;

        ll nval = C[tmp.cnt] + 1ll* A[tmp.idx] * (tmp.cnt+1) + B[tmp.idx];
        pq.push({ -nval, tmp.cnt + 1, tmp.idx });
    }
    
    return C;
}
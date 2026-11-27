#include <bits/stdc++.h>

using namespace std;

int main()
{


    vector<int> A(4);
    for(auto&i:A) cin >>i;

    int b;
    cin >>b;

    bool ok = 0;
    if (A[0] == A[1] &&A[0] == A[2] && A[0] == A[3]) ok = 1;

    for(int i = 0; i < 4; i++){
        A[i] += b;
    if (A[0] == A[1] &&A[0] == A[2] && A[0] == A[3]) ok = 1;

        A[i]-= b;
    }

    cout <<ok;
}

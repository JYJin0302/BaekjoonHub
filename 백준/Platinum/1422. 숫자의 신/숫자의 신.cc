#include <bits/stdc++.h>
using namespace std;

bool cmp1(string s1, string s2) {

	string ss1 = s1 + s2;
    string ss2 = s2 + s1;
    
    for (int i = 0; i < ss1.size(); i++){
        if (ss1[i] != ss2[i]) return ss1[i] > ss2[i];
    }

	return s1.size() < s2.size();
}

bool cmp2(string s1, string s2) {

	if (s1.size() != s2.size()) return s1.size() > s2.size();

	for (int i = 0; i < s1.size(); i++) {
		
		if (s1[i] != s2[i]) return s1[i] > s2[i];
	}

	return s1.size() < s2.size();
}

int main() {

	int k, n;
	cin >> k >> n;
	
	vector<string> A(k);
	for (auto& i : A) cin >> i;

	sort(A.begin(), A.end(), cmp2);
	string t = A[0];
	while (A.size() < n) A.push_back(t);

	sort(A.begin(), A.end(), cmp1);
	for (auto i : A) cout << i;
	
}
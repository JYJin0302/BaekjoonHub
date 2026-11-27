#include <bits/stdc++.h>
using namespace std;

vector<string> stars;

void star(int n) {
	if (n == 3) return;

	star(n / 2);
	for (int i = 0; i < n / 2; i++) {
		stars.push_back(stars[i] + " " + stars[i]);
	}
	string blank(n / 2, ' ');
	for (int i = 0; i < n / 2; i++) {
		stars[i] = blank + stars[i] + blank;
	}
	
}

int main() {
	int t;
	cin >> t;

	stars.push_back("  *  ");
	stars.push_back(" * * ");
	stars.push_back("*****");

	star(t);
	for (int i = 0; i < t; i++) {
		cout << stars[i] << '\n';
	}

}
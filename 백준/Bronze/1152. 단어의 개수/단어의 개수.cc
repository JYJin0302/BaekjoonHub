#include <iostream>
#include <cmath>
#include "stdio.h"
#include <cstring>

using namespace std;


int main() {

	int cnt = 0, i=0, n;
	char ch[1000005];
	bool word = false;

	cin.getline(ch, 1000001);
	
	n = strlen(ch);
	
	for (int i = 0; i <= n; i++) {
		if (ch[i] != ' ' && ch[i] != '\0')
			word = true;
		if ( (ch[i] == ' '|| ch[i] == '\0') && word == true && ch[i+1] != ' ' ) {
			cnt++;
			word = false;
		}
	}
	

	if ((n == 1 && ch[0] == ' '))
		cnt = 0;
	else if (ch[0] == '\0')
		cnt = 0;
	
	cout << cnt;

	return 0;
}
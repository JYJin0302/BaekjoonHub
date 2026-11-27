#include "hat.h"
#include <vector>
using namespace std;

void init(int N)
{
	// Do Something...
}

int call(vector<int> F, vector<int> B, int num)
{
	int b1 = 0;
    for (int i : F) b1 ^= i;
    
    int b2 = 0;
    for(int i : B) b2 ^= i;
    
	return b1^b2;
}
#include <stdio.h>

int main(void) {
	int a,b;
	int count=0;
	int sum=0;
	int l;
	scanf("%d",&a);
	for(int i = 0; i<a; i++){
		count = 0;
		sum = 0;
		scanf("%d",&b);
		int n[1000] = {0,};
		for(int j = 0; j<b; j++){
			scanf("%df", &n[j]);
			sum += n[j];
		}
		
		for(l = 0; l<b; l++){
			if(sum<n[l] * b)
				count++;
		}
		printf("%.3lf%%\n",(double)count/b*100);
	}
}
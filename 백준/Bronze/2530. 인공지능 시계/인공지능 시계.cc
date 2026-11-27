// test
#include <stdio.h>
int main(void)
{
	int h, m, s;
	int time;
	scanf("%d %d %d", &h, &m, &s);
	
	scanf("%d", &time);
	
	time += h*3600;
	time += m*60;
	time += s;
	
	h=time/3600;
	m=time%3600/60;
	s=time%3600%60;
	
    if(h<24)
    {
    	printf("%d %d %d \n", h, m, s);
	}
	else  //(h>=24)
	{
		printf("%d %d %d \n", h%24, m, s);
	}
	
	return 0;
}
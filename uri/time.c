#include <stdio.h>

int main(){
	int hr = 0,min = 0,sec;
	scanf("%d",&sec);
	if(sec >= 60){
		min = sec/60;
		sec = sec%60;	
	}
	if(min >= 60){
		hr = min/60;
		min = min%60;	
	}

	printf("%d:%d:%d\n",hr,min,sec);
	return 0;
}

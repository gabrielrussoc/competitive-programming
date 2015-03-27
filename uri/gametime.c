#include <stdio.h>

int main(){
	int hf, hi, mf, mi,h,m;
	scanf("%d %d %d %d",&hi,&mi,&hf,&mf);
	
	if(mf >= mi){
		m = mf - mi;
		if (hf > hi){
			h = hf - hi;		
		} else {
			h = 24 + hf - hi;		
		}	
	} else {
		m = mf - mi + 60;
		if (hf > hi){
			h = hf - hi - 1;		
		} else {
			h = 23 + hf - hi;		
		}	
	}

	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",h,m);	

	return 0;
}

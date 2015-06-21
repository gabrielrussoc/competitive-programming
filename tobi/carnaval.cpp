#include <cstdio>

int main(){
	float v[5];

	for(int i = 0; i < 5; i++)
		scanf("%f",&v[i]);

	float min = 11, max = 0;
	float soma = 0;

	for(int i = 0; i < 5; i++){
		if(v[i] < min)
			min = v[i];
		if(v[i] > max)
			max = v[i];
		soma += v[i];
	}

	printf("%.1f\n",(soma-min-max));
}
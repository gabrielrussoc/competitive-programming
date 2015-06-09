#include <cstdio>

int v[6];
int AB[2], AC[2], BC[2];

int main(){

	scanf("%d %d %d %d %d %d",&v[0],&v[1],&v[2],&v[3],&v[4],&v[5]);

	AB[0] = v[2] - v[0];
	AB[1] = v[3] - v[1];
	BC[0] = v[4] - v[2];
	BC[1] = v[5] - v[3];
	AC[0] = v[4] - v[0];
	AC[1] = v[5] - v[1];

	if(AB[0]*AC[0] + AC[1]*AB[1] == 0){
		printf("RIGHT\n");
		return 0;
	}
	if(AB[0]*BC[0] + AB[1]*BC[1] == 0){
		printf("RIGHT\n");
		return 0;
	}
	if(AC[0]*BC[0] + AC[1]*BC[1] == 0){
		printf("RIGHT\n");
		return 0;
	}


	for(int i = 0; i < 6; i++){
		v[i]++;
		if(v[0] == v[2] && v[1] == v[3]){
			v[i]--;
			continue;
		}
		if(v[0] == v[4] && v[1] == v[5]){
			v[i]--;
			continue;
		}
		if(v[2] == v[4] && v[3] == v[5]){
			v[i]--;
			continue;
		}



		AB[0] = v[2] - v[0];
		AB[1] = v[3] - v[1];
		BC[0] = v[4] - v[2];
		BC[1] = v[5] - v[3];
		AC[0] = v[4] - v[0];
		AC[1] = v[5] - v[1];
		if(AB[0]*AC[0] + AC[1]*AB[1] == 0){
			printf("ALMOST\n");
			return 0;
		}
		if(AB[0]*BC[0] + AB[1]*BC[1] == 0){
			printf("ALMOST\n");
			return 0;
		}
		if(AC[0]*BC[0] + AC[1]*BC[1] == 0){
			printf("ALMOST\n");
			return 0;
		}
		v[i] -= 2;
		if(v[0] == v[2] && v[1] == v[3]){
			v[i] += 2;
			continue;
		}
		if(v[0] == v[4] && v[1] == v[5]){
			v[i] += 2;
			continue;
		}
		if(v[2] == v[4] && v[3] == v[5]){
			v[i] += 2;
			continue;
		}
		AB[0] = v[2] - v[0];
		AB[1] = v[3] - v[1];
		BC[0] = v[4] - v[2];
		BC[1] = v[5] - v[3];
		AC[0] = v[4] - v[0];
		AC[1] = v[5] - v[1];
		if(AB[0]*AC[0] + AC[1]*AB[1] == 0){
			printf("ALMOST\n");
			return 0;
		}
		if(AB[0]*BC[0] + AB[1]*BC[1] == 0){
			printf("ALMOST\n");
			return 0;
		}
		if(AC[0]*BC[0] + AC[1]*BC[1] == 0){
			printf("ALMOST\n");
			return 0;
		}
		v[i]++;	
	}


	printf("NEITHER\n");



}
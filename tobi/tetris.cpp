#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct a{
	int p[12];
	int t;
	char nome[17];
} v[1004];

bool comp(a i, a j){

	if(i.t > j.t) 
		return true;
	else if (i.t == j.t){
		if(strcmp(i.nome,j.nome) < 0)
			return true;
	}
	return false;

}

int main(){
	
	int j, tc = 1;
	while(scanf("%d",&j) && j != 0){

		for(int i = 0; i < j; i++){
			scanf(" %s",v[i].nome);
			for(int k = 0; k < 12; k++)
				scanf("%d",&v[i].p[k]);
			sort(v[i].p,v[i].p+12);
			v[i].t = 0;
			for(int k = 1; k < 11; k++)
				v[i].t += v[i].p[k];
		}
		sort(v,v+j,comp);

		printf("Teste %d\n",tc++);
		int k = 1;
		printf("%d %d",k,v[0].t);
		printf(" %s\n",v[0].nome);
		for(int i = 1; i < j; i++){
			if(v[i].t == v[i-1].t)
				printf("%d %d",k,v[i].t);
			else{
				printf("%d %d",i+1,v[i].t);
				k = i+1;
			}
			printf(" %s\n",v[i].nome);
		}
		printf("\n");
	}

}
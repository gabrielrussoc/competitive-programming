#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>

using namespace std;

struct team{
	string nome;
	int p;
	int j;
	int gp;
	int gc;
	int sg;
} v[30];

map<string,int> mapa;

bool comp(team i, team j){

	if(i.p != j.p)
		return i.p > j.p;
	else if(i.sg != j.sg)
		return i.sg > j.sg;
	else if(i.gp != j.gp)
		return i.gp > j.gp;
	else
		return strcasecmp(i.nome.c_str(),j.nome.c_str()) < 0;



}

int main(){
		
	int g,t;
	while(scanf("%d %d",&t,&g) && t != 0){

		char aux[120],t1[20],t2[20],c;
		int g1,g2;
		string s;

		for(int i = 0; i < 30; i++){
			v[i].nome.clear();
			v[i].p = 0;
			v[i].j = 0;
			v[i].gp = 0;
			v[i].gc = 0;
			v[i].sg = 0;
		}
		mapa.clear();

		for(int i = 0; i < t; i++){
			scanf("%s",aux);
			mapa.insert(pair<string,int>(aux,i));
			v[mapa[aux]].nome = aux;
		}

		for(int i = 0; i < g; i++){
			scanf("%s %d  %c %d %s",t1,&g1,&c,&g2,t2);
			v[mapa[t1]].j++;
			v[mapa[t1]].gp += g1;
			v[mapa[t1]].gc += g2;
			v[mapa[t1]].sg += g1-g2;
			v[mapa[t2]].j++;
			v[mapa[t2]].gp += g2;
			v[mapa[t2]].gc += g1;
			v[mapa[t2]].sg += g2-g1;


			if(g1 == g2){
				v[mapa[t1]].p++;
				v[mapa[t2]].p++;
			}
			else if(g1 > g2)
				v[mapa[t1]].p += 3;
			else
				v[mapa[t2]].p += 3;

		}

		sort(v,v+t,comp);

		bool print;
		int k = 1;

		printf(" 1. %15s %3d %3d %3d %3d %3d",v[0].nome.c_str(),v[0].p,v[0].j,v[0].gp,
				v[0].gc,v[0].sg);
			if(v[0].j > 0)
				printf("%7.2lf",(double) 100*(v[0].p)/(3*v[0].j));
			else
				printf("    N/A");
			printf("\n");

		for(int i = 1; i < t; i++){

			if(v[i].p == v[i-1].p && v[i].sg == v[i-1].sg && v[i].gp == v[i-1].gp)
				printf("   ");
			else
				printf("%2d.",i+1);
				
			printf("%16s%4d %3d %3d %3d %3d",v[i].nome.c_str(),v[i].p,v[i].j,v[i].gp,
				v[i].gc,v[i].sg);
			if(v[i].j > 0)
				printf("%7.2lf",(double) 100*(v[i].p)/(3*v[i].j));
			else
				printf("    N/A");
			printf("\n");

		}

		printf("\n");
	}


}
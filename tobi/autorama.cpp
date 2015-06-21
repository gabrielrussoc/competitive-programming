#include <bits/stdc++.h>

using namespace std;

struct car{
	int posto;
	int id;
	int ult;
	int tmp;
} v[105];

bool comp(car i, car j){

	if(i.posto > j.posto) 
		return true;
	if(i.posto == j.posto) 
		return (i.tmp < j.tmp);

	return false;
}

int main(){

	int n, k, m;

	scanf("%d %d %d",&k,&n,&m);
	int x,y;

	for(int i = 1; i <= n; i++){
		v[i].ult = 0;
		v[i].posto = 0;
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d",&x,&y);
		v[x].id = x;
		if(v[x].ult == y-1){
			v[x].posto++;
			v[x].ult = y%k;
			v[x].tmp = i;
		}
	}

	sort(v+1,v+n+1,comp);

	for(int i = 1; i <= n; i++)
		printf("%d ",v[i].id);
	printf("\n");
	
}
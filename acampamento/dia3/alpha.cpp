#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int t;
int m[10005];
char aux[10005];

long long pd(int i){

	if(aux[i] == '0') return 0;
	if(i > t) return 0;
	if(m[i] != -1) return m[i];
	if(i == t) return 1;	

	int r = pd(i+1);
	if((aux[i]-'0')*10 + aux[i+1]-'0' < 27)	
	 r += pd(i+2);

	m[i] = r;
	return r;
}


int main(){

	while(scanf(" %s",aux)){

		memset(m,-1,sizeof m);
		if(aux[0] == '0') break;
		
		t = strlen(aux);
		long long ans = pd(0);
		printf("%lld\n",ans);

	}


}

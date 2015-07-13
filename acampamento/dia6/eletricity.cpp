#include <cstdio>

using namespace std;

int mes[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int dd,mm,aa;

int in[1003][6];

void anterior(int d, int m, int a){

	if(d == 1 && m == 1){
		dd = 31;
		mm = 12;
		aa = a-1;	
	}
	
	else if(d == 1){
		if(m == 3 && a%4 == 0 && a%100 != 0)
			dd = 29;
		else
			dd = mes[m-1];
		mm = m-1;
		aa = a; 		
	}
	else{
		dd = d-1;
		mm = m;
		aa = a;
	}
	//printf("atual %d %d %d\nanterior %d %d %d\n",d,m,a,dd,mm,aa);
}


int main(){

	int n;
	while(scanf("%d",&n) && n != 0){	
		for(int i = 0; i < n; i++)
			scanf("%d %d %d %d",&in[i][0],&in[i][1],&in[i][2],&in[i][3]);

		int cont, ans;
		cont = ans = 0;
		for(int i = 1; i < n; i++){
			anterior(in[i][0],in[i][1],in[i][2]);
			if(dd == in[i-1][0] && mm == in[i-1][1] && aa == in[i-1][2]){
				cont++;
				ans += in[i][3] - in[i-1][3];
			}
		}
		printf("%d %d\n",cont,ans);
	}

}

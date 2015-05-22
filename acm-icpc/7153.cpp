#include <cmath>
#include <algorithm>
#include <cstdio>
#define MAX 10005

int main(){

	double vols = 0, h[MAX][4];
	double pi = acos(-1);
	int n,r,x,y,z,s;

	scanf("%d %d",&n,&s);

	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d",&r,&x,&y,&z);
		h[i][0] = r*1000;
		h[i][1] = x*1000;
		h[i][2] = y*1000;
		h[i][3] = z*1000;


		vols += (4/3)*pi*r*r*r*pow;
	}

	double tgt = (100*100*100-vols)/s;

	printf("%lf\n",tgt); 





	
	return 0;
}
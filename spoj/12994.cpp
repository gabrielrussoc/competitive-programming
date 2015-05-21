#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	
	int n, xc, yc, r, x1, y1, x2, y2,cont = 0,explodi = 0;;
	int AO[2], AB[2];
	float res, eps = 0.00001;

	scanf("%d %d %d %d",&n,&xc,&yc,&r);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		AO[0] = xc-x1;
		AO[1] = yc-y1;
		AB[0] = x2-x1;
		AB[1] = y2-y1;

		res = (float)(fabs(AO[0]*AB[1] - AO[1]*AB[0]))/sqrt(AB[0]*AB[0] + AB[1]*AB[1]);
		if(fabs(res-r) <= eps){
			cont++;
			explodi = 1;
		}
		if(!explodi && res <= r)
			cont++;
	}

	printf("%d\n",cont);


	return 0;
}
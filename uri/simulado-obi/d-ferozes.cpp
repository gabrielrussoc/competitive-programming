#include <cstdio>
#include <cmath>
#define eps 1e-8

using namespace std;

int main(){
	
	int n,aah,x1,y1,l1,x2,y2,l2,ans;
	float diag1,diag2,dist;

	scanf("%d %d",&n,&aah);

	scanf("%d %d %d",&x1,&y1,&l1);

	ans = 1;

	for(int i = 1; i < n; i++){
		scanf("%d %d %d",&x2,&y2,&l2);

		dist = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
		diag1 = (l1*sqrt(2))/2;
		diag2 = (l2*sqrt(2))/2;

		if(dist - diag1 - diag2 > aah){
			ans = 0;
		}
		x1 = x2;
		y1 = y2;
		l1 = l2;
	}

	if(ans)
		printf("YEAH\n");
	else
		printf("OUCH\n");


	return 0;
}
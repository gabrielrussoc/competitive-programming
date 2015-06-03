#include <cmath>
#include <cstdio>
#define eps 1e-8

using namespace std;

int main(){

	double pi = acos(-1);
	
	int t;
	scanf("%d",&t);

	while(t--){

		int k1,k2,v;
		scanf("%d %d %d",&v,&k1,&k2);


		double lo, hi, mid,res1,res2;
		lo = 0;
		hi = pi/2;

		while(hi - lo > eps){

			mid = (hi + lo)/2;
			res1 = k2*v*v*sin(lo)*sin(lo)/20 + k1*v*v*sin(2*lo)/10;
			res2 = k2*v*v*sin(hi)*sin(hi)/20 + k1*v*v*sin(2*hi)/10;

			if(res1 - res2 > eps)
				hi = mid;
			else
				lo = mid;

		}

		printf("%.3lf %.3lf\n",hi,res1);


	}



}
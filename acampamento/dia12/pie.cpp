#include <bits/stdc++.h>
#define eps 1e-7

using namespace std;

int main(){
	
	double pi = acos(-1);
	int t,n,f;
	double v[10004];

	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&f);
		double maxi = 0;
		for(int i = 0; i < n; i++){
			scanf("%lf",&v[i]);
			v[i] = v[i]*v[i]*pi;
			if(v[i] > maxi) maxi = v[i];
		}

		double lo = 0, hi = maxi;

		while(hi - lo > eps){
			double mid = (lo+hi)/2.0;

			int peda = 0;
			for(int i = 0; i < n; i++)
				peda += v[i]/mid;

			if(peda >= f+1)
				lo = mid;
			else
				hi = mid - eps;
		}

		printf("%.4lf\n",lo);

	}


}
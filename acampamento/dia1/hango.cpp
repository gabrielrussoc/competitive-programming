#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define eps 1e-8

using namespace std;

int main(){

	float c;
	while(scanf("%f",&c) && c != 0){
		int ok = 0;
		float ans = 0;
		int i;
		for(i = 1; !ok; i++){
			ans += 1.0/(i+1);
			if(ans - c >= eps) ok = 1;
		}
		printf("%d card(s)\n",i-1);
		
	}


}

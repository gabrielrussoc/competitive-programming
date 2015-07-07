#include <cstdio>

using namespace std;

int main(){

	double m = 0,a;

	for(int i = 0; i < 12; i++){
		scanf("%lf",&a);
		m += a;		
	}

	m = m/12;

	printf("$%.2lf\n",m);
	

}

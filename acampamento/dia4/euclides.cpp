#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n, m, cont;
	while(scanf("%d%d", &n, &m), n!=0 || m!=0){
		if(n<m) swap(n, m);
		if(m==0 || n%m==0){
			printf("Stan wins\n");
		}
		else if(n>2*m){
			printf("Stan wins\n");
		}
		else{
			cont = 0;
			while(m!=0){
				n%=m;
				swap(n, m);
				cont++;
				if(n%m==0){
					printf("%s wins\n", cont%2 == 0 ? "Stan"  : "Ollie");
					break;
				}
				else if(n>2*m){
					printf("%s wins\n", cont%2 == 0 ? "Stan"  : "Ollie");
					break;
				}
			}
		}
	}
}
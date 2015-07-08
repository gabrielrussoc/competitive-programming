#include <cstdio>

using namespace std;

int main(){
	
	int n;
	while(scanf("%d",&n) && n != 0){
		if(n == 1 || n == 2)
			printf("Alice\n");
		else
			printf("Bob\n");
	}

}

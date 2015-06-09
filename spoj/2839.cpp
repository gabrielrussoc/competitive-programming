#include <cstdio>

using namespace std;

int v[105];

int main(){

	int n, foo;
	while(scanf("%d",&n) && n != 0){

		for(int i = 0; i < 105; i++)
			v[i] = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d",&foo);
				if(foo)
					v[j]++;
			}
		}

		int max = 0;
		for(int i = 0; i < n; i++)
			if(v[i] > max)
				max = v[i];

		printf("%d\n",max);

	}
}
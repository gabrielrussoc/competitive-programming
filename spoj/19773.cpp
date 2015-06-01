#include <string>
#include <cstdio>


using namespace std;

int main(){
	
	string pal;
	char aux[42];
	int p;

	scanf("%d",&p);

	while(p--){
		scanf("%s",aux);
		pal = aux;

		int n = pal.size();
		bool f = false;

		for(int i = 0; i < n - 1 && !f; i++){
			if(tolower(pal[i]) >= tolower(pal[i+1]))
				f = true;
		}

		printf("%s: ",pal.c_str());

		if(!f)
			printf("O\n");
		else
			printf("N\n");


	}

	



}
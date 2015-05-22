#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){

	char text[54];

	while(scanf("%s",text) && text[0] != '#'){
		if(next_permutation(text,(text+strlen(text))))
			printf("%s\n",text);
		else
			printf("No Successor\n");
	}

	return 0;
}

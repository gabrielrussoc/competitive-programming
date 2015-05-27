#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	string s, a, b;
	int k;
	char tmp[1005];

	scanf("%s",tmp);
	s = tmp;

	int tam = s.size();

	scanf("%d",&k);

	int tgt = tam/k;
	int ans = 1;

	if(tam%k == 0){
		for(int i = 0; i < tam; i += tgt){
			a = s.substr(i,tgt);
			b = a;
			reverse(a.begin(),a.end());

			if(a.compare(b))
				ans = 0;

		}

		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
		printf("NO\n");



	return 0;
}
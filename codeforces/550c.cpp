#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#define MAXN 103

int main(){

	char s[MAXN];

	scanf(" %s",s);
	int n = strlen(s);

	for(int i = 0; i < n; i++){
		if(s[i] == '8' || s[i] == '0'){
			printf("YES\n%c\n",s[i]);
			return 0;
		}
		for(int j = i + 1; j < n; j++){
			if( ( (s[i]-'0')*10 + s[j]-'0' ) % 8 == 0){
				printf("YES\n%c%c\n",s[i],s[j]);
				return 0;
			}
			for(int k = j + 1; k < n; k++){
				if(((s[i] - '0')*100 + (s[j]-'0')*10 + s[k]-'0') % 8 == 0){
					printf("YES\n%c%c%c\n",s[i],s[j],s[k]);
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	

}
#include <cstdio>

using namespace std;

int main(){
	
	int a[4];
	int ans = 0;
	char s[100009];

	for(int i = 0; i < 4; i++)
		scanf("%d",&a[i]);

	scanf("%s",s);

	for(int i = 0; s[i] != '\0'; i++)
		ans += a[s[i] - '1'];

	printf("%d\n",ans);


}
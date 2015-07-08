#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

bool pal(int n, int t){

	string s, ss;
	for(int i = 0; i < t; i++){
		s += n%10 + '0';
		n /= 10;		
	}
	for(int i = 0; i < t; i++)
		ss += s[t-i-1];

	//printf("%s %s\n",s.c_str(),ss.c_str());

	if(s == ss)
		return true;
	else
		return false; 
}

int main(){

	char aux[15];
	while(scanf(" %s",aux)){
		int t = strlen(aux);
		if(t == 1 && aux[0] == '0')
			break;

		int n = 0, j = 1;
		for(int i = t-1; i >= 0; i--){
			n += j*(aux[i]-'0');
			j *= 10;
		}
		int ans = 0;
		while(!pal(n+ans,t)) ans++;
		printf("%d\n",ans);
			
	}



}

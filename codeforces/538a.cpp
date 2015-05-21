#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(){
	
	string text;
	int len, ops;
	char temp[105];
	
	scanf("%s",temp);
	text = temp;

	len = text.size();

	for(int i = 0; i < len; i++){

		for(int j = i+1; j <= len; j++){
			string s = text.substr(0,i) + text.substr(j);
			if(s == "CODEFORCES"){
				printf("YES\n");
				return 0;
			}
		}

	}

	printf("NO\n");
	




	return 0;
}
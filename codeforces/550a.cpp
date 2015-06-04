#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	
	char aux[100004];
	scanf("%s",aux);
	string s,s1;
	s = aux;
	s1 = aux;
	bool ans;


	size_t it;

	it = s.find("AB");

	if(it != string::npos){
		s.replace(it,2,"aa");
		it = s.find("BA");
		if(it != string::npos)
			ans = true;
		else
			ans = false;
	}
	else
		ans = false;

	if(!ans){
		it = s1.find("BA");

		if(it != string::npos){
			s1.replace(it,2,"aa");
			it = s1.find("AB");
			if(it != string::npos)
				ans = true;
			else
				ans = false;
		}
		else
			ans = false;
	}

	if(ans)
		printf("YES\n");
	else
		printf("NO\n");


}
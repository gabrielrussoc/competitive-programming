#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(){

	map<string,string> dic;
	string s1,s2;
	char aux[12],c;

	while(1){
	
		while(scanf("%c",&c) && c != ' ')		
			s1 += c;
		while(scanf("%c",&c) && c != '\n')
			s2 += c;
	
		dic.insert(make_pair(s2,s1));
		s1.clear();
		s2.clear();
		
		scanf("%c",&c);
		if(c == '\n') break;
		else s1 += c;		
	}
	while(scanf("%s",aux) != EOF){
		s1 = aux;
		if(dic.find(s1) != dic.end())
			printf("%s\n",dic[s1].c_str());
		else
			printf("eh\n");

	}
		

}

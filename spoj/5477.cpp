#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN 10003

int main(){
	
	set<int> al, be, inter;
	int a, b;

	while(scanf("%d %d",&a,&b) && a != 0){

		int c;
		for(int i = 0; i < a; i++){
			scanf("%d",&c);
			al.insert(c);
		}
		for(int i = 0; i < b; i++){
			scanf("%d",&c);
			be.insert(c);
		}

		set<int>::iterator it;
		for(it = al.begin(); it != al.end(); it++){
			if(be.find(*it) != be.end())
				inter.insert(*it);

		}

		int ans = min(al.size(),be.size()) - inter.size();


		printf("%d\n",ans);
		al.clear();
		be.clear();
		inter.clear();
	}
	


}
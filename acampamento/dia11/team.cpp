#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <map>
#include <cstring>

using namespace std;


int main(){

	set<pair<pair<int,int>,int > > s;
	int t,c = 1;
	int v[1000007], vt[1234][2];

	while(scanf("%d",&t) && t != 0){
		memset(v,0,sizeof v);
		memset(vt,0,sizeof vt);
		for(int i = 0; i < t; i++){
			int k;
			scanf("%d",&k);
			for(int j = 0; j < k; j++){
				int a;
				scanf("%d",&a);
				v[a] = i;
			}
		}

		char aux[32];
		int a,k = 0, cont = 0;
		pair<pair<int,int>,int > b;
		set<pair<pair<int,int>,int > >::iterator it;
		printf("Scenario #%d\n",c++);
		while(scanf("%s",aux) && strcmp(aux,"STOP")){
			if(!strcmp(aux,"ENQUEUE")){
				scanf(" %d",&a);
				if(!vt[v[a]][0])
					vt[v[a]][1] = cont++; 
				b.first.first = vt[v[a]][1];
				//cout << "Botei o " << a << " no time " << vt[v[a]][1] << endl;
				vt[v[a]][0]--;
				b.first.second = k++;
				b.second = a;
				s.insert(b);
			}
			else {
				it = s.begin();
				printf("%d\n",it -> second);
				vt[v[it -> second]][0]++;
				s.erase(it);
			}
		}
		printf("\n");
		s.clear();
	}

}
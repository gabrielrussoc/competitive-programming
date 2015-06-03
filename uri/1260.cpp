#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(){
	
	map<string,int> mapa;
	int t;
	char buff[35];
	string ar;
	char aux[35];

	fgets(buff,35,stdin);
	sscanf(buff,"%d",&t);

	bool blank = false;

	while(t--){

		if(blank)
			printf("\n");
		else
			fgets(buff,35,stdin);

		int cont = 0;

		while(fgets(buff,35,stdin)){

			if(buff[0] == '\n')
				break;

			sscanf(buff,"%[^\n]",aux);
			ar = aux;

			if(!mapa.insert(pair<string,int> (ar,1)).second)
				mapa[ar]++;

			cont++;
			
		}

		map<string,int>::iterator it;

		for(it = mapa.begin(); it != mapa.end(); it++){
			double num = (double) 100*(it -> second)/cont;
			printf("%s %.4lf\n",it -> first.c_str(),num);
		}

		mapa.clear();
		blank = true;
		


	}


}
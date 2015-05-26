#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct score {
	int id;
	int penalty;
	int ac[11];
	int wa[10];
} team[101];

bool compare(score a, score b) {	
	if(a.ac[10] > b.ac[10]) 
		return true;
	else if(a.ac[10] == b.ac[10] && a.penalty < b.penalty)
		return true;
	else if(a.ac[10] == b.ac[10] && b.penalty == a.penalty && a.id < b.id)
		return true;
	else
		return false;

}

int main(){
	
	int c, p, t, tc;
	char l, input[100000];
	bool blank = false;

	fgets(input,100,stdin);
	sscanf(input,"%d",&tc);
	fgets(input,100,stdin);

	while(tc){

		for(int i = 1; i < 101; i++){
			team[i].penalty = 0;
			team[i].ac[10] = 0;
			team[i].id = 0;
			for(int j = 1; j < 10; j++){
				team[i].wa[j] = 0;
				team[i].ac[j] = 0;
			}
		}


		while(fgets(input,100,stdin)){

			if(input[0] == '\n')
				break;

			sscanf(input,"%d %d %d %c",&c,&p,&t,&l);
			//printf("qq tc:%d - %d %d %d %c\n",tc,c,p,t,l);

			if(l == 'C'){
				if(!team[c].ac[p]){
					team[c].ac[p]++;
					team[c].penalty += t + 20*team[c].wa[p];
					team[c].ac[10]++;
					team[c].id = c;
				}  
			}
			else if(l == 'I'){
				team[c].wa[p]++;
				team[c].id = c;
			}
			else
				team[c].id = c;

		}

		sort(team+1,team+101,compare);

		if(blank)
			printf("\n");
		blank = true;

		for(int i = 1; i < 101; i++){
			if(team[i].id)
				printf("%d %d %d\n",team[i].id,team[i].ac[10],team[i].penalty);
		}
		tc--;

	}

	return 0;
}
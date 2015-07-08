#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){

	queue< pair<int,int> > q;
	int tab[8][8];
	char x1,x2;
	int y1,y2;

	while(scanf(" %c %d  %c %d",&x1,&y1,&x2,&y2) != EOF){

		memset(tab,-1,sizeof tab);
		int i, j;
		i = x1-'a';
		j = 8-y1;
		tab[i][j] = 0;
	
		q.push(make_pair(i,j));
	
		while(q.size()){
			i = q.front().first;
			j = q.front().second;
			if(i == x2-'a' && j == 8-y2)
				break;
			q.pop();
			if(tab[i+2][j+1] == -1 && i+2 < 8 && j+1 < 8){
				q.push(make_pair(i+2,j+1));
				tab[i+2][j+1] = tab[i][j]+1;
			}
			if(tab[i+2][j-1] == -1 && i+2 < 8 && j-1 >= 0){
				q.push(make_pair(i+2,j-1));
				tab[i+2][j-1] = tab[i][j]+1;
			}
			if(tab[i+1][j+2] == -1 && i+1 < 8 && j+2 < 8){
				q.push(make_pair(i+1,j+2));
				tab[i+1][j+2] = tab[i][j]+1;
			}
			if(tab[i+1][j-2] == -1 && i+1 < 8 && j-2 >= 0){
				q.push(make_pair(i+1,j-2));
				tab[i+1][j-2] = tab[i][j]+1;
			}
			if(tab[i-1][j+2] == -1 && i-1 >= 0 && j+2 < 8){
				q.push(make_pair(i-1,j+2));
				tab[i-1][j+2] = tab[i][j]+1;
			}
			if(tab[i-1][j-2] == -1 && i-1 >= 0 && j-2 >= 0){
				q.push(make_pair(i-1,j-2));
				tab[i-1][j-2] = tab[i][j]+1;
			}
			if(tab[i-2][j+1] == -1 && i-2 >= 0 && j+1 < 8){
				q.push(make_pair(i-2,j+1));
				tab[i-2][j+1] = tab[i][j]+1;
			}
			if(tab[i-2][j-1] == -1 && i-2 >= 0 && j-1 >= 0){
				q.push(make_pair(i-2,j-1));
				tab[i-2][j-1] = tab[i][j]+1;
			}		
		}
		printf("To get from %c%d to %c%d takes %d knight moves.\n",x1,y1,x2,y2,tab[i][j]);
		while(q.size())
			q.pop();
	}
}

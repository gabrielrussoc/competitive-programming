#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

struct guy {
	int id;
	char st;
} p[1000005];

bool comp(guy i, guy j) {
	if(i.st < j.st) 
		return true;
	else if(i.st == j.st) {
		if(i.id < j.id)
			return true;
		else
			return false;
	} else
		return false;
}

int bb1(int lo, int hi, char c){
	int mid = (hi + lo)/2;

	if(lo > hi)
		return -1;

	if(hi == lo){
		if(p[hi].st == c)
			return hi;
		else
			return -1;
	}

	if(p[mid].st >= c)
		return bb1(lo,mid,c);
	else
		return bb1(mid+1,hi,c);
}

int bb(int lo, int hi, char c, int l){
	int mid = (hi + lo)/2;

	if(lo > hi)
		return -1;

	if(hi == lo){
		if(p[hi].id > p[l].id && p[hi].st == c)
			return hi;
		else
			return -1;
	}

	if(p[mid].st > c)
		return bb(lo,mid-1,c,l);
	else if(p[mid].st < c)
		return bb(mid+1,hi,c,l);
	else{
		if(p[mid].id <= p[l].id)
			return bb(mid+1,hi,c,l);
		else
			return bb(lo,mid,c,l);
	}
}

int main(){
	
	char input[1000005];

	scanf("%s",input);
	int t = strlen(input);

	for(int i = 0; i < t; i++){
		p[i].id = i;
		p[i].st = input[i];
	}

	sort(p,p+t,comp);	

	int q;
	scanf("%d",&q);
	char ss[105],at;

	while(q){

		scanf("%s",ss);
		int k = strlen(ss);
		int flag = 0;
		int f,l,pos;

		for(int j = 0; j < k && !flag; j++){
			at = ss[j];

			if(j == 0)
				f = l = bb1(0,t-1,at);

			if(l>=0 && j != 0){
				pos = bb(0,t-1,at,l);

				l = pos;
			}
			if(l < 0)
				flag = 1;

		}

		if(!flag)
			printf("Matched %d %d\n",p[f].id,p[l].id);
		else
			printf("Not matched\n");

		q--;
	}


	return 0;
}
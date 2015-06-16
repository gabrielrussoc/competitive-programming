#include <cstdio>
#include <string>

using namespace std;

int main(){
	
	char aux[100004];
	scanf("%s",aux);
	string a = aux;
	scanf("%s",aux);
	string b = aux;
	scanf("%s",aux);
	string c = aux;

	int max_b, max_c;
	max_b = a.size()/b.size();
	max_c = a.size()/c.size();

	int a_qtd[26] = {0};
	int b_qtd[26] = {0};
	int c_qtd[26] = {0};
	int foo[26];

	for(int i = 0; i < a.size(); i++)
		a_qtd[a[i] - 'a']++;
	for(int i = 0; i < a.size(); i++)
		b_qtd[b[i] - 'a']++;
	for(int i = 0; i < a.size(); i++)
		c_qtd[c[i] - 'a']++;

	for(int i = 0; i < max_b; i++){		
		foo = a_qtd;
		for(k = 0; k < 26; k++){
			foo[k] -= (i+1)*b_qtd[k];
		}
		for(int j = 0; j < max_c; j++){
			for(k = 0; k < 26; k++){
				foo[k] -= (j+1)*c_qtd[k];
			}
		}
	}



}
#include <stdio.h>
#include <string.h>

int mod28(int a){
	int res;
	if(a%28 >= 0)
		res = a % 28;
	else
		res = a % 28 + 28;

	return res;
}

int main(){
	
	char ciphertext[100],plaintext[100];
	int ciphercode[100], plaincode[100];
	int n, i, k;

	while(scanf("%d",&k) && k != 0){

		scanf("%s",ciphertext);

		n = strlen(ciphertext);

		for(i = 0; i < n; i++){
			if(ciphertext[i] == '.')
				ciphercode[i] = 27;
			else if(ciphertext[i] == '_')
				ciphercode[i] = 0;
			else
				ciphercode[i] = ciphertext[i] - 'a' + 1;
		}

		for(i = 0; i < n; i++)
			plaincode[(k * i) % n] = mod28(ciphercode[i] + i);

		for(i = 0; i < n; i++){
			if(plaincode[i] == 27)
				plaintext[i] = '.';
			else if(ciphercode[i] == 0)
				plaintext[i] = '_';
			else
				plaintext[i] = plaincode[i] + 'a' - 1;

		}

		printf("%s\n",plaintext);
	}

	return 0;
}
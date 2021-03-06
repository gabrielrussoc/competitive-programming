#include <stdio.h>

int main(){
	
	char tel[31];
	int i;

	while (scanf(" %s", tel) != EOF){
		for (i = 0; tel[i] != '\0'; i++) {

			/*digitos sem correspondencia numerica*/
			if (tel[i] == '-' || tel[i] == '0' || tel[i] == '1')
				printf("%c",tel[i]);

			/*digitos até o O (numero 7)*/
			else if( ((tel[i] - 'A') /  3) + 2 <= 7)
				printf("%d",((tel[i] - 'A') /  3) + 2);

			/*letra S especial, porque tambem fica no 7*/
			else if( (tel[i] - 'A') == 18)
				printf("7");

			/*digitos até Y (numeros 8 e 9)*/
			else if( ((tel[i] - 'A' - 1) /  3) + 2 <= 9)
				printf("%d",((tel[i] - 'A' - 1) /  3) + 2);

			/*letra Z especial, porque tambem fica no 9*/
			else
				printf("9");		
		}
		printf("\n");
	}
	
	

	return 0;
}

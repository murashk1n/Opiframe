#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

char checkWhoWin(char a, char b){
	if(a == 'k' && b == 's' || a == 's' && b == 'k'){
		return 'k';
	}else if(a == 'k' && b == 'p' || a == 'p' && b == 'k'){
		return 'p';
	}else if(a == 's' && b == 'p' || a == 'p' && b == 's'){
		return 's';
	}
}

int main(){
	//Kivi sakset paperia
	srand(time(0));
	int random = 1 + rand() % 3;
	printf("Welcome to kivi sakset paperia\n\n");
	printf("\nYour choise: ");
	char answer = ' ';
	scanf("%s", &answer);
	char compChoise;

	switch (random){
			case 1:
				compChoise = 'k';
				break;
			case 2:
				compChoise = 's';
				break;
			case 3:
				compChoise = 'p';
				break;
	}
	printf("\nComputer choise: %c", compChoise);

	if(compChoise == answer){
		printf("\nDead heat\n");
	}else	if(answer == checkWhoWin(answer,compChoise)){
		printf("\nYou win!\n");
	}else if(compChoise == checkWhoWin(answer, compChoise)){
		printf("\nComputer win!\n");
	}else{
		printf("\nIllegal choice\n");
	}
    return 0;
}
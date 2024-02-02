#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h> 

int main(){

	// Computer guess the number
	int low = 0;
	int high = 100;
	int attempts = 0;
	char answer;
	int turn = 0;

	printf("Welcome to Guess My Number\n\n");
	while (true){
		turn = (low + high)/2;
		printf("\nYour secret number is %d\n",  turn);
		printf("\nYour answer: ");
		scanf("%s", &answer);
    char something = putchar(answer);
		attempts++;
		if(something == 'l'){
			low = turn;
		}else if(something == 'h'){
			high = turn;
		}else if(something == 'y'){
			printf("\nThat's it! I got it in %d attempts!\n", attempts);
			break;
		}else{
			printf("\nIllegal choice\n");
		}
	}
    return 0;
}
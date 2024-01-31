#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h> 

int main(){

	// I guess the number
	
	// int secretNumber = rand() % 100 + 1; 
	// int attempts = 0;
	// int guess;
	
  // printf("\tWelcome to Guess My Number\n\n");
  // printf("Try to guess the number! Good luck!\n");

	// do{
  //   printf("Enter a guess: \n");
	// 	scanf("%d",&guess);
	// 	++attempts;
	// 	if (guess > secretNumber){
	// 		printf("Too high!\n\n");
	// 	}
	// 	else if (guess < secretNumber){
	// 		printf("Too low!\n\n");
	// 	}
	// 	else{
	// 		printf("\nThat's it! You got it in  %d  attempts!\n", attempts);
	// 	}
	// } while (guess != secretNumber);


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
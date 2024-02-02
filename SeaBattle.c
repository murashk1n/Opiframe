#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

    const char X = 'X';
    const char O = 'O';
    const char SHIP = 'S';

int getRandomNumber(int min, int max);
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void initializeships(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int isValidCoordinate(int x, int y);

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '_';
        }
    }
}

void initializeships(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int k = 0; k < BOARD_SIZE*2; k++) {
        int shipRow = getRandomNumber(0, BOARD_SIZE - 1);
        int shipCol = getRandomNumber(0, BOARD_SIZE - 1);

        if(board[shipRow][shipCol] == SHIP){
            continue;
        }
        board[shipRow][shipCol] = SHIP;
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);}
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|");
    }
    printf("\n\n");
}

int isValidCoordinate(int x, int y) {
    return x > 0 && x <= BOARD_SIZE && y > 0 && y <= BOARD_SIZE;
}

int main() {

    char playerBoard[BOARD_SIZE][BOARD_SIZE];
    char computerBoard[BOARD_SIZE][BOARD_SIZE];
    char playerBoardToAttack[BOARD_SIZE][BOARD_SIZE];

    initializeBoard(playerBoard);
    initializeships(playerBoard);

    initializeBoard(playerBoardToAttack);

    initializeBoard(computerBoard);
    initializeships(computerBoard);

    srand(time(NULL));

    printf("Welcome to the Sea Battle Game!\n");
    while (1) {
        system("clear");
        printf("Your Board:\n");
        printBoard(playerBoard);

        printf("\nBoard to attack:\n");
        printBoard(playerBoardToAttack);

        // players's turn
        int playerGuessRow, playerGuessCol;
        printf("Enter your guess (row and column, both between 0 and %d): ", BOARD_SIZE - 1);
        scanf("%d %d", &playerGuessRow, &playerGuessCol);

        if(isValidCoordinate == 0){
            printf("Invalid guess. Try again.\n");
            continue;
        }

        if (computerBoard[playerGuessRow][playerGuessCol] == SHIP) {
            printf("Congratulations! You hit an enemy ship!\n");
            playerBoardToAttack[playerGuessRow][playerGuessCol] = X;
            computerBoard[playerGuessRow][playerGuessCol] = X;
        } else {
            printf("Oops! You missed.\n");
            playerBoardToAttack[playerGuessRow][playerGuessCol] = O;
        }

        int playerWon = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (computerBoard[i][j] == SHIP) {
                    playerWon = 0;
                    break;
                }
            }
            if (!playerWon) {
                break;
            }
        }

        if (playerWon) {
            printf("Congratulations! You sank all enemy ships. You win!\n");
            break;
        }

        // Computer's turn
        int computerGuessRow = getRandomNumber(0, BOARD_SIZE - 1);
        int computerGuessCol = getRandomNumber(0, BOARD_SIZE - 1);

        if (playerBoard[computerGuessRow][computerGuessCol] == SHIP) {
            printf("The enemy hit one of your ships!\n");
            playerBoard[computerGuessRow][computerGuessCol] = X;
        } else {
            printf("The enemy missed.\n");
            playerBoard[computerGuessRow][computerGuessCol] = O;
        }
        int computerWon = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (playerBoard[i][j] == SHIP) {
                    computerWon = 0;
                    break;
                }
            }
            if (!computerWon) {
                break;
            }
        }
        if (computerWon) {
            printf("Game over! The enemy sank all your ships. You lose!\n");
            break;
        }
    }
    return 0;
}


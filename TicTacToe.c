#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

  const char X = 'X';
  const char O = 'O';
  const char EMPTY = ' ';
  char computer = ' ';
  char player = ' ';
  //this move need to medium level
  const int COMP_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
  int answer;
  int count;
  char board[9] = {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY, EMPTY};
  int isWinner = 0;
  int move = 1;
  int level;
  int nextMove = 0;

  const int winComb[8][3] = { 
  { 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 } };



int checkWinRow(char c){
  for (int row = 0; row < 8; row++){
    //  _ | c | c
		if ((board[winComb[row][0]] == EMPTY) && (board[winComb[row][1]] == board[winComb[row][2]]) && (board[winComb[row][1]] == c)){
      nextMove = winComb[row][0];
      return 1; 
    }
    //  c | _ | c
    if ((board[winComb[row][0]] == board[winComb[row][2]]) && (board[winComb[row][1]] == EMPTY) && (board[winComb[row][2]] == c)){
			nextMove = winComb[row][1];
      return 1;
		}
    //  c | c | _
    if ((board[winComb[row][0]] == board[winComb[row][1]]) && (board[winComb[row][1]] == c) && (board[winComb[row][2]] == EMPTY)){
			nextMove = winComb[row][2];
      return 1;
		}
	}
}

void displayBoard(char board[8]){
	printf("\n\t %c | %c | %c \t O | 1 | 2", board[0],board[1],board[2]);
	printf("\n\t----------- \t-----------");
	printf("\n\t %c | %c | %c \t 3 | 4 | 5", board[3],board[4],board[5]);
	printf("\n\t----------- \t-----------");
	printf("\n\t %c | %c | %c \t 6 | 7 | 8", board[6],board[7],board[8]);
	printf("\n\n");
}

int isCellEmpty(int cell){
  return board[cell] == EMPTY;
}

int chooseCornerCell(){
  for (int i = 0; i < 9; i+=2){
    if(i == 4){
      continue;
    }
    if(isCellEmpty(i) == 1){
      return i;
    }
  }
  return 10;
}

int randomMove(char c){
  while(1){
  srand(time(0));
	int random = rand() % 9;
  if(isCellEmpty(random)==1){
    board[random] = c;
      return 1;
    }
  }
  return 0;
}

int computerTurnHardLevel(){
  //in this strategy the best move is center cell
  if(move == 1 || move == 2){
    if (isCellEmpty(4)==1){
      board[4] = computer;
      move++;
    }else{
      //or corner cell
      board[chooseCornerCell()] = computer;
      move++;
    }
  }else{
    //computer check can player win
    if(checkWinRow(computer)==1){
      board[nextMove] = computer;
    //computer check can it win
    }else if(checkWinRow(player)==1){
      board[nextMove] = computer;
    //best move is corner cell
    }else if (chooseCornerCell()!=10){
      board[chooseCornerCell()] = computer;
    }else{
    //usually it is last move or last two moves
      randomMove(computer);
    }
  }
}

char checkWinner(){
  for (int row = 0; row < 8; row++){
		if ((board[winComb[row][0]] != EMPTY) && (board[winComb[row][0]] == board[winComb[row][1]]) &&
			(board[winComb[row][1]] == board[winComb[row][2]])){
			isWinner = 1;
      return board[winComb[row][0]];
		}
	}
  return EMPTY;
}

void whoWinner() {
    char winner = checkWinner();
    if (winner == player) {
        printf("\n You win!\n");
    } else if (winner == computer) {
        printf("\n Computer win!\n");
    } else {
        printf("\nDead heat\n");
    }
}

int isFreeCell(){
  for(int i = 0; i < 9; i++){
    if (board[i] == EMPTY){
      return 1;
    }
  }
  isWinner = 1;
  return 0;
}

int computerTurnMediumLevel(){
  while(isWinner != 1){
    if (isCellEmpty(COMP_MOVES[count])){
        board[COMP_MOVES[count]] = O;
        break;
    }count++;
  }
}

void playerTurn(){
  while(isWinner != 1){
    if(isFreeCell()==1){
      printf("\nYour turn: ");
	    scanf("%d", &answer);
      if(answer > 8 || answer < 0){
        printf("\nIllegal move! Choose number between 0 and 8!\n\n");
        continue;
      }
      if(isCellEmpty(answer) == 1){
        board[answer] = player;
        displayBoard(board);
        break;
      }else{
        printf("\nThat square is already occupied\n");
        continue;
      }
    }else{
      break;
    }
  }
}

void computerTurn(){
  printf("\nComputer turn: ");
    if(isFreeCell()==1){
      if(level == 2){
        computerTurnMediumLevel();
      }else if(level == 3){
        computerTurnHardLevel();
      }else{
        randomMove(computer);
      }
    }
  displayBoard(board);
}

void startMenu(){
  printf("Welcome to Tic-Tac-Toe.\n");
  printf("Choose level 1-easy, 2-medium, 3-hard\n");
  printf("\nYour choose: \t");
	scanf("%d", &level);
  srand(time(0));
	int random = rand() % 100;
  if(random>=50){
    printf("\nRandom choose: X for you");
    player = X;
    computer = O;
  }else{
    printf("\nRandom choose: O for you");
    player = O;
    computer = X;
  }
  printf("\nMake your move by entering a number, 0-8");
  displayBoard(board);
}

int main(){
  startMenu();
  while (isWinner != 1){
    if(player == X){
      playerTurn();
      checkWinner();
      computerTurn();
    }else{
      computerTurn();
      checkWinner();
      if(isFreeCell == 0){
      break;
      }
      playerTurn();
    }
    if(isFreeCell == 0){
      break;
    }
    checkWinner();
  }
  whoWinner();
  return 0;
}
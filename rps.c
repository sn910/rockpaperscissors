#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void PlayRockPaperScissorsGame();
char GetComputerMove();
char GetPlayerMove();

int main() {
	char c;
	printf("Welcome to Rock, Paper, Scissors! Press 'q' to quit or any other key to continue: \n"); //prints starting statement
	scanf("%c", &c); //gets player's input to continue playing
	getchar();
	while (c != 'q') { //while the player does not type q to quit
		PlayRockPaperScissorsGame(); //main game method to play the game
		printf("Press 'q' to quit or any other key to continue: \n");
		scanf("%c", &c); //gets player's input to continue playing
		getchar();
	}
	printf("Bye Bye !");
}

char GetPlayerMove() {
	char options[3] = { 'r', 's', 'p' }; //options available for player to use in game
	char pm; //the player's move for the game
	printf("Enter your move (r for rock, p for paper, s for scissors): \n");
	scanf("%c", &pm); //gets player's move to use against computer
	getchar();
	while (pm != options[0] && pm != options[1] && pm != options[2]) { //checks to see if the input is a valid input given from r, p, or s
		printf("Invalid move. Enter your move (r for rock, p for paper, s for scissors): \n"); //statement if player does not enter r, p, or s
		scanf("%c", &pm); //gets player's input for their move
		getchar();
	}
	return pm;
}

char GetComputerMove() {
	char options[3] = { 'r', 's', 'p' }; //options available for computer to use in game
	int random = rand() % 3; //chooses a random value out of r, p, or s
	char comp;
	comp = options[random]; //the computer's move for the game
	printf("Computer's move: %c \n", comp);
	return comp;
}

void PlayRockPaperScissorsGame() {
	char pm = GetPlayerMove(); //calling the player's move
	char cm = GetComputerMove(); //calling the computer's move
	if (pm == cm) { //checks to see the game results
		printf("It's a tie! \n"); //prints this statement if the player and computer moves are the same
	}
	else if ((pm == 'r' && cm == 'p') || (pm == 's' && cm == 'r') || (pm == 'p' && cm == 's')) { //checks to see the game results
		printf("Computer wins! \n"); //prints this statement if the computer wins
	}
	else if ((pm == 'p' && cm == 'r') || (pm == 'r' && cm == 's') || (pm == 's' && cm == 'p')) { //checks to see the game results
		printf("You win! \n"); //prints this statement if the player wins
	}

}

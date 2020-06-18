// Erik Roeckel (efr11)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int random_range(int start, int end){
        return rand() % (end - start + 1);
}

int main(){
	srand((unsigned int)time(NULL));
	char diff[4];
	int numColors;
	printf("How many colors would you like to play with? (3-6)\n");
	fgets(diff, 4, stdin);
	sscanf(diff, "%d", &numColors);
	
	while(numColors < 3 || numColors > 6){
		printf("Invalid input, please enter a number 3-6\n");
		printf("How many colors would you like to play with? (3-6)\n");
		fgets(diff, 4, stdin);
		sscanf(diff, "%d", &numColors);
		}
	char colors[numColors];
	//char answer[3];
	int i;
	for(i = 0; i < 4; i++){
		colors[i] = random_range(0, numColors);
		//answer[i] = colors[r];
		// got really lost with how to assign letters to each one of the numbers

	}
	char userGuess[3];
	int index = 0;
	int correctAns = 0;
	while(index < 10 && correctAns == 0)
		{
			printf("Please guess 4 colors according to the first letter of the color name\n");
			fgets(userGuess, 3, stdin);
			//***********************************************
			//if(userGuess)******************************
			index++;

		}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Problems.h"

void intializeProblems(problems *wordProblem) {

	wordProblem[0].type = UNSCRAMBLE;
	wordProblem[0].problem = "Unscramble the following word: ehurbgceeres";
	wordProblem[0].answer = "cheeseburger";

	wordProblem[1].type = UNSCRAMBLE;
	wordProblem[1].problem = "Uscramble the following word: heastgtpi";
	wordProblem[1].answer = "spaghetti";

	//add rest of the word problems
}

int displayProblem(problems *wordProblem, int numProblems) {

	srand(time(NULL));

	int randomProblem = rand() % numProblems;



	printf(wordProblem[randomProblem].problem);			//Need to change this to act appropriately according to the type of word problem



	wordProblem[randomProblem] = wordProblem[numProblems];

	getPlayerAnswer(wordProblem, randomProblem);

	numProblems--;

	return numProblems;
}

void getPlayerAnswer(problems *wordProblem, int currentProblemNum) {

	char input;

	scanf_s("%s", input, MAX_INPUT_LENGTH);

	if (!strcmp(wordProblem[currentProblemNum].answer, input)) {

		//sends information to point system module as a correct answer

	}
	
	else {

		//sends information to point system module as an incorrect answer

	}



}


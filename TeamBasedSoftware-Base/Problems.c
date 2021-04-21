#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include "Problems.h"
#include "Adventure.h"
#include "Leaderboard.h"

void intializeProblems(problems *wordProblem) {

	wordProblem[0].type = UNSCRAMBLE;
	strcpy(wordProblem[0].problem, "\n\nUnscramble the following word: cnoffi");
	strcpy(wordProblem[0].answer, "coffin");

	wordProblem[1].type = UNSCRAMBLE;
	strcpy(wordProblem[1].problem, "\n\nUnscramble the following word: gdroan");
	strcpy(wordProblem[1].answer, "dragon");

	wordProblem[2].type = UNSCRAMBLE;
	strcpy(wordProblem[2].problem, "\n\nUnscramble the following word: ardizw");
	strcpy(wordProblem[2].answer, "wizard");

	wordProblem[3].type = UNSCRAMBLE;
	strcpy(wordProblem[3].problem, "\n\nUnscramble the following word: gebrru");
	strcpy(wordProblem[3].answer, "burger");

	wordProblem[4].type = UNSCRAMBLE;
	strcpy(wordProblem[4].problem, "\n\nUnscramble the following word: dhlies");
	strcpy(wordProblem[4].answer, "shield");

	wordProblem[5].type = UNSCRAMBLE;
	strcpy(wordProblem[5].problem, "\n\nUnscramble the following word: poartl");
	strcpy(wordProblem[5].answer, "portal");

	wordProblem[6].type = RIDDLE;
	strcpy(wordProblem[6].problem, "\n\nI'm tall when I'm young, and I'm short when I'm old. What am I?");
	strcpy(wordProblem[6].answer, "candle");
	
	wordProblem[7].type = RIDDLE;
	strcpy(wordProblem[7].problem, "\n\nThe more of this there is, the less you see. What is it?");
	strcpy(wordProblem[7].answer, "darkness");
	
	wordProblem[8].type = RIDDLE;
	strcpy(wordProblem[8].problem, "\n\nI follow you all the time and copy your every move, but you can't touch me or catch me. What am I?");
	strcpy(wordProblem[8].answer, "shadow");

	wordProblem[9].type = RIDDLE;
	strcpy(wordProblem[9].problem, "\n\nI am always hungry and will die if not fed, but whatever I touch will soon turn red. What am I?");
	strcpy(wordProblem[9].answer, "fire");

	wordProblem[10].type = RIDDLE;
	strcpy(wordProblem[10].problem, "\n\nThe more you take, the more you leave behind. What am I?");
	strcpy(wordProblem[10].answer, "footsteps");

	wordProblem[11].type = RIDDLE;
	strcpy(wordProblem[11].problem, "\n\nI don't have eyes, but once I did see. Once I had thoughts, but now I'm white and empty.");
	strcpy(wordProblem[11].answer, "skull");

	wordProblem[12].type = HANGMAN;
	strcpy(wordProblem[12].problem, "\n\nGuess letters to try and figure out the word: ");
	strcpy(wordProblem[12].answer, "dungeon");

	wordProblem[13].type = HANGMAN;
	strcpy(wordProblem[13].problem, "\n\nGuess letters to try and figure out the word: ");
	strcpy(wordProblem[13].answer, "treasure");

	wordProblem[14].type = HANGMAN;
	strcpy(wordProblem[14].problem, "\n\nGuess letters to try and figure out the word: ");
	strcpy(wordProblem[14].answer, "grave");
}

int displayProblem(problems *wordProblem, int numProblems) {

	srand(time(NULL));
	int randomProblem = rand() % numProblems;	//randomly generated number used to select an unused problem

	if (wordProblem[randomProblem].type == UNSCRAMBLE || wordProblem[randomProblem].type == RIDDLE) {	//for unscramble problems and riddles
		for (int attempts = 1; attempts <= 4; attempts++)
		{
			printf("\n%s\n", wordProblem[randomProblem].problem);
			if (getPlayerAnswer(wordProblem, randomProblem, attempts))
				break;
		}
	}

	else if (wordProblem[randomProblem].type == HANGMAN) {	//for hangman problems
		hangman(wordProblem, randomProblem);
	}

	numProblems--;											//decreases the current number of available problems by 1
	wordProblem[randomProblem] = wordProblem[numProblems];	

	return numProblems;
}


int getPlayerAnswer(problems *wordProblem, int currentProblemNum, int currentAttempt) {

	char input[MAX_INPUT_LENGTH];

	scanf_s("%s", input, MAX_INPUT_LENGTH);

	if (!strcmp(wordProblem[currentProblemNum].answer, input)) {

		//should send information(like the currentAttempt #) to point system module as a correct answer
		return 1;
	}
	
	else {

		//should this send information to point system module as an incorrect answer?
		//or not communicate with point system module at all?
		return 0;
	}

}



void hangman(problems* wordProblem, int problemNum) {

	int wordLength = strlen(wordProblem[problemNum].answer);

	char hiddenWord[MAX_INPUT_LENGTH];

	for (int i = 0; i < wordLength; i++)
	{
		hiddenWord[i] = "-";
	}

	int numIncorrect = 0;
	bool continueGame = true;

	printf("\n%s\n", wordProblem[problemNum].problem);

	while (continueGame)
	{
		printf("\n\nIncorrect guesses: %d\n", numIncorrect);

		for (int i = 0; i < wordLength; i++)
		{
			if (hiddenWord[i] == wordProblem[problemNum].answer[i])
				printf("%c", wordProblem[problemNum].answer[i]);

			else
				printf("-");
		}

		printf("\nEnter a letter for your guess: ");

		char userInput = tolower(_getch());

		printf("%c", userInput);

		bool correctGuess = false;

		for (int i = 0; i < wordLength; i++)
		{
			if (userInput == wordProblem[problemNum].answer[i])
			{
				hiddenWord[i] = wordProblem[problemNum].answer[i];
				correctGuess = true;
			}
		}

		if (!correctGuess)
			numIncorrect++;

		bool win = true;

		for (int i = 0; i < strlen(wordProblem[problemNum].answer); i++)
		{
			if (hiddenWord[i] != wordProblem[problemNum].answer[i])
				win = false;
		}

		if (numIncorrect == MAX_INCORRECT_GUESSES)
		{
			//print out message for failing hangman
			printf("\nYou lose...\n");
			continueGame = false;
		}

		else if (win) {
			//print out message for completing hangman
			printf("\nYou completed it!...\n");
			continueGame = false;
		}
	}

	return 0;
}
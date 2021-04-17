#pragma once

#define NUM_PROBLEMS 15
#define MAX_COMPLETE 10
#define MAX_INPUT_LENGTH 200
#define MAX_INCORRECT_GUESSES 6
#define UNSCRAMBLE 1
#define RIDDLE 2
#define HANGMAN 3

typedef struct problems {
	int type;
	char problem[MAX_INPUT_LENGTH];
	char answer[MAX_INPUT_LENGTH];
}problems;

void intializeProblems(problems*);

int displayProblem(problems*, int);

int getPlayerAnswer(problems*, int, int);

void hangman(problems*, int);
#pragma once

#define NUM_PROBLEMS 15
#define MAX_INPUT_LENGTH 100
#define UNSCRAMBLE 1
#define RIDDLE 2
#define HANGMAN 3

typedef struct problems {
	int type;
	char problem;
	char answer;
}problems;

void intializeProblems(problems*);

int displayProblem(problems*, int);

void getPlayerAnswer(problems*, int);

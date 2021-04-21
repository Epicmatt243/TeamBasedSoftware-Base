#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "Problems.h"
#include "Adventure.h"
#include "Leaderboard.h"

int main() {

	int readyProblems = NUM_PROBLEMS;
	int readyStories = NUM_PROBLEMS;
	struct problems wordProblem[NUM_PROBLEMS];
	char *storyElements[NUM_PROBLEMS];

	intializeProblems(wordProblem);
	intializeStory(storyElements);	

	mainMenu();

	for (int i = 0; i <= MAX_COMPLETE; i++) {

		readyStories = displayStory(storyElements, readyStories);
		
		readyProblems = displayProblem(wordProblem, readyProblems);

		system("cls");		//clears the command window

		//needs to deal with saving the final score (and outputting it before quitting program?)

	}
	



	return 0;

}
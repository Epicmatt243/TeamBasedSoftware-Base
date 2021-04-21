#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "Problems.h"
#include "Adventure.h"
#include "Leaderboard.h"

int main() {
	system("cls");

	char select;
	printf("****************************************************************************\n");
	printf("*                                                                          *\n");
	printf("*                                1.start game                              *\n");
	printf("*                                2.leaderboard                             *\n");
	printf("*                                                                          *\n");
	printf("****************************************************************************\n");
	select = _getch();
	if (select == '1')
	{
		gamebegin();
		saveLeaderboard();
	}
	if (select == '2')
	{
		leaderboard();
	}

	return 0;

}

int gamebegin() 
{
	int readyProblems = NUM_PROBLEMS;
	int readyStories = NUM_PROBLEMS;
	struct problems wordProblem[NUM_PROBLEMS];
	char* storyElements[NUM_PROBLEMS];

	intializeProblems(wordProblem);
	intializeStory(storyElements);

	for (int i = 0; i <= MAX_COMPLETE; i++) {

		readyStories = displayStory(storyElements, readyStories);

		readyProblems = displayProblem(wordProblem, readyProblems);

		system("cls");		//clears the command window

		//needs to deal with saving the final score (and outputting it before quitting program?)

	}
	return 0;
}
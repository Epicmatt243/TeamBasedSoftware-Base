#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "Problems.h"
#include "Adventure.h"

int main() {

	int readyProblems = NUM_PROBLEMS;
	int readyStories = NUM_PROBLEMS;
	struct problems wordProblem[NUM_PROBLEMS];
	char *storyElements[NUM_PROBLEMS];

	intializeProblems(wordProblem);
	intializeStory(storyElements);			//theres a bug here where they aren't properly intialized, I havent gotten the chance to really figure it out yet

	for (int i = 0; i <= MAX_COMPLETE; i++) {

		readyStories = displayStory(storyElements, readyStories);		//theres currently a bug with intializing the story elements
		
		readyProblems = displayProblem(wordProblem, readyProblems);



	}
	



	return 0;

}
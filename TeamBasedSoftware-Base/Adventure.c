#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Problems.h"
#include "Adventure.h"

void intializeStory(char *storyElements[NUM_PROBLEMS]) {

	storyElements[0] = "\n\nYou find a large temple that appears to be made of gold... \nThe front door is locked, and on it is a sentence you can't quite make out...\n";

	storyElements[1] = "\n\nAfter travelling alone for an hour, you come across a grave. The gravestone has your name on it, but the date is illegible...\n";

	storyElements[2] = "\n\nYou turn the corner and find a McDonalds...  You're amazed as to how something like that exists in a place like this.\nYou decide to go order a big mac...\n";

	storyElements[3] = "\n\nYou find yourself walking down a set of stairs which feels like they never end...\n";

	storyElements[4] = "\n\nYou hear the sound of rain... It's quite calming, so you decide to stop and rest for a bit...\n";
	
	storyElements[5] = "\n\nAs you continue walking to your final destination, you can't help but think that something or someone is watching you...\n";

	storyElements[6] = "\n\nYou see a light in the distance, but it doesn't appear to grow or shrink when you walk towards it...\n";

	storyElements[7] = "\n\nYou haven't seen another person in days, you continue to wander aimlessly, starting to get desperate for food...\n";

	storyElements[8] = "\n\nYou lie down for a quick break, you slowly end up falling asleep...\n";

	storyElements[9] = "\n\nYou smell the scent of... fried chicken? You grow curious and try to find the source...\n";

	storyElements[10] = "\n\nYou find a piece of paper on the ground...\nIt's a map, you have no idea where you are, but you still try to read it.\n";

	storyElements[11] = "\n\nYou come to a dead end, but when you turn around, the previous path has shifted into something entirely different...\n";

	storyElements[12] = "\n\nYou find a large open space, with a lone door in the middle of it.  When you try to open it, the head of a dwarf pokes out from the side...\n";

	storyElements[13] = "\n\nA loud voice appears out of nowhere, speaking a language you've never heard...  You attept to understand it...\n";

	storyElements[14] = "\n\nYou see something shiny lying in the dirt, it looks like a ring...\nOn it reads: \"ash nazg thrakatulûk agh burzum-ishi krimpatul...\"\n";
	
}

int displayStory(char *storyElements[NUM_PROBLEMS], int numStories) {

	srand(time(NULL));
	int randomStory = rand() % numStories;				//randomly generated number used to select an unused story piece

	printf("\n%s\n", storyElements[randomStory]);

	storyElements[randomStory] = storyElements[numStories];
	numStories--;											//decreases the current number of available problems by 1

	return numStories;
}
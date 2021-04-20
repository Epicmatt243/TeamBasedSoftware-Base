#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "Problems.h"
#include "Leaderboard.h"
#include "PointSys.h"

struct levels levelArr[MAX_LEVELS];

int levelNum;

void checkAnswer(bool correct, int probType, int attempt) {		//Word problems module will call this in the "getPlayerAnswer" and at the end of the "hangman" functions.

	if (levelNum == 0)
	{
		levelNum++;
	}
	if (correct == true || attempt == 6)
	{
		levelInfo(levelArr, probType, correct, attempt);
		levelNum++;
		return;
	}
	else
	{
		return;
	}
}


void levelInfo(levels* levelArr, int probType, bool correct, int attempts) {

	int i = levelNum - 1;

	levelArr[i].num = levelNum;
	levelArr[i].tries = attempts;
	levelArr[i].type = probType;
	levelArr[i].complete = correct;
	levelArr[i].points = levelScore(levelArr[i].tries, levelArr[i].type, levelArr[i].complete);
}


int levelScore(int lvlTries, int lvlType, bool complete) {

	int initialScore = 128;
	int tempScore;
	int lvlScore;
	double dLvlTries = (double)lvlTries;
	switch (lvlTries)
	{
	case 1:
		tempScore = initialScore;
		switch (lvlType)
		{
		case 1:
			lvlScore = tempScore * 2;
			break;

		case 2:
			lvlScore = tempScore * 3;
			break;
		case 3:

			lvlScore = tempScore * 4;
			break;
		}
		break;

	case 2:
		tempScore = initialScore;
		switch (lvlType)
		{
		case 1:
			lvlScore = tempScore * 1.5;
			break;

		case 2:
			lvlScore = tempScore * 2;
			break;

		case 3:
			lvlScore = tempScore * 2.5;
			break;
		}
		break;

	case 3:
		tempScore = initialScore;
		switch (lvlType)
		{
		case 1:
			lvlScore = tempScore;
			break;
		case 2:
			lvlScore = tempScore;
			break;
		case 3:
			lvlScore = tempScore;
			break;
		}
		break;

	case 4:
		tempScore = initialScore - (initialScore >> 2);
		switch (lvlType)
		{
		case 1:
			lvlScore = tempScore;
			break;
		case 2:
			lvlScore = tempScore;
			break;
		case 3:
			lvlScore = tempScore;
			break;
		}
		break;

	case 5:
		tempScore = initialScore - (initialScore >> 1);
		switch (lvlType)
		{
		case 1:
			lvlScore = tempScore;
			break;
		case 2:
			lvlScore = tempScore;
			break;
		case 3:
			lvlScore = tempScore;
			break;
		}
		break;

	case 6:
		if (complete == true)
		{
			tempScore = initialScore - ((initialScore >> 1) + (initialScore >> 2));
			switch (lvlType)
			{
			case 1:
				lvlScore = tempScore;
				break;

			case 2:
				lvlScore = tempScore;
				break;

			case 3:
				lvlScore = tempScore;
				break;
			}
		}
		else if (complete == false)
		{
			lvlScore = 0;
			break;
		}
		break;
	default:
		return;
	}
	printf("%d\n", lvlScore);
	return lvlScore;
}


int finalScore() {

	int scoreSum = 0;
	for (int i = 0; i <= MAX_LEVELS; i++)
	{
		scoreSum += levelArr[i].points;
	}
	return scoreSum;
}
#pragma once

#define MAX_LEVELS 10

typedef struct levels {
	int num;
	int tries;
	int type;
	int points;
	bool complete;
}levels;

void checkAnswer(bool, int, int);

void levelInfo(levels*, int, bool, int);

int levelScore(int, int, bool);

int finalScore();
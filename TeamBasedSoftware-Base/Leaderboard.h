#pragma once
#include<conio.h>
#include<stdio.h>
#include <Windows.h>

typedef struct inf
{
	char name[20];
	int score;
}info;

int mainMenu();
void leaderboardMenu();
int leaderboard();
int saveLeaderboard();
int HightoLow();
int alphabet();
int clearLeaderboard();

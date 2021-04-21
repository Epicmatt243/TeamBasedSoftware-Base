#define _CRT_SECURE_NO_WARNINGS
#include"Leaderboard.h"
#include "Problems.h"
#include "Adventure.h"
#include "PointSys.h"

int score = 0;



void leaderboardMenu()
{
	system("cls");
	printf("****************************************************************************\n");
	printf("*                                                                          *\n");
	printf("*                    1.display from high to low                            *\n");
	printf("*                    2.display in alphabet order                           *\n");
	printf("*                    3.clear leaderboard                                   *\n");
	printf("*                    4.main menu                                           *\n");
	printf("*                                                                          *\n");
	printf("****************************************************************************\n");

	return 0;

}

int leaderboard()
{
	char select;
	leaderboardMenu();
	select = _getch();
	switch (select) //options
	{
	case '1':HightoLow(); break;
	case '2':alphabet(); break;
	case '3':clearLeaderboard(); break;
	case '4':main(); break;
	default:printf("\t Error!\n Please try again:");


	}
}

int saveLeaderboard()
{
	info tmp;
	FILE* fp;
	printf("Please enter your name:");
	scanf("%s", &tmp.name);
	tmp.score = score;
	fp = fopen("leaderboard.txt", "a");
	if (fp == NULL)
	{
		printf("cannot open the files\n");
		system("pause");
		return -1;//if the file occurs error then return -1 
	}
	fprintf(fp, "%s %d", tmp.name, tmp.score);
	fclose(fp);
	return 0;
}

int HightoLow()
{
	info tmp[10];
	info temp;
	int n = 0, j = 0, i = 0, k = 0;
	FILE* fp;
	char choice;

	if ((fp = fopen("leaderboard.txt", "r")) == NULL)	//determine if the leaderboard file exists.
	{
		printf("\t\t Failed to open the leaderboard, do you want to create a new one(Y/N)?");
		choice = _getch();
		while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			printf("°Ô°ÓInvalid Input°Ó°Ô Please try again:");
			choice = _getch();
		}
		if (choice == 'Y' || choice == 'y')
		{
			fp = fopen("leaderboard.txt", "w"); //reset leaderboard
			printf("\n\t\t Successes! \n");
			fclose(fp);
		}
		printf("\n Press any key to go back to the main menu");
		_getch();
		main();
	}

	else
		for (i = 0; i < n - 1; i++) //use bubble sort to arrange the rank from the highest to lowest
		{
			k = i;
			for (j = i + 1; j < n; j++)
				if (tmp[j].score > tmp[k].score) //comparing the size
					k = j;
			temp = tmp[k];
			tmp[k] = tmp[i];
			tmp[i] = temp;
		}
	i = 0;
	while (i <= 10 && fscanf(fp, "%s%d", tmp[i].name, &tmp[i].score) != EOF)
	{
		printf("%3d%15s%10d\n", i + 1, tmp[i].name, tmp[i].score);
		i++;
	}
	fclose(fp);
	return 0;
}


int alphabet()
{
	info tmp[10];
	info temp;
	int n = 0, j = 0, i = 0, k = 0;
	FILE* fp;
	char choice;

	if ((fp = fopen("leaderboard.txt", "r")) == NULL)	//determine if the leaderboard file exists.
	{
		printf("\t\t Failed to open the leaderboard, do you want to create a new one(Y/N)?");
		choice = _getch();
		while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			printf("°Ô°ÓInvalid Input°Ó°Ô Please try again:");
			choice = _getch();
		}
		if (choice == 'Y' || choice == 'y')
		{
			fp = fopen("leaderboard.txt", "w"); //reset leaderboard
			printf("\n\t\t Successes! \n");
			fclose(fp);
		}
		printf("\n Press any key to go back to the main menu");
		_getch();
		main();
	}

	else
		for (i = 0; i < n - 1; i++) //use bubble sort to arrange the rank in alphabet order
		{
			k = i;
			for (j = i + 1; j < n; j++)
				if (strcmp(tmp[j].name, tmp[k].name) > 0) //compare two strings
					k = j;
			temp = tmp[k];
			tmp[k] = tmp[i];
			tmp[i] = temp;
		}
	i = 0;
	while (i <= 10 && fscanf(fp, "%s%d", tmp[i].name, &tmp[i].score) != EOF)
	{
		printf("%3d%15s%10d\n", i + 1, tmp[i].name, tmp[i].score);
		i++;
	}
	fclose(fp);
	return 0;
}


int clearLeaderboard()
{
	FILE* fp;
	char A;
	printf("Do you want to clear the leaderboard(Y/N)?");
	A = _getch();
	while (A != 'Y' && A != 'y' && A != 'N' && A != 'n')
	{
		printf("\n°Ô°ÓInvalid Input°Ó°Ô Please enter Y/N:");
		A = _getch();
	}
	if (A == 'Y' || A == 'y')
	{
		if (A == 'y') printf(" y");
		else printf(" Y");
		fp = fopen("leaderboard.txt", "w"); //reset leaderboard
		fclose(fp);
		printf("\n Success!\n Press any key to go back to the main menu");
		_getch();
		main();
	}
	else leaderboardMenu();
}
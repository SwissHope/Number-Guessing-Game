#include <iostream>
#include <ctime>
#include <time.h>
#include <thread>
#include <stdlib.h>
#include <chrono>
#include <cstdlib>

using namespace std;

int rnd[3] = { 0 };
int difficultLevel = 1;
bool fail = false;

void numberGenerator()
{
}

void playGame()
{
	srand(time(NULL));

	for (int i = 0; i < 3; i++)
	{
		rnd[i] = rand() % (difficultLevel + 1);
	}
	int sum = rnd[0] + rnd[1] + rnd[2];
	int prod = rnd[0] * rnd[1] * rnd[2];
	int ans[3] = { 0,0,0 };
	cout << "You are attempting to enter a level " << difficultLevel << " room." << endl << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "The room is protected by a lock that uses three numbers, however there is a reminder display on each door." << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "The reminder display tells you that the sum of the numbers is " << sum << ".";
	this_thread::sleep_for(chrono::seconds(1));
	cout << endl << "The product of the numbers is " << prod << "." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Which three numbers make these two values?" << endl << "Enter them below, placing a space between each." << endl;
	cin >> ans[0] >> ans[1] >> ans[2];

	int ansSum = ans[0] + ans[1] + ans[2];
	int ansProd = ans[0] * ans[1] * ans[2];

	if (ansSum == sum && ansProd == prod)
	{
		system("cls");
		cout << "Congratulations, the door opened! " << endl << "There may be more challenges ahead." << endl;
		difficultLevel++;
		this_thread::sleep_for(chrono::milliseconds(3000));
		system("cls");
		this_thread::sleep_for(chrono::milliseconds(1500));
	}
	else
	{
		system("cls");
		cout << "Well that was wrong. So wrong that alarms have started blaring." << endl << "Today isn't your lucky day either, as now there are guards everywhere." << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		difficultLevel = 16;
		fail = true;
	}
}

void main()
{
	char again = 'X';
	while (difficultLevel <= 15)
	{
		numberGenerator();
		playGame();
	}

	if (fail == false)
	{
		cout << "Congratulations, you have done well. Your next challenge awaits." << endl << endl;
	}

	while (again != 'Y' && again != 'y' && again != 'N' && again != 'n')
	{
		cout << "Would you like to play again? (Y/N) ";
		cin >> again;
	}

	if (again == 'Y' || again == 'y')
	{
		system("cls");
		difficultLevel = 1;
		main();
	}
}
#include <iostream>
#include <time.h>
using namespace std;

int bulls;
int cows;
int number[4];
int a_number[4];

void GenerateNumber()
{
	srand(time(0));
	int r_number;
	number[0] = rand() % 9 + 1;
	for (int i = 1; i < 4; i++)
	{
		bool unique;
		do
		{
			unique = true;
			r_number = rand() % 10;
			for (int j = 0; j < i; j++)
				if (number[j] == r_number)
				{
					unique = false;
					break;
				}
		} while (!unique);
		number[i] = r_number;
	}
}

void Logic()
{
	for (int i = 0; i < 4; i++)
	{
		if (a_number[i] == number[i])
			bulls++;
		else
		{
			for (int j = 0; j < 4; j++)
				if (a_number[i] == number[j])
				{
					cows++;
					break;
				}
		}
	}

}

void Play()
{
	int n_a_a_number;
	GenerateNumber();
	do
	{
		bulls = 0;
		cows = 0;
		cout << "==============================\n";
		cout << "\nAsk for a number: ";
		cin >> n_a_a_number;
		for (int i = 3; i >= 0; i--)
		{
			a_number[i] = n_a_a_number % 10;
			n_a_a_number /= 10;
		}
		Logic();
		cout << endl << "Bulls: " << bulls << endl << "Cows: " << cows << endl << endl;
	} while (bulls != 4);
}

int main()
{
	Play();
}
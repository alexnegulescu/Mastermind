#ifndef CODE_H
#define CODE_H

#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Declaration

class Code
{
private:
	int size, range;
	vector<int> secretCode, secretCopy, guessCopy;

public:
	// Constructor
	Code(int n, int m)
	{
		size = n;
		range = m;
	}

	// Public Member Functions
	vector<int> create();
	int checkCorrect(vector<int> guess);
	int checkIncorrect(vector<int> guess);

};

// Implementation

vector<int> Code::create()
{
	srand(time(NULL));
	int randomDigit;
	for (int i = 0; i < size; i++)
	{
		randomDigit = rand() % range;
		secretCode.push_back(randomDigit);
	}
	return secretCode;
}

int Code::checkCorrect(vector<int> guess)
{
	secretCopy = secretCode;
	guessCopy = guess;
	int correct = 0;
	for (int x = 0; x < guessCopy.size(); x++)
	{
		if (guessCopy[x] == secretCopy[x])
		{
			correct++;
			guessCopy[x] = range + 1;
			secretCopy[x] = range + 2;
		}
	}
	return correct;
}


int Code::checkIncorrect(vector<int> guess)
{
	int correct = 0;

	for (int x = 0; x < guessCopy.size(); x++)
	{
		for (int y = 0; y < secretCopy.size(); y++)
		{
			if (guessCopy[x] == secretCopy[y] && x == y)
			{
				break;
			}
			else if (guessCopy[x] == secretCopy[y] && x != y)
			{
				correct++;
				guessCopy[x] = range + 1;
				secretCopy[y] = range + 2;
				break;
			}
		}
	}

	return correct;
}

#endif

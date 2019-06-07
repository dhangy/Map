// File/Project Prolog
//Name : Dannie Brockbank
// CS 2420 Section 003
// Project: External Iterator
// Date: 10/7/18
//
// I declare that the following code was written by me or provided 
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive
// a zero on this project if I am found in violation of this policy.
// 
// I also state that the Standard Template Library is NOT used in this project
// ---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "HashMap.h"

using namespace std;

void CleanString(string& line)
{
	// make string all lowercase
	transform(line.begin(), line.end(), line.begin(), ::tolower);

	// replace punctuation with white-space
	for (char& c : line)
	{
		if (c < 'a' || c > 'z')
			c = ' ';
	}
}

void FindLargestWordCount(HashMap& hm, string &key, int& maxValue)
{
	auto start = hm.begin();
	auto end = hm.end();
	key = *start;
	hm.GetKeyValue(*start, maxValue);
	++start;
	while (start != end)
	{
		int value = 0;
		hm.GetKeyValue(*start, value);
		if (value > maxValue)
		{
			key = *start;
			maxValue = value;
		}
		++start;
	}
}

int main()
{
	// NOTE: no path information. 
	// Check your dev environment to see where the "default" location is and make sure the text file is there
	ifstream myFile("AliceInWonderland.txt");
	if (myFile.is_open())
	{
		string line;
		stringstream ss;

		HashMap hm(500);

		while (getline(myFile, line))
		{
			// pull each individual word from the line
			CleanString(line);

			stringstream ss(line);
			string word;
			while (ss >> word)
			{
				if (word.length() > 1)
				{
					int currentCount = 0;
					if (currentCount == -1) {
						cout << "wtf";
					}
					hm.GetKeyValue(word, currentCount);		// get the current count for this word
					hm.SetKeyValue(word, currentCount + 1);	// inc the count for this word
				}
			}
		}

		cout << "Most common words are:" << endl;
		for (int i = 0; i < 25; i++)
		{
			string mostCommon;
			int value = -1;

			FindLargestWordCount(hm, mostCommon, value);
			cout << mostCommon << "\t\t" << value << endl;

			hm.SetKeyValue(mostCommon, -1);	// set the count negative so it won't appear on the next iteration
		}
		myFile.close();
	}

	cout << endl << "press the [Enter] key to exit" << endl;
	cin.get();
	return 0;
}
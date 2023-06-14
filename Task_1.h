// Given a text file. Calculate the length of the shortest word in this file 
// (a word is a group of consecutive characters other than spaces and punctuation marks).
//

#pragma once
#include <fstream>
using namespace std;

int Task1()
{
	ifstream in;

	in.open("Task_1_File.txt");

	if (!in.is_open())
	{
		cout << "\n\n\tError\n\n\n";
		return 1;
	}

	char ch;
	char ch2 = 'a';
	int count = 0;
	int min = INT_MAX;

	while (in.get(ch))
	{
		if ((ch == ' ' || ch == '.' || ch == ',') && !(ch2 == ' ' || ch2 == '.' || ch2 == ','))
		{
			if (min > count)
			{
				min = count;
			}
			count = 0;
		}
		else if ((!(ch == ' ' || ch == '.' || ch == ',') && !(ch2 == ' ' || ch2 == '.' || ch2 == ',')) || (!(ch == ' ' || ch == '.' || ch == ',') && (ch2 == ' ' || ch2 == '.' || ch2 == ',')))
		{
			count++;
		}
		ch2 = ch;
	}
	cout << "\n\n\tThe length of the shortest word is " << min;
}
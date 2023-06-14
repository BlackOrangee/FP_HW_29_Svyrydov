// Create a text file that contains positive, negative, zero numbers and arbitrary characters. 
// Determine the number of positive, negative, zero numbers and words in each line of the file. 
// Write the received values with appropriate comments in another text file.
//

#pragma once
#include <fstream>
#include <string>
using namespace std;

int Task2()
{
	// Counters
	int neg = 0;
	int pos = 0;
	int zero = 0;
	int space = 0;	
	
	// Reading file
	ifstream in;

	in.open("Task_2_File.txt");

	if (!in.is_open())
	{
		cout << "\n\n\tRead error\n\n\n";
		return 1;
	}

	string str;

	while (getline(in, str))
	{
		int len = 0;
		len = str.length();

		space++;
		for (int i = 0; i < len; i++)
		{
			if ((str[i] >= 49 && str[i] <= 57 && str[i - 1] != '-') && !(str[i - 1] >= 48 && str[i - 1] <= 57))
			{
				pos++;
			}
			else if ((str[i] >= 49 && str[i] <= 57 && str[i - 1] == '-') && !(str[i - 1] >= 48 && str[i - 1] <= 57))
			{
				neg++;
			}
			else if (str[i] == 48 && str[i - 1] == ' ')
			{
				zero++;
			}
			else if (str[i] == ' ')
			{
				space++;
			}
		}
	}

	int words = space - (pos + neg + zero);

	cout << "\n\n\tReading complite without errors";


	// Writing
	ofstream out;

	out.open("Task_2_File.LOG");

	if (!out.is_open())
	{
		cout << "\n\n\tSave error\n\n\n";
		return 1;
	}

	out << "Number of positive characters: " << pos;
	out << "\nNumber of negative characters: " << neg;
	out << "\nNumber of zeros: " << zero;
	out << "\nNumber of words: " << words;
	
	cout << "\n\n\tTask complete";
	cout << "\n\n\tLog file is created!\n\n\n";
	
	return 0;
}
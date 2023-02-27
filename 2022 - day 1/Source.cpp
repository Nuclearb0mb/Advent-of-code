#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()		// part 2
{

	std::cout << "Input calories carried by elves: \n";

	std::string inputLine;
	std::vector<int> elfCarriedCalories;

	// reading input per line
	int carriedCalories = 0;			//sum of calories until empty line is found

	while (std::getline( std::cin, inputLine))
	{
		if (inputLine.empty())
		{
			elfCarriedCalories.push_back(carriedCalories);

			carriedCalories = 0;
		}
		else
		{
			carriedCalories += stoi(inputLine);
		}
	}

	if (!(carriedCalories == 0))	//if file does not end with empty line, insert last elf calorie count
	{
		elfCarriedCalories.push_back(carriedCalories);
		carriedCalories = 0;
	}

	//sort ascending
	std::sort(elfCarriedCalories.begin(), elfCarriedCalories.end());
	
	int elvesToSum = 3;			//how many elves with the most calories carried to sum together
	int sumOfNElvesWithMostCalories = 0;	// sum of N of elves with the most carried calories

	for (int i = 0; i < elvesToSum; i++)
	{
		sumOfNElvesWithMostCalories += elfCarriedCalories.at(elfCarriedCalories.size() - (1 + i));
		std::cout << 1 + i << ". " << " Most carried calories: " << elfCarriedCalories.at(elfCarriedCalories.size() - (1 + i)) << "\n";
	}

	std::cout << "Sum of most carried calories: " << sumOfNElvesWithMostCalories << "\n";	
}
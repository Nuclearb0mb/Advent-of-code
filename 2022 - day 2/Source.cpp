#include <iostream>
#include <vector>
#include <string>

// -- Part 2 --
enum Result
{
	win,
	loss,
	draw,
	error
};

Result getResult(const char opponent, const char you)		// A = rock; B = paper; C = scissors
{
	if (opponent == you)			// draw
	{
		return draw;
	}
	else if (opponent == 'A') 
	{
		if (you == 'B')
		{
			return win;
		}
		else
		{
			return loss;
		}
	}
	else if (opponent == 'B') 
	{
		if (you == 'C')
		{
			return win;
		}
		else
		{
			return loss;
		}
	}
	else if (opponent == 'C')
	{
		if (you == 'A')
		{
			return win;
		}
		else
		{
			return loss;
		}
	}

	return error;
	
}

void setSymbolForResult(const char opponent, const char result, char& you)		//sets your acoording to wanted result; A = rock; B = paper; C = scissors RESULT: X = loss, Y = draw, Z = win
{
	if (result == draw)	
	{
		you = opponent;
	}
	else if (opponent == 'A')
	{
		if (result == win)
		{
			you = 'B';
		}
		else
		{
			you = 'C';
		}
	}
	else if (opponent == 'B')
	{
		if (result == win)
		{
			you = 'C';
		}
		else
		{
			you = 'A';
		}
	}
	else if (opponent == 'C')
	{
		if (result == win)
		{
			you = 'A';
		}
		else
		{
			you = 'B';
		}
	}
}

void addSymbolScore(int& scoreSum, const char playedSymbol)
{
	switch (playedSymbol)				// your symbol score distribution
	{
	case 'A':
		scoreSum += 1;
		break;
	case 'B':
		scoreSum += 2;
		break;
	case 'C':
		scoreSum += 3;
		break;
	default:
		break;
	}
}

int main()
{
	std::cout << "Input Rock, Paper, Scissors strategy: \n";

	std::string inputLine;
	int opponentScoreSum = 0;
	int yourScoreSum = 0;

	while (std::getline(std::cin, inputLine))
	{
		Result wantedResult = Result::error;
		char opponentSymbol = '0';

		for (char playedSymbol : inputLine)
		{
			

			switch(playedSymbol) {
			case 'A':
				opponentSymbol = 'A';		// rock
				break;
			case 'B':
				opponentSymbol = 'B';		// paper
				break;
			case 'C':
				opponentSymbol = 'C';		// scissors
				break;
			case 'X':			
				wantedResult = Result::loss;			//loss
				break;
			case 'Y':
				wantedResult = Result::draw;			//draw
				break;
			case 'Z':
				wantedResult = Result::win;				//win
				break;
			default:
				break;
			}
			
		}

		char yourSymbol = '0';

		setSymbolForResult(opponentSymbol, wantedResult, yourSymbol);

		addSymbolScore(yourScoreSum, yourSymbol);
		addSymbolScore(opponentScoreSum, opponentSymbol);


		switch (getResult(opponentSymbol, yourSymbol))		// distribute match score
		{ 
			case Result::win:
				yourScoreSum += 6;
				break;
			case Result::draw:
				yourScoreSum += 3;
				opponentScoreSum += 3;
				break;
			case Result::loss:
				opponentScoreSum += 6;
				break;
			case Result::error:
				std::cout << "getResult Error\n";
				break;
			default:
				std::cout << "getResult unknown result\n";
		}

	}

	std::cout << "Final score:\nYou: " << yourScoreSum << "\n";
	std::cout << "Opponent: " << opponentScoreSum << "\n";

}

/*	---- First part -----
int main()
{
	std::cout << "Input Rock, Paper, Scissors strategy: \n";

	std::string inputLine;
	int opponentScoreSum = 0;
	int yourScoreSum = 0;

	while (std::getline(std::cin, inputLine))
	{
		char yourSymbol = '0';
		char opponentSymbol = '0';

		for (char playedSymbol : inputLine)
		{


			switch(playedSymbol) {
			case 'A':
				opponentSymbol = 'A';		// rock
				opponentScoreSum += 1;
				break;
			case 'B':
				opponentSymbol = 'B';		// paper
				opponentScoreSum += 2;
				break;
			case 'C':
				opponentSymbol = 'C';		// scissors
				opponentScoreSum += 3;
				break;
			case 'X':
				yourSymbol = 'X';			//your rock
				yourScoreSum += 1;
				break;
			case 'Y':
				yourSymbol = 'Y';			//your paper
				yourScoreSum += 2;
				break;
			case 'Z':
				yourSymbol = 'Z';			//your scissors
				yourScoreSum += 3;
				break;
			default:
				break;
			}

		}

		yourSymbol -= 23;		// conversion to same symbols

		switch (getResult(opponentSymbol, yourSymbol))		// distribute match score
		{
			case win:
				yourScoreSum += 6;
				break;
			case draw:
				yourScoreSum += 3;
				opponentScoreSum += 3;
				break;
			case loss:
				opponentScoreSum += 6;
				break;
			case error:
				std::cout << "getResult Error\n";
				break;
			default:
				std::cout << "getResult unknown result\n";
		}

	}

	std::cout << "Final score:\nYou: " << yourScoreSum << "\n";
	std::cout << "Opponent: " << opponentScoreSum << "\n";

}


*/